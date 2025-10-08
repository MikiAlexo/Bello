#include"display.h"


 String Zero = "";
uint8_t selected = 0;
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


boolean set_bell = false;
boolean main_menu = false;
boolean date_and_time = false;
boolean  help_and_contact = false;

byte hr = 00 , mn = 00, sec = 00, side = 0, period = 1;

void mainmenu() {
  String next_bell = "??:??";
  boolean homee = true;
  while (homee) {
    bell();
    String Zero = ad_O();
    String timee =  "<" + String(hour()) + ":" + zero + String(minute()) + ">" ;
    //    Serial.println(F("MAIN MENU"));
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(32, 10);
    display.println(F("BELLO"));
    //  display.println("");
    display.setTextSize(1);
    display.setCursor(0, 0);//90,0
    display.println(timee);
    display.setCursor(32, 35);
    display.println(F("NEXT |"));
    //  display.println("");
    display.setCursor(32, 45);
    display.println(F("BELL |"));
    //  display.println("");
    display.setCursor(70, 40);
    display.println(nextbell(next_bell));
    //  display.println("");
    display.display();

    if (menu_pressed()) {
      homee = false;
      delay(10);
      beep();

    }
  }
}

void settings() {
  if (down_pressed()) {
 
    selected += 1;
    beep();
  }
  const char *settings[4]PROGMEM = {
    "*Set bell time",
    "*Set time",
    "*Help&contact",
    " <-back "
  };

  if (selected >= 4) {
    selected = 0;
  }
  //  Serial.println(F("SETTINGS"));
  //Serial.println(selected);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(25, 0);
  display.println(F("--SETTINGS--"));
  display.println("");
  delay(50);

  for (byte i = 0; i < 4; i++) {
    if (i == selected) {
      display.setTextColor(SH110X_BLACK, SH110X_WHITE);
      display.println(settings[i]);
      //Serial.println(settings[i]);
    } else if (i != selected) {
      display.setTextColor(SH110X_WHITE);
      display.println(settings[i]);
      //Serial.println(settings[i]);
    }
  }

  display.display();
  if (enter_pressed() && main_menu) {
    if (selected == 3 && !date_and_time) { //back
      main_menu = false;

    }
    if (selected == 2) {//help and contact
      help_and_contact = true;
      main_menu = false;
      while (help_and_contact) {
        help_contact();
        if (menu_pressed() || enter_pressed()) {
          delay(90);
          beep();
          if (menu_pressed() || enter_pressed())
            help_and_contact = false;
        }
      }
    }
    if (selected == 1) {// set date and time
      date_and_time = true;
      main_menu = false;
      byte hr = 00 , mn = 00, sec = 00, side = 0;

      while (date_and_time) {

        //        Serial.println(F("DATE AND TIME"));
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SH110X_WHITE);
        display.setCursor(25, 0);
        display.println(F("--Set time--"));
        //        display.println("");
        display.setTextSize(2);
        display.setTextColor(SH110X_WHITE);
        display.setCursor(15, 32);
        display.print(hr);
        //        display.println("");
        display.setCursor(37, 32);
        display.print(":");
        //        display.println("");
        display.setCursor(45, 32);
        display.print(mn);
        //        display.println("");
        display.setCursor(70, 32);
        display.print(":");
        //        display.println("");
        display.setCursor(80, 32);
        display.println(sec);
        display.setCursor(15 + (side * 30), 40); //eqn for the x axis of the dash
        display.print("_");
        //        display.println("");
        display.display();


        if (side_pressed()) {
          delay(100);
          side++;
          beep();
        }
        if (down_pressed()&& side == 0 ) {
          delay(100);
          hr += 1;

          if (hr > 23) {
            hr = 0;
            beep();
          }
        }
        if (down_pressed()&& side == 1 ) {
          delay(100);
          mn += 1;
          if (mn > 60) {
            mn = 0;
            beep();
          }
        }
        if (down_pressed() && side == 2 ) {
          delay(100);
          sec += 5;
          if (sec > 60) {
            sec = 0;
            beep();
          }
        }
        if (side > 2)
          side = 0;

        if (enter_pressed()) {//back
          beep();
          //dealy(65);
          if (enter_pressed()) {
            setTimeDate(hr, mn, sec);
            main_menu = false;
            date_and_time = false;
          }
        }
        if (menu_pressed()) {
          beep();
          main_menu = true;
          date_and_time = false;
        }
      }
    }
    if (selected == 0) {// set bell
      delay(200);
      //      Serial.println(selected);
      set_bell = true;
      main_menu = false;
      while (set_bell) {
        setbell();

      }
    }
  }
}

void setbell() {

  //  Serial.println(F("bell TIME"));
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(35, 0);
  display.print(F("Period-"));//got rid of two spaces and change position from 25 to 35
  //display.println("");
  display.println(period);
  //  display.println("");
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(30, 32);
  display.print(hr);
  //  display.println("");
  display.setCursor(52, 32);
  display.print(":");
  //  display.println("");
  display.setCursor(74, 32);
  display.print(mn);
  display.setCursor(30 + (side * 44), 40); //eqn for the x axis of the dash
  display.print("_");
  display.display();


  if (side_pressed()) {
    delay(100);
    side++;
    beep();
    // Serial.println(side);
  }
  if (down_pressed() && side == 0 ) {
    delay(100);
    hr += 1;
    //Serial.println(hr);
    if (hr > 23)
      hr = 0;
  }
  if (down_pressed() && side == 1 ) {
    delay(100);
    mn += 1;
    if (mn > 60)
      mn = 0;
  }
  if (side > 1)
    side = 0;

  
  if (enter_pressed()) {
    delay(200);
    if (period >= 1 && period <= 10) {
      switch (period) {
        case 1:
          period_h[0] = hr;
          period_m[0] = mn;
          save(ADDR_PERIOD_1_H, ADDR_PERIOD_1_M, hr, mn);
          break;
        case 2:
          period_h[1] = hr;
          period_m[1] = mn;
          save(ADDR_PERIOD_2_H, ADDR_PERIOD_2_M, hr, mn);

          break;
        case 3:
          period_h[2] = hr;
          period_m[2] = mn;
          save(ADDR_PERIOD_3_H, ADDR_PERIOD_3_M, hr, mn);

          break;
        case 4:
          period_h[3] = hr;
          period_m[3] = mn;
          save(ADDR_PERIOD_4_H, ADDR_PERIOD_4_M, hr, mn);

          break;
        case 5:
          period_h[4] = hr;
          period_m[4] = mn;
          save(ADDR_PERIOD_5_H, ADDR_PERIOD_5_M, hr, mn);
          break;
        case 6:
          period_h[5] = hr;
          period_m[5] = mn;
          save(ADDR_PERIOD_6_H, ADDR_PERIOD_6_M, hr, mn);
          break;
        case 7:
          period_h[6] = hr;
          period_m[6] = mn;
          save(ADDR_PERIOD_7_H, ADDR_PERIOD_7_M, hr, mn);

          break;
        case 8:
          period_h[7] = hr;
          period_m[7] = mn;
          save(ADDR_PERIOD_8_H, ADDR_PERIOD_8_M, hr, mn);

          break;
        case 9:
          period_h[8] = hr;
          period_m[8] = mn;
          save(ADDR_PERIOD_9_H, ADDR_PERIOD_9_M, hr, mn);

          break;
        case 10:
          period_h[9] = hr;
          period_m[9] = mn;
          save(ADDR_PERIOD_10_H, ADDR_PERIOD_10_M, hr, mn);

          break;
      }
      period++;
    }
  }



  if (menu_pressed()) {//back
    delay(65);
    if (menu_pressed()) {
      period++;

    }

  }
}

void help_contact() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(15, 0);
  display.println(F("  HELP&CONTACT"));
  display.setCursor(0, 0);
  display.println("");
  display.println("");
  display.println(F("[No]-0967761090"));
  display.println("");
  display.println(F("[Web]CreativeAdis.com"));
  display.println("");
  //display.println(F("[Mail]-support.CA.com"));
  display.println(F("[BUILD] BL-V1-1.3'"));
  display.display();

}
