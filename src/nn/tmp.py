import os
import pandas as pd


def check(directory, idx):
    lables = ["rest", "bottle", "pen", "phone"]
    for label in lables:
        label_dir = os.path.join(directory, label)
        if not os.path.exists(label_dir):
            print(f"Label directory {label_dir} does not exist.")
            continue

        for file in os.listdir(label_dir):
            file_path = os.path.join(label_dir, file)
            if not os.path.isfile(file_path):
                print(f"File {file_path} is not a valid file.")
                continue

            try:
                df = pd.read_csv(file_path, header=None)
                if df.empty:
                    print(f"File {file_path} is empty.")

                # select the columns with index idx
                df_selected = df.iloc[:, idx]
                # print(f"Selected columns from {file_path}:\n{df_selected}")
                # check if the selected column is all zeros
                if (df_selected == 0).all():
                    print(f"File {file_path} has all zeros in column index {idx}.")
            

            except Exception as e:
                print(f"Error reading {file_path}: {e}")



if __name__ == "__main__":
    directory = '/home/feld/ros2_ws/datasets/corrupted_dataset_filtered_usable'
    idx = 14
    check(directory, idx)
    idx = 16
    check(directory, idx)