#pragma once
#include<DS3232RTC.h>
#include<Arduino.h>

extern DS3232RTC RTC;
extern int Relay_pin;
extern int Manual_pin;
extern byte currentHour;
extern byte currentMinute;
extern int delay_interval_1;
extern int delay_interval_2;
extern String zero;


void bell();
void ring();
String ad_O();
void Manual_ring();
String nextbell (String next_bell);
void setTimeDate (byte _hour, byte _minute, byte _second);