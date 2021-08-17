///ARDUINO ESCLAVO///
#include <Servo.h>
Servo myservo; 
int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(12);
}
void loop() {
  char data = Serial.read();
  switch(data){
    case "0":
      Serial.println("0");
      pos = 0; 
      myservo.write(pos); 
    case "1":
      Serial.println("1"); 
      pos = 180; 
      myservo.write(pos);
  }
}
