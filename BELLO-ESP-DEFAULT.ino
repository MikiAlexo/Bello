#include <EEPROM.h>
#include <DS3232RTC.h>

#define EEPROM_SIZE 32  // EEPROM size

const byte ADDR_PERIOD_1_H = 0;
const byte ADDR_PERIOD_1_M = 1;
const byte ADDR_PERIOD_2_H = 2;
const byte ADDR_PERIOD_2_M = 3;
const byte ADDR_PERIOD_3_H = 4;
const byte ADDR_PERIOD_3_M = 5;
const byte ADDR_PERIOD_4_H = 6;
const byte ADDR_PERIOD_4_M = 7;
const byte ADDR_PERIOD_5_H = 8;
const byte ADDR_PERIOD_5_M = 9;
const byte ADDR_PERIOD_6_H = 10;
const byte ADDR_PERIOD_6_M = 11;
const byte ADDR_PERIOD_7_H = 12;
const byte ADDR_PERIOD_7_M = 13;
const byte ADDR_PERIOD_8_H = 14;
const byte ADDR_PERIOD_8_M = 15;
const byte ADDR_PERIOD_9_H = 16;
const byte ADDR_PERIOD_9_M = 17;
const byte ADDR_PERIOD_10_H = 18;
const byte ADDR_PERIOD_10_M = 19;
const byte ADDR_PERIOD_11_H = 20;
const byte ADDR_PERIOD_11_M = 21;

static byte period_1_h = 8, period_1_m = 10;
static byte period_2_h = 8, period_2_m = 30;
static byte period_3_h = 9, period_3_m = 15;
static byte period_4_h = 10, period_4_m = 0;
static byte period_5_h = 10, period_5_m = 45;
static byte period_6_h = 11, period_6_m = 30;
static byte period_7_h = 12, period_7_m = 15;
static byte period_8_h = 13, period_8_m = 0;
static byte period_9_h = 14, period_9_m = 0;
static byte period_10_h = 14, period_10_m = 45;
static byte period_11_h = 15, period_11_m = 30;

DS3232RTC RTC;

void setup() {
  Serial.begin(115200);
  
  EEPROM.begin(EEPROM_SIZE); 

  delay(200);

  EEPROM.write(ADDR_PERIOD_1_H, period_1_h);
  EEPROM.write(ADDR_PERIOD_2_H, period_2_h);
  EEPROM.write(ADDR_PERIOD_3_H, period_3_h);
  EEPROM.write(ADDR_PERIOD_4_H, period_4_h);
  EEPROM.write(ADDR_PERIOD_5_H, period_5_h);
  EEPROM.write(ADDR_PERIOD_6_H, period_6_h);
  EEPROM.write(ADDR_PERIOD_7_H, period_7_h);
  EEPROM.write(ADDR_PERIOD_8_H, period_8_h);
  EEPROM.write(ADDR_PERIOD_9_H, period_9_h);
  EEPROM.write(ADDR_PERIOD_10_H, period_10_h);
  EEPROM.write(ADDR_PERIOD_11_H, period_11_h);

  EEPROM.write(ADDR_PERIOD_1_M, period_1_m);
  EEPROM.write(ADDR_PERIOD_2_M, period_2_m);
  EEPROM.write(ADDR_PERIOD_3_M, period_3_m);
  EEPROM.write(ADDR_PERIOD_4_M, period_4_m);
  EEPROM.write(ADDR_PERIOD_5_M, period_5_m);
  EEPROM.write(ADDR_PERIOD_6_M, period_6_m);
  EEPROM.write(ADDR_PERIOD_7_M, period_7_m);
  EEPROM.write(ADDR_PERIOD_8_M, period_8_m);
  EEPROM.write(ADDR_PERIOD_9_M, period_9_m);
  EEPROM.write(ADDR_PERIOD_10_M, period_10_m);
  EEPROM.write(ADDR_PERIOD_11_M, period_11_m);

  EEPROM.commit();
  
  setSyncProvider(RTC.get);
  setTimeDate(8, 0, 00); //--> put the current time here
}

void loop(void) {}

void setTimeDate(byte _hour, byte _minute, byte _second) {
  time_t t;
  tmElements_t tm;

  tm.Hour = _hour;
  tm.Minute = _minute;
  tm.Second = _second;
  t = makeTime(tm);

  RTC.set(t);
  setTime(t);
}

