#include<Servo.h>
int motorPin1 = 12; // pin 2 on L293D IC
int motorPin2 = 13; // pin 7 on L293D IC
int motorPin3 = 11; // pin 2 on L293D IC
int motorPin4 = 10; // pin 7 on L293D IC
int enablePin = 5; // pin 1 on L293D IC
int state;
int flag=0; //makes sure that the serial only prints once the state

Servo servo_test;

void setup() {
    // sets the pins as outputs:
    
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(enablePin, OUTPUT);
    // sets enablePin high so that motor can turn on:
    digitalWrite(enablePin, HIGH);
    // initialize serial communication at 9600 bits per second:
Serial.begin(9600);
}

void loop() {
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){
state = Serial.read();
flag=0;
}
    // if the state is '0' the DC motor will turn off
    if (state == '0') {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        digitalWrite(motorPin3, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin4, LOW); // set pin 7 on L293D low
        if(flag == 0){
        Serial.println("Motor: off");
        flag=1;
}
}
    // if the state is '1' the motor will turn right
    else if (state == 'F') {`
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high
        digitalWrite(motorPin3, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin4, HIGH); // set pin 7 on L293D high
        if(flag == 0){
Serial.println("Motor: right");
flag=1;
}
}
    else if (state == 'R'){
        
        digitalWrite(motorPin1, HIGH); // set pin 2 on L293D low
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D high
        
        digitalWrite(motorPin3, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin4, HIGH); // set pin 7 on L293D high
        if(flag == 0){
            Serial.println("Motor: right");
            flag=1;
        }
    }
    else if (state == 'L'){
        
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high
        
        digitalWrite(motorPin3, HIGH); // set pin 2 on L293D low
        digitalWrite(motorPin4, LOW); // set pin 7 on L293D high
        if(flag == 0){
            Serial.println("Motor: right");
            flag=1;
        }
    }
    // if the state is '2' the motor will turn left
    else if (state == 'B') {
        digitalWrite(motorPin1, HIGH); // set pin 2 on L293D high
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        digitalWrite(motorPin3, HIGH); // set pin 2 on L293D high
        digitalWrite(motorPin4, LOW); // set pin 7 on L293D low
        if(flag == 0){
Serial.println("Motor: left");
flag=1;
}
}
}
