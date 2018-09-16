#include <AFMotor.h>      //add Adafruit Motor Shield library

const int trigPin1 = A0;
const int echoPin1 = A1;
const int trigPin2 = A2; 
const int echoPin2 = A3;
const int trigPin3 = A4;
const int echoPin3 = A5;

#define TurnDistance 8
#define FrontDistance 6


AF_DCMotor leftMotor(2, MOTOR12_1KHZ); // create motor #1, using M2 output, set to 1kHz PWM frequency
AF_DCMotor rightMotor(1, MOTOR12_1KHZ);// create motor #2, using M1 output, set to 1kHz PWM frequency

int leftDistance, rightDistance; //distances on either side

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  leftMotor.setSpeed(50);
  rightMotor.setSpeed(50);


}

void loop() {
  // put your main code here, to run repeatedly:

leftMotor.setSpeed(50);
rightMotor.setSpeed(50);


 
  if ( FrontSensor() < FrontDistance && RightSensor () < TurnDistance && LeftSensor ()< TurnDistance) // obstacle infront of all 3 sides
  {
     turnAround (); //then reverse
  }
  else if (FrontSensor() < FrontDistance && RightSensor () < TurnDistance  && LeftSensor ()> TurnDistance) // obstacle on right and front sides
  {
     turnLeft (); // turn left side
  }
  else if (FrontSensor() < FrontDistance && RightSensor () > TurnDistance && LeftSensor ()< TurnDistance) // obstacle on left and front sides
  {
     turnRight (); // turn right side
  }
  else if (FrontSensor() < FrontDistance && RightSensor () >TurnDistance && LeftSensor ()> TurnDistance) // obstacle on front sides
  {
     turnRight (); // then turn right
  }
  else if (FrontSensor() > FrontDistance && RightSensor () > TurnDistance && LeftSensor ()< TurnDistance) // obstacle on left sides
  {
     turnRight (); // then turn right and then forward
  }
  else if (FrontSensor() > FrontDistance && RightSensor () < TurnDistance && LeftSensor () > TurnDistance) // obstacle on right sides
  {
     moveForward(); // then turn left and then right
  }
  else
  {
     moveForward();
  }
}



long LeftSensor ()
{
long dur;
digitalWrite(trigPin1, LOW);
delayMicroseconds(5); // delays are required for a succesful sensor operation.
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin1, LOW);
dur = pulseIn(echoPin1, HIGH);
return (dur/58);// convert the distance to centimeters.
}
long FrontSensor ()
{
long dur;
digitalWrite(trigPin2, LOW);
delayMicroseconds(5); // delays are required for a succesful sensor operation.
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin2, LOW);
dur = pulseIn(echoPin2, HIGH);
return (dur/58);// convert the distance to centimeters.
}
long RightSensor ()
{
long dur;
digitalWrite(trigPin3, LOW);
delayMicroseconds(5); // delays are required for a succesful sensor operation.
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin3, LOW);
dur = pulseIn(echoPin3, HIGH);
return (dur/58);// convert the distance to centimeters.
}



void moveForward() {
    
    leftMotor.run(FORWARD);      // turn it on going forward
    rightMotor.run(FORWARD);     // turn it on going forward
  
}
//-------------------------------------------------------------------------------------------------------------------------------------
void moveBackward() {
    
    leftMotor.run(BACKWARD);     // turn it on going backward
    rightMotor.run(BACKWARD);    // turn it on going backward

}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnRight() {
 
  leftMotor.run(FORWARD);      // turn motor 1 forward
  rightMotor.run(BACKWARD);    // turn motor 4 backward
    
  delay(100); // run motors this way for 1500        
  
  leftMotor.run(FORWARD);      // set both motors back to forward
  rightMotor.run(FORWARD);
       
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnLeft() {
  
  leftMotor.run(BACKWARD);      // turn motor 1 backward
  rightMotor.run(FORWARD);     // turn motor 4 forward
  
  delay(100); // run motors this way for 1500  
  
  leftMotor.run(FORWARD);      // turn it on going forward
  rightMotor.run(FORWARD);     // turn it on going forward
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnAround() {
  
  leftMotor.run(FORWARD);      // turn motor 1 forward
  rightMotor.run(BACKWARD);    // turn motor 4 backward
  
  delay(100); // run motors this way for 1700
  
  leftMotor.run(FORWARD);      // set both motors back to forward
  rightMotor.run(FORWARD);      
}  


