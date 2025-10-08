#pragma once
#include<Arduino.h>
#include"time manager.h"
#include"input manager.h"

const  byte beep_pin PROGMEM = 6;

void beep();
void ring();
void backbeep();