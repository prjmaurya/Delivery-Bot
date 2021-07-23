#include<Servo.h> 
Servo servo_test;
int obstaclePin1 = 7;  // This is our input pin
int obstaclePin2 = 8;  // This is our input pin
int LED = 13; // Use the onboard Uno LED
int hasObstacle1 = HIGH;  // HIGH MEANS NO OBSTACLE
int hasObstacle2 = HIGH;  // HIGH MEANS NO OBSTACLE
void setup() {
  servo_test.attach(3);
  // put your setup code here, to run once:
   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  hasObstacle1 = digitalRead(obstaclePin1);//Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
  hasObstacle2 = digitalRead(obstaclePin2);
  if (hasObstacle1 == HIGH || hasObstacle2 == HIGH) //LOW means something is ahead, so illuminates the 13th Port connected LED
  {
    Serial.println("Someone is on the door!!");
    
    digitalWrite(LED, HIGH);//Illuminates the 13th Port LED
    servo_test.write(4);
  }
  else
  {
//    Serial.println("Path is clear");
    digitalWrite(LED, LOW);
    servo_test.write(91);
  }
//  delay(10);

}
