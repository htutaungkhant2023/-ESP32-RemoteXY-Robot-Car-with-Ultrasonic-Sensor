🚙 ESP32-C3 RemoteXY Robot Car
📌 Overview
This project uses ESP32-C3, L298N Motor Driver, and HC-SR04 Ultrasonic Sensor
to build a robot car that can be controlled via the RemoteXY mobile app (BLE).
You can drive it forward, backward, left, and right using the joystick,
and the ultrasonic sensor measures the distance in real time.
🔧 Hardware Requirements
ESP32-C3 Mini
L298N Motor Driver
DC Motors (x2 or x4)
HC-SR04 Ultrasonic Sensor
Battery (Li-ion / Li-Po)
RemoteXY App (Android / iOS)
💻 Software Requirements
Arduino IDE (with ESP32 board support)
Libraries:
RemoteXY
BLEDevice (for ESP32 BLE)
🎮 Controls
Joystick (RemoteXY app)
Forward: Joystick ↑
Backward: Joystick ↓
Turn Left: Joystick ←
Turn Right: Joystick →
Stop: Center position
The ultrasonic distance value is displayed in the RemoteXY app.
📂 Project Structure
robot-car/
│── robot_car.ino   # Main control code
│── README.md
🖼️ Demo
![480658894_1341516586868134_5550177618425314348_n](https://github.com/user-attachments/assets/2c5c89c7-e9fe-4c14-8bf7-ac85c9c1130e)


----------

📖 プロジェクト概要 (日本語)
このプロジェクトは、ESP32、L298Nモータードライバ、HC-SR04超音波センサーを使用した
Bluetooth制御ロボットカーです。
スマホアプリ RemoteXY を使って、ジョイスティックで操作し、リアルタイムに障害物までの距離を確認できます。
🔹 機能
RemoteXY BLE制御（ジョイスティック＋スイッチ）
前進 / 後退 / 左旋回 / 右旋回
超音波センサーによる距離計測（アプリとシリアルモニタに表示）
障害物接近時に自動停止（オプション）
--
🔹 使用ハードウェア
ESP32（ESP32-C3 または ESP32-WROOM）
L298N モータードライバモジュール
DCモーター ×2
HC-SR04 超音波センサー
電源（バッテリーパック）
--
🔹 ピン接続
コンポーネント	ESP32 ピン
IN1 (L298N)	GPIO14
IN2 (L298N)	GPIO27
IN3 (L298N)	GPIO26
IN4 (L298N)	GPIO25
TRIG (HC-SR04)	GPIO12
ECHO (HC-SR04)	GPIO13
--
🔹 使い方
スマホに RemoteXYアプリ をインストールします（iOS/Android対応）。
提供された .rxy 設定ファイルを読み込むか、組み込みのBLEインターフェイスを使用します。
Arduino IDE から ESP32 にスケッチをアップロードします。
電源を入れ、アプリから BLE (RemoteXY) デバイスに接続します。
ジョイスティックでロボットを操作し、距離データを確認できます。
