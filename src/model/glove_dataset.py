import torch
import pandas as pd
from torch.utils.data import Dataset
import os


class GloveDataset(Dataset):
    def __init__(self, directory, labels):
        self.directory = directory
        self.labels = labels
        self.label_id = {label: idx for idx, label in enumerate(self.labels)}
        self.data = []  # Store (tensor, label_id) pairs

        for label in self.labels:
            dir_path = os.path.join(self.directory, label)
            if not os.path.exists(dir_path):
                print(f"Directory {dir_path} does not exist.")
                continue

            for filename in os.listdir(dir_path):
                file_path = os.path.join(dir_path, filename)
                if os.path.isfile(file_path):
                    df = pd.read_csv(file_path, header=None)

                    # Select specific columns
                    used_columns = list(range(2, 25))       # 23 columns
                    used_columns += list(range(28, 32))     # 4 columns
                    used_columns += list(range(35, 39))     # 4 columns
                    df = df.iloc[:, used_columns]

                    # Normalize first 23 columns to [-1, 1]
                    df.iloc[:, :23] = (df.iloc[:, :23] / 1000.0) * 2 - 1

                    # Pad if needed to 100 rows
                    if df.shape[0] < 100:
                        padding = pd.DataFrame(0, index=range(100 - df.shape[0]), columns=df.columns)
                        df = pd.concat([padding, df], ignore_index=True)
                    elif df.shape[0] > 100:
                        df = df.iloc[-100:, :]  # keep the last 100 rows


                    tensor = torch.tensor(df.values, dtype=torch.float32).unsqueeze(0)  
                    label_tensor = torch.tensor(self.label_id[label], dtype=torch.long)
                    self.data.append((tensor, label_tensor))

    def __len__(self):
        return len(self.data)

    def __getitem__(self, index):
        return self.data[index]
