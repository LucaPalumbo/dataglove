import torch
from torch.utils.data import DataLoader
import torch.optim as optim
from glove_dataset import GloveDataset
from network import Network
import os



def main():
    directory = "dataset"
    labels = ["bottle", "pen", "phone"]

    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

    # Create the dataset
    train_dir = os.path.join(directory, "train")
    val_dir = os.path.join(directory, "validation")
    train_dataset = GloveDataset(train_dir, labels)
    validation_dataset = GloveDataset(val_dir, labels)

    # Create the DataLoader
    train_dataloader = DataLoader(train_dataset, batch_size=4, shuffle=True)
    validation_dataloader = DataLoader(validation_dataset, batch_size=4, shuffle=True)
    net = Network()
    optimizer = optim.Adam( net.parameters(), lr = 1e-3)

    loss_function = torch.nn.CrossEntropyLoss()  # Define your loss function
    optimizer = torch.optim.Adam(net.parameters(), lr=0.001)  # Define your optimizer


    net.to(device)  # Move the network to the device (GPU or CPU)
    epoch = 100
    for e in range(epoch):
        print(f"Epoch {e+1}/{epoch}")


        net.eval()
        print("Validation...")
        with torch.no_grad():
            total_loss = 0
            correct = 0
            total = 0
            for batch, labels_id in validation_dataloader:
                batch = batch.to(device)
                labels_id = labels_id.to(device)
                Network_output = net(batch)
                val_loss = loss_function(Network_output, labels_id)
                total_loss += val_loss.item()
                _, predicted = torch.max(Network_output, 1)
                total += labels_id.size(0)
                correct += (predicted == labels_id).sum().item()
            avg_val_loss = total_loss / len(validation_dataloader)
            accuracy = correct / total
            print(f"Validation loss: {avg_val_loss:.4f}, Accuracy: {accuracy:.4f}")
        print(f"Epoch {e+1} completed.\n")


        print("Training...")
        # Iterate through the DataLoader
        net.train()  # Set the network to training mode
        for batch, labels_id in train_dataloader:
            optimizer.zero_grad()
            batch = batch.to(device)
            labels_id = labels_id.to(device)
            Network_output = net(batch)  # Forward pass through the network
            train_loss = loss_function(Network_output, labels_id)  # Compute the loss
            train_loss.backward()
            optimizer.step()
            print(f"Batch loss: {train_loss.item()}")

        




if __name__ == "__main__":
    main()