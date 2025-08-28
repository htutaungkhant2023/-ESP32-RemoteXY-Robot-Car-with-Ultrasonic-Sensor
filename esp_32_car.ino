//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 64 bytes
  { 255,3,0,5,0,57,0,19,0,0,0,0,82,1,106,200,1,1,4,0,
  5,17,107,69,69,32,2,26,31,67,12,61,83,24,109,2,26,2,70,76,
  14,18,18,16,26,136,0,2,10,16,31,15,1,2,26,31,31,79,78,0,
  79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_01_x; // from -100 to 100
  int8_t joystick_01_y; // from -100 to 100
  uint8_t switch_01; // =1 if switch ON and =0 if OFF

    // output variables
  float value_01;
  uint8_t led_01; // from 0 to 1

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

// L298N motor pins
#define IN1 14
#define IN2 27
#define IN3 26
#define IN4 25

// HC-SR04 ultrasonic pins
#define TRIG_PIN 12
#define ECHO_PIN 13



void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(115200);

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  // ========== Motor Control ==========
  int x = RemoteXY.joystick_01_x;
  int y = RemoteXY.joystick_01_y;

  if (y > 30) {
    // Forward
    motorForward();
  }
  else if (y < -30) {
    // Backward
    motorBackward();
  }
  else if (x < -30) {
    // Turn Left
    motorLeft();
  }
  else if (x > 30) {
    // Turn Right
    motorRight();
  }
  else {
    // Stop
    motorStop();
  }

  // ========== Distance Measurement ==========
  float distance = getDistanceCM();
  RemoteXY.value_01 = distance;

  // Print to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  RemoteXY_delay(100); // non-blocking delay

}

void motorForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void motorBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void motorLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void motorRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

//////////////////////////////////////////////
//           Distance Calculation           //
//////////////////////////////////////////////

float getDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 20000); // 20ms timeout
  float distance = duration * 0.034 / 2;
  if (distance > 400 || duration == 0) return -1; // Out of range
  return distance;
}