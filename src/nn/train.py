import torch
from torch.utils.data import DataLoader
import torch.optim as optim
from nn.glove_dataset import GloveDataset
from nn.early_stopping import EarlyStopping
from nn.network import Network
import os
from tqdm import tqdm

import mlflow



def train(directory='./dataset', labels=["rest", "bottle", "pen", "phone"]):
    with mlflow.start_run():

        device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

        # Create the dataset
        train_dir = os.path.join(directory, "train")
        val_dir = os.path.join(directory, "validation")
        train_dataset = GloveDataset(train_dir, labels)
        validation_dataset = GloveDataset(val_dir, labels)

        # Create the DataLoader
        train_dataloader = DataLoader(train_dataset, shuffle=True, batch_size=5)
        validation_dataloader = DataLoader(validation_dataset, shuffle=True, batch_size=5)
        net = Network( output_classes=len(labels) )
        # print number of parameters
        num_params = sum(p.numel() for p in net.parameters() if p.requires_grad)
        print(f"Number of trainable parameters: {num_params}")


        loss_function = torch.nn.CrossEntropyLoss()  # Define your loss function
        optimizer = torch.optim.Adam(net.parameters(), lr=1e-3)  # Define your optimizer

        early_stopping = EarlyStopping(patience=50, verbose=True, delta=0.0007)  # Initialize early stopping

        net.to(device)  # Move the network to the device (GPU or CPU)
        epoch = 0
        while True:

            net.eval()
            with torch.no_grad():

                confusion_matrix = torch.zeros(len(labels), len(labels))  # Initialize confusion matrix

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
                    # Update confusion matrix
                    for t, p in zip(labels_id.view(-1), predicted.view(-1)):
                        confusion_matrix[t.long(), p.long()] += 1
                    progress_bar.set_description(f'Epoch {epoch+1} - Val Loss: {val_loss.item():.4f}, Accuracy: {correct/total:.4f}')
                    # print("Confusion Matrix:\n", confusion_matrix)
            

            if early_stopping(net ,total_loss):
                print("Early stopping triggered. Training stopped.")
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

            # Log metrics to MLflow
            mlflow.log_metric("train_loss", train_loss.item(), step=epoch)
            mlflow.log_metric("val_loss", total_loss / len(validation_dataloader), step=epoch)
            mlflow.log_metric("accuracy", correct / total, step=epoch)


        

def main():
    labels = ["rest", "bottle", "pen", "phone"] #, "mouse", "glasses"]
    directory = '/home/feld/ros2_ws/datasets/dataset_split'
    train(directory, labels)




if __name__ == "__main__":
    main()