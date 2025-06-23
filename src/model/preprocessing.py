
# read every file in specified directory and remove all the [ and ] characters
import os
import random
import shutil

def remove_brackets_from_files(directory):
    for filename in os.listdir(directory):
        if filename.endswith(".txt"):
            file_path = os.path.join(directory, filename)
            with open(file_path, 'r') as file:
                content = file.read()
            content = content.replace('[', '').replace(']', '')
            with open(file_path, 'w') as file:
                file.write(content)
    print(f"Brackets removed from all files in {directory}")


def train_val_test_split(partition = (0.6, 0.2, 0.2), directory = "dataset"):
    """
    Splits the dataset into training, validation, and test sets.
    
    Args:
        partition (tuple): A tuple containing the proportions for train, val, and test sets.
        directory (str): The directory containing the dataset.
        
    """
    all_files = []
    for label in os.listdir(directory):
        label_path = os.path.join(directory, label)
        if os.path.isdir(label_path):
            for file in os.listdir(label_path):
                all_files.append((os.path.join(label_path, file), label))

    # Shuffle the files
    random.shuffle(all_files)
    
    total_files = len(all_files)
    train_size = int(partition[0] * total_files)
    val_size = int(partition[1] * total_files)
    
    train_files = all_files[:train_size]
    val_files = all_files[train_size:train_size + val_size]
    test_files = all_files[train_size + val_size:]

    for f in train_files:
        # copy file to 'dataset/train/label' directory. Create directories if they do not exist
        label_dir = os.path.join(directory, 'train', f[1])
        os.makedirs(label_dir, exist_ok=True)
        # os.rename(f[0], os.path.join(label_dir, os.path.basename(f[0])))
        shutil.copy(f[0], os.path.join(label_dir, os.path.basename(f[0])))
    for f in val_files:
        # copy file to 'dataset/train/label' directory. Create directories if they do not exist
        label_dir = os.path.join(directory, 'validation', f[1])
        os.makedirs(label_dir, exist_ok=True)
        # os.rename(f[0], os.path.join(label_dir, os.path.basename(f[0])))
        shutil.copy(f[0], os.path.join(label_dir, os.path.basename(f[0])))
    for f in test_files:
        # copy file to 'dataset/train/label' directory. Create directories if they do not exist
        label_dir = os.path.join(directory, 'test', f[1])
        os.makedirs(label_dir, exist_ok=True)
        # os.rename(f[0], os.path.join(label_dir, os.path.basename(f[0])))
        shutil.copy(f[0], os.path.join(label_dir, os.path.basename(f[0])))
    

    


# Example usage
if __name__ == "__main__":
    directory = [
        "dataset/bottle",
        "dataset/pen",
        "dataset/phone"
    ]
    # for dir in directory:
    #     remove_brackets_from_files(dir)
    train_val_test_split(directory='dataset')
    