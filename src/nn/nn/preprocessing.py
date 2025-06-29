
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
    

    
# a function that takes the dataset and splits data into test (20%), and for the rest makes k folds (e.g. 5 folds) for training and validation
def k_fold_split(k=5, directory="dataset", test_ratio=0.2):
    """
    Splits the dataset into a test set and k folds for training and validation.

    Args:
        k (int): The number of folds.
        directory (str): The directory containing the dataset.
        test_ratio (float): Proportion of data to use as test set.
    """
    all_files = []
    labels = [d for d in os.listdir(directory) if os.path.isdir(os.path.join(directory, d)) and d not in ['train', 'validation', 'test', 'folds']]
    for label in labels:
        label_path = os.path.join(directory, label)
        for file in os.listdir(label_path):
            all_files.append((os.path.join(label_path, file), label))

    # Shuffle the files
    random.shuffle(all_files)

    # Split into test and the rest
    total_files = len(all_files)
    test_size = int(test_ratio * total_files)
    test_files = all_files[:test_size]
    rest_files = all_files[test_size:]

    # Save test files
    for f in test_files:
        label_dir = os.path.join(directory, 'test', f[1])
        os.makedirs(label_dir, exist_ok=True)
        shutil.copy(f[0], os.path.join(label_dir, os.path.basename(f[0])))

    # Create k folds from the rest
    fold_size = len(rest_files) // k
    folds = [rest_files[i*fold_size:(i+1)*fold_size] for i in range(k)]
    # Add remaining files to the last fold
    if len(rest_files) % k != 0:
        folds[-1].extend(rest_files[k*fold_size:])

    for i in range(k):
        val = folds[i]
        train = [f for j, fold in enumerate(folds) if j != i for f in fold]

        # Create directories and copy files
        train_dir = os.path.join(directory, 'folds', f'fold_{i+1}', 'train')
        val_dir = os.path.join(directory, 'folds', f'fold_{i+1}', 'validation')

        os.makedirs(train_dir, exist_ok=True)
        os.makedirs(val_dir, exist_ok=True)

        for f in train:
            label_dir = os.path.join(train_dir, f[1])
            os.makedirs(label_dir, exist_ok=True)
            shutil.copy(f[0], os.path.join(label_dir, os.path.basename(f[0])))

        for f in val:
            label_dir = os.path.join(val_dir, f[1])
            os.makedirs(label_dir, exist_ok=True)
            shutil.copy(f[0], os.path.join(label_dir, os.path.basename(f[0])))

    print(f"Dataset split: {len(test_files)} files for test, {k} folds for training/validation.")




# Example usage
if __name__ == "__main__":
    directory = [
        "dataset/rest",
        "dataset/bottle",
        "dataset/pen",
        "dataset/phone"
    ]
    # for dir in directory:
    #     remove_brackets_from_files(dir)
    # train_val_test_split(directory='dataset')
    k_fold_split(k=5, directory='./dataset')
    