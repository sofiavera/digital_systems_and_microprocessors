///ARDUINO MAESTRO///
#include "IRremote.h"
const int receiver = 11;      
IRrecv irrecv(receiver);
decode_results results;      
   
void setup(){   
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn();  
}
void loop(){   
  if (irrecv.decode(&results)){
    switch(results.value){
      
      case 0xFF6897:
        Serial.write("0");
        break;
      case 0xFF30CF:
        Serial.write("1");
        break;
    }
    delay(500);      
    irrecv.resume();            
  }  
}
