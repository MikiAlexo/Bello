#include"MemoryManager.h"

byte period_h[10];
byte period_m[10];



void loadPeriods() {
  EEPROM.get(ADDR_PERIOD_1_H, period_h[0]);
  EEPROM.get(ADDR_PERIOD_1_M, period_m[0]);
  EEPROM.get(ADDR_PERIOD_2_H, period_h[1]);
  EEPROM.get(ADDR_PERIOD_2_M, period_m[1]);
  EEPROM.get(ADDR_PERIOD_3_H, period_h[2]);
  EEPROM.get(ADDR_PERIOD_3_M, period_m[2]);
  EEPROM.get(ADDR_PERIOD_4_H, period_h[3]);
  EEPROM.get(ADDR_PERIOD_4_M, period_m[3]);
  EEPROM.get(ADDR_PERIOD_5_H, period_h[4]);
  EEPROM.get(ADDR_PERIOD_5_M, period_m[4]);
  EEPROM.get(ADDR_PERIOD_6_H, period_h[5]);
  EEPROM.get(ADDR_PERIOD_6_M, period_m[5]);
  EEPROM.get(ADDR_PERIOD_7_H, period_h[6]);
  EEPROM.get(ADDR_PERIOD_7_M, period_m[6]);
  EEPROM.get(ADDR_PERIOD_8_H, period_h[7]);
  EEPROM.get(ADDR_PERIOD_8_M, period_m[7]);
  EEPROM.get(ADDR_PERIOD_9_H, period_h[8]);
  EEPROM.get(ADDR_PERIOD_9_M, period_m[8]);
  EEPROM.get(ADDR_PERIOD_10_H, period_h[9]);
  EEPROM.get(ADDR_PERIOD_10_M, period_m[9]);


}

