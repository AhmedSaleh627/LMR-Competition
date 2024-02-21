#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library
#include <SoftwareSerial.h> //Bluetooth module library

//our L298N control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 8;
const int RightMotorForward = 2;
const int RightMotorBackward = 3;

//sensor pins
#define IR_sensor 5
int IR;
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2
#define EN_1 11
#define EN_2 6
#define maximum_distance 200

boolean goesForward = false;
int distance = 100;
boolean forward = false ;
boolean backward = false ;
boolean left = false ;
boolean right = false ;
boolean stopped = false ; 
boolean flag = false ;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function

Servo servo_motor; //our servo name

SoftwareSerial BTSerial(10, 9); // RX | TX Bluetooth

void setup() {
  pinMode(IR_sensor, INPUT);
  pinMode(EN_1, OUTPUT);
  pinMode(EN_2, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  servo_motor.attach(4); //our servo pin
  servo_motor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  BTSerial.begin(9600); // set up Bluetooth serial communication
  Serial.begin(9600);
}

void loop() {
  IR = digitalRead(IR_sensor);
  analogWrite(EN_1, 100);
  analogWrite(EN_2, 85);
  if (BTSerial.available()) {
    char data = BTSerial.read();
    Serial.write(data);
    switch (data) 
    {
    case 'f' :
      forward = true ;
      backward = false;
      left = false;
      right = false;
      stopped = false ;
      flag = false ; 
      break;
    case 'b' :
      forward = false ;
      backward = true;
      left = false;
      right = false;
      stopped = false ;
      flag = false ; 
      break;
    case 'r': 
      forward = false ;
      backward = false;
      left = false;
      right = true;
      stopped = false ;
      flag = false ; 
      break;
    case 'l':
      forward = false ;
      backward = false;
      left = true;
      right = false;
      stopped = false ;
      flag = false ; 
      break;
    case 's' :
      stopped = true ;
      forward = false ;
      backward = false;
      left = false;
      right = false;
      flag = false ; 
      break;
    case 'a' :
      stopped = false ;
      forward = false ;
      backward = false;
      left = false;
      right = false;
      flag = true ; 
      break;
    }
   
  }
  if(forward)
  {
    moveForward();
  }
  else if(backward)
  {
    moveBackward();
  }
  else if(right)
  {
    turnRight();
  }
  else if(left)
  {
    turnLeft();
  }
  else if(stopped) 
  {
    moveStop() ; 
  }
  if(flag) { // Otherwise, continue with autonomous movement
    analogWrite(EN_1, 100);
    analogWrite(EN_2, 85);
    int distanceRight = 0;
    int distanceLeft = 0;
    delay(50);
    if (distance <= 20) {
      moveStop();
      delay(300);
      moveBackward();
      delay(400);
      moveStop();
      delay(300);
      distanceRight = lookRight();
      delay(300);
      distanceLeft = lookLeft();
      delay(300);
      if (distance >= distanceLeft) {
        turnRight();
        moveStop();
      } else {
        turnLeft();
        moveStop();
      }
    } else {
      moveForward();
    }
    distance = readPing();
    Serial.println(distance);
  }
  if(IR == HIGH)
  {
    flag = false ;
    stopped = true ;
    moveStop();
  }
}

int lookRight() {
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft() {
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  Serial.println("stop");
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward() {
  goesForward = true;
  Serial.println("For");
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void moveBackward() {
  Serial.println("back");
//  goesForward = false;
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
}

void turnRight() {
  Serial.println("right");
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(250);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW); 
}

void turnLeft() {
  Serial.println("left");
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(250);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
