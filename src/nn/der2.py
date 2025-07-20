import torch
from tqdm import tqdm
from torch.utils.data import DataLoader
from torch.nn import functional as F
from nn.early_stopping import EarlyStopping
from nn.glove_dataset import GloveDataset
from nn.network import Network
import copy





def lwf_train(old_model, student, dataset_train, dataset_train_replay, dataset_val, dist_lambda = 1,  warm_up=False): 
    old_classes = 4

    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

    student.to(device)
    loss_function = torch.nn.CrossEntropyLoss()

    # optimizer_params = {
    #     "lr": 1e-4,  # Learning rate
    #     "momentum": 0.4,  # Momentum
    # }

    optimizer = torch.optim.Adam(student.parameters(), lr=1e-4) # lr 10 time smaller than in train.py
    # optimizer = torch.optim.SGD(student.parameters(), **optimizer_params)  # Using SGD with momentum and weight decay
    dataloader_train = DataLoader(dataset_train, shuffle=True, batch_size=5)
    dataloader_train_replay = DataLoader(dataset_train_replay, shuffle=True, batch_size=1)

    dataloader_val = DataLoader(dataset_val, shuffle=True, batch_size=5)
    early_stopping = EarlyStopping(patience=50, delta=0.0006, verbose=True)
    
    iter_replay = iter(dataloader_train_replay)

    epoch = 0
    while True:
        student.train()
        total_loss = 0
        progress_bar = tqdm(dataloader_train, desc=f'Epoch {epoch+1}')
        for batch_new, labels_id_new in progress_bar:
            try:
                batch_replay, labels_replay = next(iter_replay)
            except StopIteration:
                iter_replay = iter(dataloader_train_replay)
                batch_replay, labels_replay = next(iter_replay)

            optimizer.zero_grad()
            batch_new = batch_new.to(device)
            labels_id_new = labels_id_new.to(device) + old_classes
            batch_replay = batch_replay.to(device)
            labels_replay = labels_replay.to(device)


            student_output = student(batch_new)

            loss = loss_function(student_output, labels_id_new)
            
            with torch.no_grad():
                teacher_output = old_model(batch_replay)

            student_output_replay = student(batch_replay)
            dist_loss = F.mse_loss(student_output_replay[:,:old_classes], teacher_output) * dist_lambda

            loss += dist_loss

            loss.backward()
            optimizer.step()

            total_loss += loss.item()
            progress_bar.set_description(f'Epoch {epoch+1} - Loss: {total_loss:.4f}')



        student.eval()
        progress_bar = tqdm(dataloader_val, desc=f'Validation Epoch {epoch+1}')
        with torch.no_grad():
            total_val_loss = 0
            correct_val = 0
            total_val = 0
            for batch, labels_id in progress_bar:
                batch = batch.to(device)
                labels_id = labels_id.to(device) # + old_classes  ##

                student_output = student(batch)

                val_loss = loss_function(student_output, labels_id) 
                total_val_loss += val_loss.item()

                _, predicted = torch.max(student_output, 1)
                total_val += labels_id.size(0)
                correct_val += (predicted == labels_id).sum().item()

                accuracy = correct_val / total_val
                progress_bar.set_description(f'Validation Loss: {total_val_loss:.4f}, Accuracy: {accuracy:.4f}')


        if early_stopping(student, total_val_loss, accuracy, 'distillated_checkpoint.pt'):
            print("Early stopping triggered. Training stopped.")
            break

        epoch += 1

        if epoch >= 100 and warm_up:
            break




def main():
    old_model = Network(output_classes=4)
    old_model.load_state_dict(torch.load("checkpoint.pt"))

    new_model = copy.deepcopy(old_model)
    new_model.classifier.add_task(output_classes=2)

    dataset_train = GloveDataset("/home/feld/ros2_ws/datasets/dataset_merged3/train", ["mouse", "glasses"])
    dataset_train_replay = GloveDataset("/home/feld/ros2_ws/datasets/dataset_merged3/train", ["rest", "bottle", "pen", "phone"])
    dataset_val = GloveDataset("/home/feld/ros2_ws/datasets/dataset_merged3/validation", ["rest", "bottle", "pen", "phone", "mouse", "glasses"])

    # new_model.set_warmup_mode(True)  # Set the model to warmup mode
    # lwf_train( new_model, dataset_train, dataset_val, warm_up=True)

    # new_model.set_warmup_mode(False)  # Set the model to normal mode
    lwf_train(old_model, new_model, dataset_train, dataset_train_replay, dataset_val)
if __name__ == "__main__":
    main()