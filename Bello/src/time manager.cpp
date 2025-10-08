#include"memory manager.h"
#include"time manager.h"

DS3232RTC RTC;
String zero="";

int Relay_pin=12;
int delay_interval_1=5000;
int delay_interval_2=1000;
byte currentHour = hour();
byte currentMinute = minute();

String nextbell(String next_bell){
  for (byte i = 0; i < 10; i++) {
    // Check if current period is active and update next_bell
    if ((period_h[i] < currentHour || (period_h[i] == currentHour && period_m[i] <= currentMinute)) &&
        (period_h[(i + 1) % 10] > currentHour || (period_h[(i + 1) % 10] == currentHour && period_m[(i + 1) % 10] > currentMinute))) {

      if (byte(period_m[(i + 1) % 10]) < 10)
        zero = "0";
      else if (period_m[(i + 1) % 10] >= 10)
        zero = "";
      next_bell = String(period_h[(i + 1) % 10]) + ":" + zero + String(period_m[(i + 1)]);
      return next_bell;
    }
  }

  if (period_m[0] < 10)
    zero = "0";
  else if (period_m[0] >= 10)
    zero = "";
  // If no active period found, return the start of the first period
  next_bell = String(period_h[0]) + ":" + zero + String(period_m[0]); 




return next_bell;
}

String ad_O(){
 if (minute() < 10) {
    return "0";
  }
  else {
    return "";
  }   
}

void bell() {
 
  for (byte i = 0; i < 10; i++) {
    if (period_h[i] == currentHour && period_m[i] == currentMinute) {
      Serial.println("ringing");
      ring();
      return;
    }
  }
  //ring for the last period**works only if the period is 15:30
  if (currentHour > period_h[10] && currentMinute < period_m[10]) {
    Serial.println("ringing");
    ring();
    return;
  }

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

