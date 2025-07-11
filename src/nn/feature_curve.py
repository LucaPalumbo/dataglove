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


def train( directory , num_features = None ):
    labels = ["rest", "bottle", "pen", "phone"]

    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

    # Create the dataset
    train_dir = os.path.join(directory, "train")
    val_dir = os.path.join(directory, "validation")
    train_dataset = GloveDataset(train_dir, labels, num_features=num_features)
    validation_dataset = GloveDataset(val_dir, labels, num_features=num_features)

    # Create the DataLoader
    train_dataloader = DataLoader(train_dataset, shuffle=True, batch_size=5)
    validation_dataloader = DataLoader(validation_dataset, shuffle=True, batch_size=5)
    net = Network(num_features=num_features)
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
            early_stopping.store_results(num_features)
            break



        # Iterate through the DataLoader
        net.train()  # Set the network to training mode
        progress_bar = tqdm(train_dataloader, unit="batch")
        for batch, labels_id in progress_bar:
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
    plt.figure(figsize=(10, 5))

    # Plotting the losses
    plt.subplot(1, 2, 1)
    plt.plot(losses, marker='o', label='Loss')
    plt.fill_between(range(len(losses)), 
                     [l - s for l, s in zip(losses, std_losses)], 
                     [l + s for l, s in zip(losses, std_losses)], 
                     alpha=0.2)
    plt.title('Feature Selection Curve - Loss')
    plt.xlabel('Feature Set Size')
    plt.ylabel('Loss')
    plt.legend()

    # Plotting the accuracies
    plt.subplot(1, 2, 2)
    plt.plot(accuracies, marker='o', label='Accuracy', color='orange')
    plt.fill_between(range(len(accuracies)), 
                     [a - s for a, s in zip(accuracies, std_accuracies)], 
                     [a + s for a, s in zip(accuracies, std_accuracies)], 
                     alpha=0.2)
    plt.title('Feature Selection Curve - Accuracy')
    plt.xlabel('Feature Set Size')
    plt.ylabel('Accuracy')
    plt.legend()

    plt.tight_layout()
    plt.show()


def plot():
    df = pd.read_csv("feature_curve_results.csv")

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
    parser = argparse.ArgumentParser(description="feature_selection_curve.py")
    parser.add_argument("--plot", action="store_true", help="plot the feature selection curve")

    args = parser.parse_args()
    if args.plot:
        print("Plotting feature selection curve...")
        plot()
        return


    for num_features in range(6, 32):
        for i in range(1, 6):
            directory = f"/home/feld/ros2_ws/datasets/dataset_merged/folds/fold_{i}" 

            print(f"Training with {num_features} features")
            train(directory, num_features=num_features)


if __name__ == "__main__":
    main()