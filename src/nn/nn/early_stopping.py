import torch
import numpy as np
import os


class EarlyStopping:
    def __init__(self, patience=5, delta=0, verbose=False):
        self.patience = patience
        self.delta = delta
        self.verbose = verbose
        self.counter = 0
        self.best_score = None
        self.early_stop = False
        self.val_loss_min = np.inf
        self.best_accuracy = 0.0

    def __call__(self, model, val_loss, accuracy=None, path='checkpoint.pt'):
        score = -val_loss  # Più alto è meglio (perché la loss deve diminuire)

        if self.best_score is None:
            self.best_score = score
            self.save_checkpoint(val_loss, accuracy, model, path)
        elif score < self.best_score + self.delta:
            self.counter += 1
            if self.verbose:
                print(f'EarlyStopping counter: {self.counter} out of {self.patience}')
            if self.counter >= self.patience:
                self.early_stop = True
        else:
            self.best_score = score
            self.save_checkpoint(val_loss, accuracy, model, path)
            self.counter = 0
        return self.early_stop

    def save_checkpoint(self, val_loss, accuracy, model, path):
        '''Salva il modello se la validation loss diminuisce.'''
        if self.verbose:
            print(f'Validation loss decreased ({self.val_loss_min:.6f} --> {val_loss:.6f}). Saving model...')
        torch.save(model.state_dict(), path)
        self.val_loss_min = val_loss
        self.best_accuracy = accuracy

    def store_results(self, num_feature, filename="results.csv"):
        # Check if the file exists
        if not os.path.exists(filename):
            # If it doesn't exist, create it and write the header
            with open(filename, 'w') as f:
                f.write("num_features,loss,accuracy\n")
        # Append the results to the file
        with open(filename, 'a') as f:
            f.write(f"{num_feature},{self.val_loss_min},{self.best_accuracy}\n")