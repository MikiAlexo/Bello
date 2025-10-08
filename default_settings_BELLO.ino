#include <EEPROM.h>
#include <DS3232RTC.h>

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
const byte  ADDR_PERIOD_11_H PROGMEM = 20;
const byte  ADDR_PERIOD_11_M PROGMEM = 21;

static byte period_1_h = 8, period_1_m = 10;
static byte period_2_h = 8, period_2_m = 30;
static byte period_3_h = 9, period_3_m = 15;

static byte period_4_h = 10, period_4_m = 00;

static byte period_5_h = 10, period_5_m = 45;
static byte period_6_h = 11, period_6_m = 30;

static byte period_7_h = 12, period_7_m = 15;

static byte period_8_h = 13, period_8_m = 0;
static byte period_9_h = 14, period_9_m = 0;
static byte period_10_h = 14, period_10_m = 45;
static byte period_11_h = 15, period_11_m = 30;

void setup() {
  // put your setup code here, to run once:
  EEPROM.begin();
  delay(200);
  //hour
  EEPROM.update(ADDR_PERIOD_1_H, period_1_h);
  EEPROM.update(ADDR_PERIOD_2_H, period_2_h);
  EEPROM.update(ADDR_PERIOD_3_H, period_3_h);
  EEPROM.update(ADDR_PERIOD_4_H, period_4_h);
  EEPROM.update(ADDR_PERIOD_5_H, period_5_h);
  EEPROM.update(ADDR_PERIOD_6_H, period_6_h);
  EEPROM.update(ADDR_PERIOD_7_H, period_7_h);
  EEPROM.update(ADDR_PERIOD_8_H, period_8_h);
  EEPROM.update(ADDR_PERIOD_9_H, period_9_h);
  EEPROM.update(ADDR_PERIOD_10_H, period_10_h);
  EEPROM.update(ADDR_PERIOD_11_H, period_11_h);

  //minute
  EEPROM.update(ADDR_PERIOD_1_M, period_1_m);
  EEPROM.update(ADDR_PERIOD_2_M, period_2_m);
  EEPROM.update(ADDR_PERIOD_3_M, period_3_m);
  EEPROM.update(ADDR_PERIOD_4_M, period_4_m);
  EEPROM.update(ADDR_PERIOD_5_M, period_5_m);
  EEPROM.update(ADDR_PERIOD_6_M, period_6_m);
  EEPROM.update(ADDR_PERIOD_7_M, period_7_m);
  EEPROM.update(ADDR_PERIOD_8_M, period_8_m);
  EEPROM.update(ADDR_PERIOD_9_M, period_9_m);
  EEPROM.update(ADDR_PERIOD_10_M, period_10_m);
  EEPROM.update(ADDR_PERIOD_11_M, period_11_m);

  setSyncProvider(RTC.get);
  setTimeDate(8, 0, 00);
}

void loop() {
  // put your main code here, to run repeatedly:
}
void setTimeDate (byte _hour, byte _minute, byte _second) {
  time_t t;
  tmElements_t tm;

  tm.Hour = _hour;
  tm.Minute = _minute;
  tm.Second = _second;
  t = makeTime (tm);

  RTC.set(t);
  setTime(t);
}
