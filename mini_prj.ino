#include <Servo.h>

Servo myservo1;

char t;
int ran;
const int trigPin = 7;
const int echoPin = 8;
// defines variables
long duration;
int distance;
void setup() {

  ran = random(10);
myservo1.attach(4); 
pinMode(9,OUTPUT);   //left motors forward
pinMode(10,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(12,OUTPUT);   //right motors reverse
pinMode(3,OUTPUT);   //right motors reverse

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  if(t!= 'S'){
    Serial.println(t); 
  }
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
//  delay(500);
  if(distance <= 10){
    digitalWrite(3, HIGH);
  }
  else{
    digitalWrite(3, LOW);
  }
  //  Serial.println(ran);
  
}
 
if(t == 'R'){            //move forward(all motors rotate in forward direction)
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
 
else if(t == 'L'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}
 
else if(t == 'F'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
 
else if(t == 'B'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}
 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}


else if(t == 'W')
{
  myservo1.write(5);
}

else if(t == 'w')
{
  myservo1.write(90);
}





}
