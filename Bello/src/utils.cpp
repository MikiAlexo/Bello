#include"utils.h"

void ring(){
digitalWrite(relay_pin,HIGH);
delay(delay_interval_1);
digitalWrite(relay_pin,LOW);
delay(delay_interval_2);
digitalWrite(relay_pin,HIGH);
delay(delay_interval_1);
digitalWrite(relay_pin,LOW);
delay(delay_interval_2);
}

void beep() {
  digitalWrite(beep_pin, HIGH);
  delay(50);
  digitalWrite(beep_pin, LOW);
}

void backbeep() {
  //defining the frequency of the notes
  int E = 330; 
  int G = 392; 
  int C = 262;

  tone(beep_pin, C, 100); 
  delay(150);
  tone(beep_pin, E, 100); 
  delay(150);
  tone(beep_pin, G, 100);
  delay(250);
}

