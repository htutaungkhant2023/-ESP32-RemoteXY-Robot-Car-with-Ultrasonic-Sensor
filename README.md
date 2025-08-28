🚙 ESP32-C3 RemoteXY Robot Car
---
📌 Overview
This project uses ESP32-C3, L298N Motor Driver, and HC-SR04 Ultrasonic Sensor
to build a robot car that can be controlled via the RemoteXY mobile app (BLE).
You can drive it forward, backward, left, and right using the joystick,
and the ultrasonic sensor measures the distance in real time.
---
🔧 Hardware Requirements
ESP32-C3 Mini
L298N Motor Driver
DC Motors (x2 or x4)
HC-SR04 Ultrasonic Sensor
Battery (Li-ion / Li-Po)
RemoteXY App (Android / iOS)
---
💻 Software Requirements
Arduino IDE (with ESP32 board support)
Libraries:
RemoteXY
BLEDevice (for ESP32 BLE)
---
🎮 Controls
Joystick (RemoteXY app)
Forward: Joystick ↑
Backward: Joystick ↓
Turn Left: Joystick ←
Turn Right: Joystick →
Stop: Center position
The ultrasonic distance value is displayed in the RemoteXY app.
---
📂 Project Structure
robot-car
│── robot_car.ino   # Main control code
│── README.md
---
🖼️ Demo
![480658894_1341516586868134_5550177618425314348_n](https://github.com/user-attachments/assets/2c5c89c7-e9fe-4c14-8bf7-ac85c9c1130e)


