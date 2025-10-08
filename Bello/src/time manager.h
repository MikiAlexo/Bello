#pragma once
#include<DS3232RTC.h>
#include<Arduino.h>
#include"utils.h"

extern DS3232RTC RTC;
extern int Relay_pin;
extern byte currentHour;
extern byte currentMinute;
extern int delay_interval_1;
extern int delay_interval_2;
extern String zero;


void bell();
String ad_O();
String nextbell (String next_bell);
void setTimeDate (byte _hour, byte _minute, byte _second);