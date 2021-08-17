#include "pitches.h"

int i = 0;
int myNote = 0;

int melody[] = {NOTE_C3,NOTE_D3, NOTE_E3, NOTE_F3};
int pitch1[] = {NOTE_C5};
int pitch2[] = {NOTE_C6};
int duration = 500;

int buzzer = 11;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2),Pitch1,RISING);
  attachInterrupt(digitalPinToInterrupt(3),Pitch2,RISING);
}
void loop(){
  for(i = 0; i < 4; i++) {
    tone(buzzer, melody[i], duration);
    delay(1000);
  }
  noTone(buzzer);
  delay(500);
}
void Pitch1(){
    for(i = 0; i < 1; i++) {
      tone(buzzer, pitch1[i], duration);
    }    
}

void Pitch2(){
    for(i = 0; i < 1; i++) {
      tone(buzzer, pitch2[i], duration);
    }    
}
