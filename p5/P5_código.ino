#include <EnableInterrupt.h>
#include "pitches.h"
#include <LiquidCrystal.h>

#define ELEVEN 11
#define TWELVE 12
#define THIRTEEN 13
#define EIGHT 8

LiquidCrystal lcd(7,6,5,4,3,2);

const int ledPinR = 10;

const int buzzer = 9;
int melody = NOTE_F3;

int atrial_fibrillation[80] = {59,59,59,81,88,98,59,59,67,66,55,59,59,87,86,59,76,80,59,59,59,59,59,57,50,40,32,30,95,247,355,247,32,0,43,59,59,59,59,59,59,
                                59,59,66,75,84,94,102,107,108,105,97,88,78,69,59,50,59,65,64,59,59,74,75,75,59,59,59,59,59,29,40,76,59,62,64,65,63,59,59};
                      
int heartbeat[80] = {59,59,59,59,59,59,59,59,59,59,59,59,59,87,95,97,96,85,59,59,59,59,59,57,50,40,32,30,95,247,355,247,32,0,43,59,59,59,59,59,59,
                      59,59,66,75,84,94,102,107,108,105,97,88,78,69,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59};
           

volatile int Delay = 14;
volatile int value = 1;

int tiempo1;
int tiempo2;
int tiempo;
int HR;

void NormalV(){
  value = 1;
  Delay = 14;
}
void TachycardiaV(){
  value = 1;
  Delay = 8;
}

void BradycardiaV(){
  value = 1;
  Delay = 33;
}

void AtrialF(){
  value = 2;
}

void atrialF(){
  for(int a=0;a<80;a++){
    Serial.println((atrial_fibrillation[a]/0.2)-295);
    delay(8);
    if(atrial_fibrillation [a] == 355){
      tone(buzzer, melody , 8);
      digitalWrite(ledPinR,HIGH);
      delay(8);
      digitalWrite(ledPinR,LOW);
    }
  }
}

void ECG(int f){
  for(int i=0;i<80;i++){
    Serial.println((heartbeat[i]/0.2)-295);
    delay(f);
    if (heartbeat[i] == 30){
      tiempo1 = millis();
    }
    if (heartbeat [i]== 0){
      tiempo2 = millis();
    }
    if(heartbeat [i] == 355){
      tone(buzzer, melody , f);
      digitalWrite(ledPinR,HIGH);
      delay(f);
      digitalWrite(ledPinR,LOW);
    }
  }
}

void QRSt_HRf(int t1, int t2, int d){
  tiempo = t2 - t1;
  lcd.clear();

  lcd.setCursor(2,0);
  lcd.print("QRS time:");
  lcd.print(tiempo);
  lcd.print("ms");

  HR = 1000/d;

  lcd.setCursor(2,1);
  lcd.print("HR:");
  lcd.print(HR);
  lcd.print("bps");
    
  delay(3);
}
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(ledPinR, OUTPUT);
  
  enableInterrupt(ELEVEN,NormalV,RISING);
  enableInterrupt(TWELVE,TachycardiaV,RISING); 
  enableInterrupt(THIRTEEN,BradycardiaV,RISING);
  enableInterrupt(EIGHT, AtrialF, RISING);
}
void loop() {
  if(value == 1){
    digitalWrite(ledPinR,LOW);
    ECG(Delay);
    QRSt_HRf(tiempo1,tiempo2,Delay);
  }
  if(value == 2){
    lcd.clear();
    atrialF();
  }
}
