import torch
import pandas as pd
from torch.utils.data import Dataset
import os


class GloveDataset(Dataset):
    def __init__(self, directory, labels, num_features=31):
        self.directory = directory
        self.labels = labels
        self.label_id = {label: idx for idx, label in enumerate(self.labels)}
        self.data = []  # Store (tensor, label_id) pairs
        self.time_length = 300

        for label in self.labels:
            dir_path = os.path.join(self.directory, label)
            if not os.path.exists(dir_path):
                print(f"Directory {dir_path} does not exist.")
                continue

            for filename in os.listdir(dir_path):
                file_path = os.path.join(dir_path, filename)
                if os.path.isfile(file_path):
                    df = pd.read_csv(file_path, header=None)

                    # used_columns = list(range(2, 25)) + list(range(26, 30)) + list(range(31, 35))
                    used_columns = list(range(2,33))
                    if num_features is not None:
                        used_columns = used_columns[:num_features]
                    df = df.iloc[:, used_columns]

                    # Normalize first 23 columns to [-1, 1]
                    df.iloc[:, :23] = (df.iloc[:, :23] / 1000.0) * 2 - 1

                    # Pad if needed
                    if df.shape[0] < self.time_length:
                        padding = pd.DataFrame(0, index=range(self.time_length - df.shape[0]), columns=df.columns)
                        df = pd.concat([padding, df], ignore_index=True)
                    elif df.shape[0] > self.time_length:
                        df = df.iloc[-self.time_length:, :]  # keep the last rows


                    tensor = torch.tensor(df.values, dtype=torch.float32).unsqueeze(0)  
                    label_tensor = torch.tensor(self.label_id[label], dtype=torch.long)
                    self.data.append((tensor, label_tensor))

    def __len__(self):
        return len(self.data)

    def __getitem__(self, index):
        return self.data[index]
