#include"input manager.h"

int Manual_pin = 2;

void Manual_ring(){
while (digitalRead(Manual_pin)==HIGH)
{
digitalWrite(Relay_pin,HIGH);
Serial.println("manual_ringing");
}
digitalWrite(Relay_pin,LOW);

}

bool menu_pressed(){return digitalRead(menu_pin)==0;}

bool down_pressed(){ return digitalRead(down_pin)==0;}

bool side_pressed(){ return digitalRead(side_pin)==0;}

bool enter_pressed(){ return digitalRead(enter_pin)==0;}

