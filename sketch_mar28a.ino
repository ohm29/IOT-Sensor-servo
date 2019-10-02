
const int trigPin = D0;
const int echoPin = D1;
long duration;
int distance;
#include <Servo.h>
Servo myservo;     


void setup() {
  myservo.attach(D2);
 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(50);
  
if (distance < 50) {
    myservo.write(300);
    delay(3000); 
 } else if (distance > 50){
   myservo.write(0);
  
}
}
