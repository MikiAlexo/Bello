#pragma once
#include<Arduino.h>
#include<EEPROM.h>
#include <Wire.h>

extern byte period_h[10];
extern byte period_m[10];


 const byte  ADDR_PERIOD_1_H PROGMEM = 0;
 const byte  ADDR_PERIOD_1_M PROGMEM = 1;
 const byte  ADDR_PERIOD_2_H PROGMEM = 2;
 const byte  ADDR_PERIOD_2_M PROGMEM = 3;
 const byte  ADDR_PERIOD_3_H PROGMEM = 4;
 const byte  ADDR_PERIOD_3_M PROGMEM = 5;
 const byte  ADDR_PERIOD_4_H PROGMEM = 6;
 const byte  ADDR_PERIOD_4_M PROGMEM = 7;
 const byte  ADDR_PERIOD_5_H PROGMEM = 8;
 const byte  ADDR_PERIOD_5_M PROGMEM = 9;
 const byte  ADDR_PERIOD_6_H PROGMEM = 10;
 const byte  ADDR_PERIOD_6_M PROGMEM = 11;
 const byte  ADDR_PERIOD_7_H PROGMEM = 12;
 const byte  ADDR_PERIOD_7_M PROGMEM = 13;
 const byte  ADDR_PERIOD_8_H PROGMEM = 14;
 const byte  ADDR_PERIOD_8_M PROGMEM = 15;
 const byte  ADDR_PERIOD_9_H PROGMEM = 16;
 const byte  ADDR_PERIOD_9_M PROGMEM = 17;
 const byte  ADDR_PERIOD_10_H PROGMEM = 18;
 const byte  ADDR_PERIOD_10_M PROGMEM = 19;







void loadPeriods();
