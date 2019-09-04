#include <Servo.h>
Servo servo;
int trigPin = 5;
int echoPin = 7;
int lidControl = 3;               
int powerServo = 2;
long distance;
int duration;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(lidControl);
  digitalWrite(powerServo, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (0.034*duration)/2;

  if(distance<30){
    delay(50);
    servo.write(0);
    delay(1700);
  }
  else{
    delay(10);
    servo.write(90);
    delay(100);
  }
  Serial.println(distance);
  

}
