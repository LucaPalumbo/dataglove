import torch
from torch import nn

class LwfClassifier(nn.Module):
    def __init__(self, input_size, n_tasks=1, output_classes = [4] ):
        super(LwfClassifier, self).__init__()
        self.input_size = input_size
        self.classifiers = nn.ModuleList()
        for i in range(n_tasks):
            output_class = output_classes[i] if i < len(output_classes) else output_classes[-1]
            classifier = nn.Linear(input_size, output_class)
            self.classifiers.append(classifier)
    
    def forward(self, x):
        # Esegui ogni classifier
        outputs = [clf(x) for clf in self.classifiers]
        # Concatenali lungo la dimensione delle classi (dim=1)
        # Il risultato è un tensor di shape (batch_size, sum(output_dims))
        return torch.cat(outputs, dim=1)

    def add_task(self, output_classes):
        classifier = nn.Linear(self.input_size, output_classes)
        self.classifiers.append(classifier)



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
    def __init__(self, num_features=31, output_classes=4):
        super(Network, self).__init__()

        self.relu = nn.ReLU()
        self.conv1 = nn.Conv2d(1, 16, kernel_size=(1, 3), padding=(0, 1))
        self.conv2 = nn.Conv2d(16, 32, kernel_size=(1, 3), padding=(0, 1))
        self.pool = nn.MaxPool2d(kernel_size=(1, 2), stride=(1, 2), padding=(0, 1) )
        self.bilstm = nn.LSTM(input_size=(num_features+2)//2*32, num_layers=2, hidden_size=16, bidirectional=True, batch_first=True)
        self.attention = Attention(hidden_dim=32)  
        self.dense1 = nn.Linear(32, 20)
        # self.dense2 = nn.Linear(10, output_classes)  
        self.classifier = LwfClassifier(20, output_classes=[output_classes])
        self.softmax = nn.Softmax(dim=1)


    def set_warmup_mode(self, warmup_mode=True):
        """
        Set the warmup mode for the network. All parameters will be frozen except the last layer.
        :param warmup_mode: bool, if True, the network will be in warmup mode.
        """
        for param in self.parameters():
            param.requires_grad = not warmup_mode
        
        for param in self.classifier.classifiers[-1].parameters():
            param.requires_grad = True

        

    def forward(self, x):
        x = self.relu(self.conv1(x))
        x = self.relu(self.conv2(x))
        x = self.pool(x)

        x = x.permute(0, 2, 1, 3)
        x = x.flatten(start_dim=2)
        x, _ = self.bilstm(x)
        x, _ = self.attention(x)
        x = self.relu(self.dense1(x))
        x = self.classifier(x)
        x = self.softmax(x)

        return x
