#include <PS4Controller.h>
#include<ESP32Servo.h>
int pos1=0;
int pos2=0;
int pos3=0;

const int leftFrontMotorPin1 = 32;   // Left front motor pin 1
const int leftFrontMotorPin2 = 33;   // Left front motor pin 2

const int rightFrontMotorPin1 = 26;  // Right front motor pin 1
const int rightFrontMotorPin2 = 25; // Right front motor pin 2

const int leftRearMotorPin1 = 12;   // Left rear motor pin 1
const int leftRearMotorPin2 = 13;   // Left rear motor pin 2

const int rightRearMotorPin1 = 4;  // Right rear motor pin 1
const int rightRearMotorPin2 = 2;  // Right rear motor pin 2

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

void setup() {
     Serial.begin(115200);
  PS4.begin("cc:db:a7:00:ee:9e");

   myservo1.attach(19);
   myservo2.attach(18);
   myservo3.attach(21);
   myservo4.attach(5);
   
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
     if (PS4.Right())
    {
      MoveRight(); 
    }
    if (PS4.Left())
    {
      MoveLeft(); 
    }
     if (PS4.Up())
     {
      MoveForward(); 
     }
     if (PS4.Down())
     {
      MoveBackward();
     }
     if (PS4.Cross())
     {
      MoveStop();
      myservo4.write(90); 
     }
     if ((PS4.R1()))
     {
      myservo4.write(80);
     }
     if (PS4.L1()){
      
      myservo4.write(110);
    }
    if (PS4.Triangle())
    {
      if(pos1>180)
      {
        pos1=180;
      }
      else
      {
        pos1+=10;
      }
    Serial.println(pos1);
    myservo1.write(pos1);
    delay(1200);
    
    }
    if (PS4.Circle()) 
    {
      if(pos1<0)
      {
        pos1=0;
      }
      else
      {
        pos1-=10;
      }
     Serial.println(pos1);
     myservo1.write(pos1);
     delay(1200);
    
    }
    if (PS4.L2())
    {
      if(pos2<0)
      {
        pos2=0;
      }
      else
      {
        pos2-=25;
      }
       
      Serial.println(pos2);
      myservo2.write(pos2);
      delay(1200);
    }
    if (PS4.R2()) 
    {
      if(pos2>180)
      {
        pos2=180;
      }
      else
      {
        pos2+=25;
      }
       
      Serial.println(pos2);
      myservo2.write(pos2);
      delay(1200);
    }
     if (PS4.L3()){
      if(pos3<0)
      {
        pos3=0;
      }
      else
      {
        pos3-=15;
      }
      
      Serial.println(pos3);
      myservo3.write(pos3);
      delay(1200);
    }
     if (PS4.R3()){
      if(pos3>180)
      {
        pos3=180;
      }
      else
      {
        pos3+=15;
      }
      
      Serial.println(pos3);
      myservo3.write(pos3);
      delay(1200);
    }
   
  }


}


void MoveRight()
{
   digitalWrite(leftFrontMotorPin1, HIGH);
  digitalWrite(leftFrontMotorPin2, LOW);
  
  digitalWrite(rightFrontMotorPin1, HIGH);
  digitalWrite(rightFrontMotorPin2, LOW);
  
  digitalWrite(leftRearMotorPin1, HIGH);
  digitalWrite(leftRearMotorPin2, LOW);
  
  digitalWrite(rightRearMotorPin1, HIGH);
  digitalWrite(rightRearMotorPin2, LOW);
}
void MoveLeft()
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
void MoveForward()
{
      digitalWrite(leftFrontMotorPin1, HIGH);
  digitalWrite(leftFrontMotorPin2, LOW);
  
  digitalWrite(rightFrontMotorPin1, LOW);
  digitalWrite(rightFrontMotorPin2, HIGH);
  
  digitalWrite(leftRearMotorPin1, HIGH);
  digitalWrite(leftRearMotorPin2, LOW);
  
  digitalWrite(rightRearMotorPin1, LOW);
  digitalWrite(rightRearMotorPin2, HIGH);
}
void MoveBackward()
{
  digitalWrite(leftFrontMotorPin1, LOW);
  digitalWrite(leftFrontMotorPin2, HIGH);
  
  digitalWrite(rightFrontMotorPin1, HIGH);
  digitalWrite(rightFrontMotorPin2, LOW);
  
  digitalWrite(leftRearMotorPin1, LOW);
  digitalWrite(leftRearMotorPin2, HIGH);
  
  digitalWrite(rightRearMotorPin1, HIGH);
  digitalWrite(rightRearMotorPin2, LOW);
}
void MoveStop()
{
  digitalWrite(leftFrontMotorPin1, LOW);
  digitalWrite(leftFrontMotorPin2, LOW);
  
  digitalWrite(rightFrontMotorPin1, LOW);
  digitalWrite(rightFrontMotorPin2, LOW);
  
  digitalWrite(leftRearMotorPin1, LOW);
  digitalWrite(leftRearMotorPin2, LOW);
  
  digitalWrite(rightRearMotorPin1, LOW);
  digitalWrite(rightRearMotorPin2, LOW);

}
