Project Overview (English)
This project is a Bluetooth-controlled robot car built with ESP32, L298N motor driver, and HC-SR04 ultrasonic sensor.
The control interface is created using the RemoteXY mobile app, which allows you to drive the car via a joystick and monitor the distance detected by the ultrasonic sensor in real time.
---
🔹 Features
RemoteXY BLE control (joystick + switch)
Forward / Backward / Left / Right movement
Ultrasonic distance measurement (displayed in app + Serial Monitor)
Safety stop when obstacle is too close (optional)
--
🔹 Hardware Used
ESP32 (ESP32-C3 or ESP32-WROOM supported)
L298N Motor Driver Module
DC Motors (x2)
HC-SR04 Ultrasonic Sensor
Power supply (Battery pack)
--
🔹 Pin Connections
Component	ESP32 Pin
IN1 (L298N)	GPIO14
IN2 (L298N)	GPIO27
IN3 (L298N)	GPIO26
IN4 (L298N)	GPIO25
TRIG (HC-SR04)	GPIO12
ECHO (HC-SR04)	GPIO13
--
🔹 How to Use
Install RemoteXY app on your smartphone (iOS/Android).
Open the provided .rxy configuration or use the built-in BLE interface.
Upload the Arduino code to ESP32 using Arduino IDE.
Power on the robot and connect from the app via BLE (RemoteXY device).
Use the joystick to control movement and monitor distance value.

-----------

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
