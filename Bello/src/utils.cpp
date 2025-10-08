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
  // Define the frequencies for the notes
//   int D = 1174; // D note 294
  int E = 330; 
  int G = 392; 
//   int A = 880; // A note 440
//   int B = 494; 
//   int FSharp = 370; 
//   int CSharp = 277; 
  int C = 262; // C note

  // Play the sequence of notes

  tone(beep_pin, C, 100); // A note
  delay(150);
  tone(beep_pin, E, 100); // D note
  delay(150);
  tone(beep_pin, G, 100); // D note
  delay(250);
}
