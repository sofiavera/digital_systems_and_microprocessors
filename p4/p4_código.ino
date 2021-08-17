#include <EnableInterrupt.h>
#define ARDUINOPIN2 2
#define ARDUINOPIN3 3
#define ARDUINOPIN4 4

volatile int valorX = 0; // VARIABLE DE LECTURA DEL EJE X
int pinJX = A0; // EJE X CONECTADO AL PIN ANALOGICO A0

volatile int value = 0;
int Delay2;
int Delay3;
int Delay4;

int x;
int a;
float t;

void SawtoothC(){
  value = 2;
}

void TriangleC(){
  value = 3;
}

void SquareC(){
  value = 4;
}

void SawtoothW(int d2){
  for(t=0; t<=100; t=t+1){
    Serial.println(t);
    delay(d2);
  }
}

void TriangleW(int d3){
  for(t=0;t<=100;t=t+1){
    Serial.println(t);
    delay(d3);
  }
  for(t=100;t>=0;t=t-1){
    Serial.println(t);
    delay(d3);  
  }
}

void SquareW(int d4){
  for(x=0;x<=100; x++){
    a =0;
    Serial.println(a);
    delay(d4);  
  }
  for(x=0; x<=100; x++){
    a =100;
    Serial.println(a);
    delay(d4);  
  }
}
void setup() {
  Serial.begin(115200);
  enableInterrupt(ARDUINOPIN2,SawtoothC,RISING);
  enableInterrupt(ARDUINOPIN3,TriangleC,RISING); 
  enableInterrupt(ARDUINOPIN4,SquareC,RISING);
}

void loop() {
  Serial.println(0);

  while (value == 2){
    valorX = analogRead (pinJX);
    delay(5);
    Delay2 = map(valorX, 1023, 0, 20,1);
    SawtoothW(Delay2); 
  }

  while (value == 3){ 
    valorX = analogRead (pinJX);
    delay(5);
    Delay3 = map(valorX, 1023, 0, 20,1);
    TriangleW(Delay3); 
  }

  while (value == 4){
    valorX = analogRead (pinJX);
    delay(5);
    Delay4 = map(valorX, 1023, 0, 20,1);
    SquareW(Delay4); 
  }
  
}


  
