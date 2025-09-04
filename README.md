# 🧤 Dataglove: Real-Time Object Recognition with the VMG30 Sensor Glove

This project enables **real-time object recognition** using the **VMG30 sensorized glove** by [Virtual Realities](https://www.vrealities.com/products/data-gloves/vmg30).  
Sensor data from the glove is processed using a deep learning model that classifies hand gestures and object interactions in real time.

> 🧪 This repository has also been a playground for experimenting with **continual learning** techniques, allowing the model to **incrementally learn new object classes** without forgetting previously learned ones.

---

## 🧠 Neural Network Model: A-CBLN

At the core of the system is an **A-CBLN** model:  
> **A**ttention-based **C**onvolutional **B**idirectional **L**STM **N**etwork  
Inspired by the [PLOS ONE paper](https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0294174).


---

## 📂 Repository Structure
ros2_ws/\
├── src/ \
│ ├── dataglove/ # ROS 2 nodes: data acquisition + real-timeclassification \
│ ├── dataglove_msg/ # Custom ROS 2 messages for glove data\
│ └── nn/ # Neural network code: training, evaluation, continual learning\
├── datasets/ # datasets gathered by me  \
├── presentation/ # slides to present the project \
├── images # picture of glove, object used, and graphs
- **`dataglove/`**  
  ROS 2 nodes for:
  - Reading data from the VMG30 glove  
  - Publishing it as ROS messages  
  - Running real-time classification

- **`dataglove_msg/`**  
  Custom message definitions used to structure glove sensor data in ROS 2.

- **`nn/`**  
  Python code for:
  - Training, validating, and testing the neural network  
  - Implementing continual learning methods like:
    - **Learning Without Forgetting (LwF)**
    - **Dark Experience Replay (DER)**  
  - Preprocessing, model saving/loading, and experiment tracking

---

## 🛠️ Build & Run Instructions

Make sure you have sourced your ROS 2 environment (and Python virtual environment, if used).

### 🔧 Build the ROS 2 Packages

```bash
colcon build --packages-select dataglove dataglove_msg
source install/setup.bash
```


### 🚀 Run the System

Start the glove data publisher:
```bash
ros2 run dataglove glove
```

Start the real-time classifier:
```bash
ros2 run dataglove real_time_classifier
```

---
## 🏋️‍♂️ Training & Continual Learning

To train a new model on recorded glove data:
```bash
cd src/nn/
python3 train.py
cp checkpoint.pt ../dataglove/dataglove
```

Make sure to install the required Python dependencies:

```bash
pip install -r requirements.txt
```

The nn/ directory also includes:
Continual learning strategies like:

- lwf.py for Learning Without Forgetting

- der.py for Dark Experience Replay

> **L**earning **W**hithout **F**orgetting: see paper [ArXive](https://arxiv.org/abs/1606.09282)\
**D**ark **E**xperience **R**eplay: see [ArXive](https://arxiv.org/abs/2004.07211)

<!--
---
## 🎓 Why This Project Matters
 
This project combines ROS 2, real-time systems, and deep learning to build an interactive gesture-based recognition system.
It also serves as a hands-on platform for experimenting with continual learning — a key challenge in making AI systems that learn over time without forgetting what they've already mastered.
-->