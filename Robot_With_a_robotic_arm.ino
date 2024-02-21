#include <PS4Controller.h>
const int leftFrontMotorPin1 = 32;   // Left front motor pin 1
const int leftFrontMotorPin2 = 33;   // Left front motor pin 2

const int rightFrontMotorPin1 = 26;  // Right front motor pin 1
const int rightFrontMotorPin2 = 25; // Right front motor pin 2

const int leftRearMotorPin1 = 12;   // Left rear motor pin 1
const int leftRearMotorPin2 = 13;   // Left rear motor pin 2

const int rightRearMotorPin1 = 2;  // Right rear motor pin 1
const int rightRearMotorPin2 = 4;  // Right rear motor pin 2

void setup() {
    Serial.begin(115200);
  PS4.begin("cc:db:a7:00:ee:9e");
  
  pinMode(leftFrontMotorPin1, OUTPUT); 
  pinMode(leftFrontMotorPin2, OUTPUT); 
  
  pinMode(rightFrontMotorPin1, OUTPUT);
  pinMode(rightFrontMotorPin2, OUTPUT);
  
  pinMode(leftRearMotorPin1, OUTPUT);
  pinMode(leftRearMotorPin2, OUTPUT);
  
  pinMode(rightRearMotorPin1, OUTPUT);
  pinMode(rightRearMotorPin2, OUTPUT);
  

}

void loop() {
  if (PS4.isConnected())
  {
    if (PS4.Up()){
      digitalWrite(leftFrontMotorPin1, HIGH);
  digitalWrite(leftFrontMotorPin2, LOW);
  
  digitalWrite(rightFrontMotorPin1, HIGH);
  digitalWrite(rightFrontMotorPin2, LOW);
  
  digitalWrite(leftRearMotorPin1, HIGH);
  digitalWrite(leftRearMotorPin2, LOW);
  
  digitalWrite(rightRearMotorPin1, HIGH);
  digitalWrite(rightRearMotorPin2, LOW);
      
    }
    if (PS4.Down())
    {
      digitalWrite(leftFrontMotorPin1, LOW);
  digitalWrite(leftFrontMotorPin2, HIGH);
  
  digitalWrite(rightFrontMotorPin1, LOW);
  digitalWrite(rightFrontMotorPin2, HIGH);
  
  digitalWrite(leftRearMotorPin1, LOW);
  digitalWrite(leftRearMotorPin2, HIGH);
  
  digitalWrite(rightRearMotorPin1, LOW);
  digitalWrite(rightRearMotorPin2, HIGH);
    }
    if (PS4.Right()){
      Serial.println("Right Button");  
  digitalWrite(leftFrontMotorPin1, HIGH);
  digitalWrite(leftFrontMotorPin2, LOW);
  
  digitalWrite(rightFrontMotorPin1, LOW);
  digitalWrite(rightFrontMotorPin2, HIGH);
  
  digitalWrite(leftRearMotorPin1, HIGH);
  digitalWrite(leftRearMotorPin2, LOW);
  
  digitalWrite(rightRearMotorPin1, LOW);
  digitalWrite(rightRearMotorPin2, HIGH);
    
 
    }
    if (PS4.Left()){
      Serial.println("Left Button");
  digitalWrite(leftFrontMotorPin1, LOW);
  digitalWrite(leftFrontMotorPin2, HIGH);
  
  digitalWrite(rightFrontMotorPin1, HIGH);
  digitalWrite(rightFrontMotorPin2, LOW);
  
  digitalWrite(leftRearMotorPin1, LOW);
  digitalWrite(leftRearMotorPin2, HIGH);
  
  digitalWrite(rightRearMotorPin1, HIGH);
  digitalWrite(rightRearMotorPin2, LOW);
      
 }
 if (PS4.Cross()){
      Serial.println("Cross Button");   
      digitalWrite(leftFrontMotorPin1, LOW);
  digitalWrite(leftFrontMotorPin2, LOW);
  
  digitalWrite(rightFrontMotorPin1, LOW);
  digitalWrite(rightFrontMotorPin2, LOW);
  
  digitalWrite(leftRearMotorPin1, LOW);
  digitalWrite(leftRearMotorPin2, LOW);
  
  digitalWrite(rightRearMotorPin1, LOW);
  digitalWrite(rightRearMotorPin2, LOW);
      
      
    }
      
  }


}
