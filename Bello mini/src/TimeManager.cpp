#include"MemoryManager.h"
#include"TimeManager.h"

DS3232RTC RTC;
String zero;

int Relay_pin=12;
int Manual_pin = 2;
int delay_interval_1=5000;
int delay_interval_2=1000;
byte currentHour = hour();
byte currentMinute = minute();

String nextbell(String next_bell){

  for (byte i = 0; i < 10; i++) {
    if ((period_h[i] < currentHour || (period_h[i] == currentHour && period_m[i] <= currentMinute)) &&
        (period_h[(i + 1) % 10] > currentHour || (period_h[(i + 1) % 10] == currentHour && period_m[(i + 1) % 10] > currentMinute))) {
      // Update next_bell
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
    //    res = "0";
    return "0";
  }
  else {
    //    result  = mn;
    return "";
  }   
}

void bell() {

  // Iterate over periods
  for (byte i = 0; i < 10; i++) {
    // Check if current period's hour and minute match the current time
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
  //
  //  tm.Year = _year - 1970;
  //  tm.Month = _month;
  //  tm.Day = _day;

  t = makeTime (tm);

  RTC.set(t);
  setTime(t);
}
void ring(){
digitalWrite(Relay_pin,HIGH);
delay(delay_interval_1);
digitalWrite(Relay_pin,LOW);
delay(delay_interval_2);
digitalWrite(Relay_pin,HIGH);
delay(delay_interval_1);
digitalWrite(Relay_pin,LOW);
delay(delay_interval_2);
}

void Manual_ring(){
while (digitalRead(Manual_pin)==HIGH)
{
digitalWrite(Relay_pin,HIGH);
Serial.println("manual_ringing");
}
digitalWrite(Relay_pin,LOW);


}
