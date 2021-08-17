#include "IRremote.h"
#include <Servo.h>
Servo myservo; 
int pos = 0;
const int receiver = 11;      
IRrecv irrecv(receiver);
decode_results results;      

void moveservo() {        
  switch(results.value){
    case 0xFF6897: Serial.println("0"); pos = 0; myservo.write(pos); break;
    case 0xFF30CF: Serial.println("1"); pos = 180; myservo.write(pos);  break;   
  default: 
    Serial.print(" other button   ");
    Serial.println(results.value);
  }
}
void setup(){   
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn();  
  myservo.attach(12);
}
void loop(){   
  if (irrecv.decode(&results))   
  {
    moveservo(); 
    delay(500);      
    irrecv.resume();            
  }  
}
