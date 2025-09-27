#include <Arduino.h>
#include<TimeManager.h>
#include<display.h>

int Relay_pin = 2;

void buttonISR(){

    
}
void setup(){
// pinMode(Relay_pin)
attachInterrupt(Relay_pin,buttonISR,FALLING);
}

void loop(){


}