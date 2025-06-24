# 🧤 Dataglove: Real-Time Object Recognition with VMG30 Sensorized Glove

This project enables **real-time object recognition** using the **VMG30 data glove** by [Virtual Realities](https://www.vrealities.com/products/data-gloves/vmg30).  
It uses a neural network model to classify hand gestures or object interactions from sensor data.

---

## 🧠 Neural Network Model: A-CBLN

We use the **A-CBLN** architecture:  
> **A**ttention-based **C**onvolutional **B**idirectional **L**STM **N**etwork  
As described in the [PLOS ONE paper](https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0294174).

---

## 📦 ROS 2 Packages

This project is composed of two main packages:

- `dataglove_msg`: Custom message definitions for glove data.
- `dataglove`: ROS 2 nodes for publishing, processing, and classifying glove data.

---

## 🛠️ Build Instructions

Make sure you have sourced your ROS 2 environment and (if needed) your virtual environment.

To build only this project:

```bash
colcon build --packages-select dataglove dataglove_msg
```

Then source your workspace:
```bash
source install/setup.bash
```

🚀 Run the System

Launch the publisher node:
```bash
ros2 run dataglove glove
```
Launch the real-time classifier node:
```bash
ros2 run dataglove real_time_classifier
```

🏋️‍♂️ Train a New Model

If you want to train your own model using recorded glove data:
```bash
cd src/model/
python3 train.py
```

Make sure all dependencies (e.g. PyTorch, NumPy, etc.) are installed and properly configured in your environment.
📂 Project Structure

ros2_ws/
├── src/
│   ├── dataglove/          # ROS 2 node logic (publisher + classifier)
│   ├── dataglove_msg/      # Custom ROS 2 messages
│   └── model/              # Neural network code (train.py, models/, etc.)

✅ Requirements

Install Python dependencies with:
```bash
pip install -r requirements.txt
```

📄 License


🙋‍♂️ Contributions

