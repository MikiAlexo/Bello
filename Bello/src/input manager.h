#pragma once
#include<Arduino.h>
#include"time manager.h"

const byte relay_pin PROGMEM = 12;
const byte menu_pin PROGMEM = 11;
const byte side_pin PROGMEM = 10;
const byte enter_pin PROGMEM = 9;
const byte down_pin PROGMEM = 8;
const byte manual_pin PROGMEM = 2;

extern uint8_t selected;


extern boolean set_bell;
extern boolean main_menu;
extern boolean date_and_time;
extern boolean  help_and_contact;

void Manual_ring();
bool menu_pressed();
bool down_pressed();
bool side_pressed();
bool enter_pressed();
