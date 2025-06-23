import torch
from torch.utils.data import DataLoader
from glove_dataset import GloveDataset
from network import Network
import os
from tqdm import tqdm


def main():
    # initiialize model from checkpoint if exists
    checkpoint_path = "checkpoint.pt"
    if os.path.exists(checkpoint_path):
        print("Loading model from checkpoint...")
        net = Network()
        net.load_state_dict(torch.load(checkpoint_path))
    else:
        print("No checkpoint found, initializing new model...")
        exit(1)
    

    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    directory = "dataset"
    labels = ["bottle", "pen", "phone"]
    test_dir = os.path.join(directory, "test")
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
            total += labels_id.size(0)
            correct += (predicted == labels_id).sum().item()
            progress_bar.set_description(f"Loss: {total_loss / (len(test_dataloader)):.4f}, Accuracy: {correct / total:.4f}")


if __name__ == "__main__":

    main()