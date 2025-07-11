import torch
import os
from nn.glove_dataset import GloveDataset
from nn.early_stopping import EarlyStopping
from nn.network import Network
import pandas as pd
from torch.utils.data import DataLoader
from tqdm import tqdm
import argparse
import matplotlib.pyplot as plt


sensors_index = {
    "fing": (0,10),
    "press": (14, 19),
    "abd": (19, 23),
    "quat": (23, 31)
}


def train( directory, start=0, end=33):
    labels = ["rest", "bottle", "pen", "phone"]

    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

    # Create the dataset
    train_dir = os.path.join(directory, "train")
    val_dir = os.path.join(directory, "validation")
    train_dataset = GloveDataset(train_dir, labels)
    validation_dataset = GloveDataset(val_dir, labels)

    # Create the DataLoader
    train_dataloader = DataLoader(train_dataset, shuffle=True, batch_size=5)
    validation_dataloader = DataLoader(validation_dataset, shuffle=True, batch_size=5)
    net = Network(num_features=end-start)
    # print number of parameters
    num_params = sum(p.numel() for p in net.parameters() if p.requires_grad)
    print(f"Number of trainable parameters: {num_params}")

    loss_function = torch.nn.CrossEntropyLoss()  # Define your loss function
    optimizer = torch.optim.Adam(net.parameters(), lr=1e-3)  

    early_stopping = EarlyStopping(patience=20, verbose=True, delta=0.0007)  # Initialize early stopping


    net.to(device)  # Move the network to the device (GPU or CPU)
    epoch = 0
    while True:
        net.eval()
        with torch.no_grad():
            total_loss = 0
            correct = 0
            total = 0
            progress_bar = tqdm(validation_dataloader)
            for batch, labels_id in progress_bar:

                # remove features that are not in the range [start, end]
                batch = batch[:,:,:,start:end]

                batch = batch.to(device)
                labels_id = labels_id.to(device)
                Network_output = net(batch)
                val_loss = loss_function(Network_output, labels_id)
                total_loss += val_loss.item()
                _, predicted = torch.max(Network_output, 1)
                total += labels_id.size(0)
                correct += (predicted == labels_id).sum().item()
                accuracy = correct / total
                progress_bar.set_description(f'Epoch {epoch+1} - Val Loss: {total_loss:.4f}, Accuracy: {accuracy:.4f}')
        

        if early_stopping(net, total_loss, accuracy):
            print("Early stopping triggered. Training stopped.")
            early_stopping.store_results(num_feature=end-start)
            break



        # Iterate through the DataLoader
        net.train()  # Set the network to training mode
        progress_bar = tqdm(train_dataloader, unit="batch")
        for batch, labels_id in progress_bar:
            batch = batch[:,:,:,start:end]

            optimizer.zero_grad()
            batch     = batch.to(device)
            labels_id = labels_id.to(device)
            Network_output = net(batch)  # Forward pass through the network
            
            train_loss = loss_function(Network_output, labels_id)  # Compute the loss
            train_loss.backward()
            progress_bar.set_description(f'Epoch {epoch+1} - Train Loss: {train_loss.item():.4f}')
            optimizer.step()
        epoch += 1




def plot_feature_selection_curve(losses, accuracies, std_losses, std_accuracies):
    names = ["Fingers", "Pressure", "Abduction", "Quaternion"]
    # create a bar plot with error bars
    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1)
    plt.bar(range(len(losses)), losses, yerr=std_losses, capsize=5, color='lightblue', edgecolor='black')
    plt.title('Feature Bar Plot - Loss')
    plt.xlabel('Sensors Set')
    plt.ylabel('Loss')
    plt.xticks(range(len(losses)), names)
    plt.grid(axis='y')
    plt.subplot(1, 2, 2)
    plt.bar(range(len(accuracies)), accuracies, yerr=std_accuracies, capsize=5, color='lightgreen', edgecolor='black')
    plt.title('Feature Bar Plot - Accuracy')
    plt.xlabel('Sensors Set')
    plt.ylabel('Accuracy')
    plt.xticks(range(len(losses)), names)
    plt.grid(axis='y')
    plt.tight_layout()
    plt.savefig("feature_selection_curve.png")
    plt.show()

def plot():
    df = pd.read_csv("results.csv")

    losses = []
    accuracies = []
    std_losses = []
    std_accuracies = []


    # iterate df in chunks of 5 rows
    for i in range(0, len(df), 5):
        chunk = df.iloc[i:i+5]
        # compute average of the 'loss' column and the accuracy column
        avg_loss = chunk['loss'].mean()
        avg_accuracy = chunk['accuracy'].mean()
        losses.append(avg_loss)
        accuracies.append(avg_accuracy)

        # compute std of the 'loss' column and the accuracy column
        std_loss = chunk['loss'].std()
        std_accuracy = chunk['accuracy'].std()
        std_losses.append(std_loss)
        std_accuracies.append(std_accuracy)
    
    # Plot the feature selection curve
    plot_feature_selection_curve(losses, accuracies, std_losses, std_accuracies)



def main():
    parser = argparse.ArgumentParser(description="sensor_group.py")
    parser.add_argument("--plot", action="store_true", help="plot the feature selection curve")

    args = parser.parse_args()
    if args.plot:
        print("Plotting feature selection curve...")
        plot()
        return


    for sensor_group, (start, end) in sensors_index.items():
        
        for i in range(1, 6):
            directory = f"/home/feld/ros2_ws/datasets/dataset_merged/folds/fold_{i}" 

            print(f"Training with {sensor_group} features")
            train(directory, start=start, end=end)


if __name__ == "__main__":
    main()