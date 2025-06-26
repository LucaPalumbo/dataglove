import torch
from torch import nn


class Attention(nn.Module):
    def __init__(self, hidden_dim):
        super(Attention, self).__init__()
        self.attn = nn.Linear(hidden_dim, 1)
        self.softmax = nn.Softmax(dim=1)

    def forward(self, lstm_output):
        # lstm_output: (batch, seq_len, hidden_dim)
        scores = self.attn(lstm_output)              # (batch, seq_len, 1)
        weights = self.softmax(scores)               # (batch, seq_len, 1)
        context = torch.sum(weights * lstm_output, dim=1)  # (batch, hidden_dim)
        return context, weights
    

class Network(nn.Module):
    def __init__(self):
        super(Network, self).__init__()

        self.relu = nn.ReLU()
        self.conv1 = nn.Conv2d(1, 16, kernel_size=(1, 3), padding=(0, 1))
        self.conv2 = nn.Conv2d(16, 32, kernel_size=(1, 3), padding=(0, 1))
        self.pool = nn.MaxPool2d(kernel_size=(1, 2), stride=(1, 2), padding=(0, 1) )
        self.bilstm = nn.LSTM(input_size=512, num_layers=2, hidden_size=8, bidirectional=True, batch_first=True)
        self.attention = Attention(hidden_dim=16)  
        self.dense = nn.Sequential(
            nn.Linear(16, 10),  # Paper uses 16 FC units
            nn.ReLU(),
            nn.Linear(10, 4)
        )
        self.softmax = nn.Softmax(dim=1)



    def forward(self, x):
        x = self.relu(self.conv1(x))
        x = self.relu(self.conv2(x))
        x = self.pool(x)

        x = x.permute(0, 2, 1, 3)
        x = x.flatten(start_dim=2)
        x , _ = self.bilstm(x)
        x, _ = self.attention(x)
        x = self.dense(x)
        x = self.softmax(x)

        return x
