import torch
from torch import nn


class SelectiveFreezeDense(nn.Module):
    """
    Layer denso che permette di freezare selettivamente i pesi delle classi originali
    """
    def __init__(self, input_size, old_classes, new_classes):
        super(SelectiveFreezeDense, self).__init__()
        self.old_classes = old_classes
        self.new_classes = new_classes
        self.total_classes = old_classes + new_classes
        
        # Pesi per le classi originali (verranno freezati durante warmup)
        self.old_weight = nn.Parameter(torch.randn(input_size, old_classes))
        self.old_bias = nn.Parameter(torch.randn(old_classes))
        
        # Pesi per le nuove classi (sempre trainable)
        self.new_weight = nn.Parameter(torch.randn(input_size, new_classes))
        self.new_bias = nn.Parameter(torch.randn(new_classes))
        
        # Flag per controllare il freezing
        self.warmup_mode = True
        
    def forward(self, x):
        # Output per le classi originali
        old_output = torch.matmul(x, self.old_weight) + self.old_bias
        
        # Output per le nuove classi
        new_output = torch.matmul(x, self.new_weight) + self.new_bias
        
        # Concatenazione degli output
        return torch.cat([old_output, new_output], dim=-1)
    
    def set_warmup_mode(self, warmup=True):
        """Attiva/disattiva la modalità warmup"""
        self.warmup_mode = warmup
        self.old_weight.requires_grad = not warmup
        self.old_bias.requires_grad = not warmup
        self.new_weight.requires_grad = True
        self.new_bias.requires_grad = True
    
    def load_old_weights(self, old_weight, old_bias):
        """Carica i pesi del modello precedente"""
        with torch.no_grad():
            self.old_weight.copy_(old_weight)
            self.old_bias.copy_(old_bias)


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
    def __init__(self, num_features=31, output_classes=4, old_model=None, old_model_output_classes=2):
        super(Network, self).__init__()

        self.relu = nn.ReLU()
        self.conv1 = nn.Conv2d(1, 16, kernel_size=(1, 3), padding=(0, 1))
        self.conv2 = nn.Conv2d(16, 32, kernel_size=(1, 3), padding=(0, 1))
        self.pool = nn.MaxPool2d(kernel_size=(1, 2), stride=(1, 2), padding=(0, 1) )
        self.bilstm = nn.LSTM(input_size=(num_features+2)//2*32, num_layers=2, hidden_size=8, bidirectional=True, batch_first=True)
        self.attention = Attention(hidden_dim=16)  
        self.dense1 = nn.Linear(16, 10)
        self.dense2 = nn.Linear(10, output_classes)  
        self.softmax = nn.Softmax(dim=1)



        if old_model is not None:
            with torch.no_grad():
                # Initialize the new model with the old model's weights
                self.conv1.weight.data = old_model.conv1.weight.data.clone()
                self.conv2.weight.data = old_model.conv2.weight.data.clone()
                self.bilstm.load_state_dict(old_model.bilstm.state_dict(), strict=False)
                self.attention.load_state_dict(old_model.attention.state_dict(), strict=False)
                self.dense1.weight.data = old_model.dense1.weight.data.clone()
                self.dense1.bias.data = old_model.dense1.bias.data.clone()
                            
                w = old_model.dense2.weight
                b = old_model.dense2.bias
        
                # self.dense[2].weight[:old_model_output_classes] = old_model.dense[2].weight
                # self.dense[2].bias[:old_model_output_classes] = old_model.dense[2].bias
        

    def set_warmup_mode(self, warmup_mode=True):
        """
        Set the warmup mode for the network.
        :param warmup_mode: bool, if True, the network will be in warmup mode.
        """
        self.warmup_mode = warmup_mode
        if warmup_mode:
            # Freeze the convolutional layers and LSTM layers
            for param in self.conv1.parameters():
                param.requires_grad = False
            for param in self.conv2.parameters():
                param.requires_grad = False
            for param in self.bilstm.parameters():
                param.requires_grad = False
            for param in self.attention.parameters():
                param.requires_grad = False
            for param in self.dense1.parameters():
                param.requires_grad = False
        else:
            # Unfreeze all layers
            for param in self.parameters():
                param.requires_grad = True

    def forward(self, x):
        x = self.relu(self.conv1(x))
        x = self.relu(self.conv2(x))
        x = self.pool(x)

        x = x.permute(0, 2, 1, 3)
        x = x.flatten(start_dim=2)
        x , _ = self.bilstm(x)
        x, _ = self.attention(x)
        x = self.relu(self.dense1(x))
        x = self.dense2(x)
        x = self.softmax(x)

        return x
