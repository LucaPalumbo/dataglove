import torch
from torch.utils.data import DataLoader
from nn.glove_dataset import GloveDataset
from nn.network import Network
import os
import pandas as pd
from tqdm import tqdm
import argparse
import seaborn as sns
import matplotlib.pyplot as plt


labels = ["rest", "bottle", "pen", "phone"]
# labels = ["rest", "bottle", "pen", "phone", "mouse", "glasses"]

confusion_matrix = torch.zeros(len(labels), len(labels))  # Assuming 4 classes


def test(directory = 'dataset', checkpoint_path="checkpoint.pt", dir = "test"):



    # initiialize model from checkpoint if exists
    if os.path.exists(checkpoint_path):
        print("Loading model from checkpoint...")
        net = Network(output_classes=4)
        # net.classifier.add_task(output_classes=2) 
        net.load_state_dict(torch.load(checkpoint_path))
    else:
        print("No checkpoint found, initializing new model...")
        exit(1)
    

    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    test_dir = os.path.join(directory, dir)
    test_dataset = GloveDataset(test_dir, labels)
    test_dataloader = DataLoader(test_dataset, shuffle=False, batch_size=1)

    net.to(device) 
    net.eval()  # Set the model to evaluation mode
    total_loss = 0
    correct = 0
    total = 0
    loss_function = torch.nn.CrossEntropyLoss()  # Define your loss function
    progress_bar = tqdm(test_dataloader)
    with torch.no_grad():
        for batch, labels_id in progress_bar:
            batch = batch.to(device)
            labels_id = labels_id.to(device)
            Network_output = net(batch)
            # print(Network_output.shape, Network_output)
            val_loss = loss_function(Network_output, labels_id)
            total_loss += val_loss.item()
            _, predicted = torch.max(Network_output, 1)
            # Update confusion matrix
            for t, p in zip(labels_id.view(-1), predicted.view(-1)):
                confusion_matrix[t.long(), p.long()] += 1
            total += labels_id.size(0)
            correct += (predicted == labels_id).sum().item()
            progress_bar.set_description(f"Loss: {total_loss / (len(test_dataloader)):.4f}, Accuracy: {correct / total:.4f}")

    print("Confusion Matrix:\n" , confusion_matrix)

def plot_confusion_matrix():

    plt.figure(figsize=(10, 8))
    sns.heatmap(confusion_matrix.numpy(), annot=True, fmt='g', cmap='Blues',
                xticklabels=labels, yticklabels=labels)
    plt.xlabel('Predicted')
    plt.ylabel('True')
    plt.title('Confusion Matrix')
    plt.show()


# def single_test():
#     # Test a single sample
#     directory = "dataset"
#     labels = ["bottle", "pen", "phone"]
#     file_name = '1.csv'  # Example file name, change as needed
#     test_dir = os.path.join(directory, "test")
#     df = pd.read_csv(os.path.join(test_dir, file_name), header=None)
    
#     used_columns = list(range(2, 25))       # 23 columns
#     used_columns += list(range(28, 32))     # 4 columns
#     used_columns += list(range(35, 39))     # 4 columns
#     df = df.iloc[:, used_columns]


#     net = Network()
#     net.load_state_dict(torch.load("checkpoint.pt"))
#     net.eval()
#     with torch.no_grad():
#         # Normalize first 23 columns to [-1, 1]
#         df.iloc[:, :23] = (df.iloc[:, :23] / 1000.0) * 2 - 1

#         # Pad if needed to 100 rows
#         if df.shape[0] < 100:
#             padding = pd.DataFrame(0, index=range(100 - df.shape[0]), columns=df.columns)
#             df = pd.concat([padding, df], ignore_index=True)
#         elif df.shape[0] > 100:
#             df = df.iloc[-100:, :]

#         tensor = torch.tensor(df.values, dtype=torch.float32).unsqueeze(0)  # Add batch dimension
#         tensor = tensor.to(torch.device('cuda' if torch.cuda.is_available() else 'cpu'))
#         output = net(tensor)
#         _, predicted = torch.max(output, 1)
#         print(f"Predicted label for {file_name}: {labels[predicted.item()]}")
        


def main():
    parser = argparse.ArgumentParser(description="Test the model on the dataset.")
    parser.add_argument('--checkpoint', type=str, default="checkpoint.pt", help='Path to the model checkpoint')
    parser.add_argument('--validation', action='store_true', help='Run validation instead of test')
    parser.add_argument('--plot', action='store_true', help='Plot confusion matrix')
    args = parser.parse_args()


    directory = '/home/feld/ros2_ws/datasets/dataset_merged2'  # Change this to your dataset directory
    test(directory, args.checkpoint, "validation" if args.validation else "test")

    if args.plot:
        print("Plotting confusion matrix...")
        plot_confusion_matrix()


if __name__ == "__main__":

    main()