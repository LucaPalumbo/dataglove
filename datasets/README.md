# 📁 Dataset - VMG30 Glove Grasping Movements

This folder contains the dataset used to train and evaluate the neural network model for real-time object recognition with the VMG30 data glove.

## 🛠️ Dataset Construction

The dataset was **manually collected** using the VMG30 sensorized glove.  
Each file in this folder corresponds to a **single recording of a grasping movement**, where the glove captured the sensor data over time.

## 🧪 Data Collection Protocol

To ensure consistency and reproducibility, each sample was recorded following this protocol:

1. **~1 second** with the **hand resting on the table**  
2. **Grasping movement** to reach and hold the object  
3. **~1 second** with the **hand holding the object still**

This approach ensures that each sample captures the **entire grasping action**, including both static and dynamic phases.
