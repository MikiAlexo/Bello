#include <Arduino.h>
#include"input manager.h"
#include"memory manager.h"
#include"display.h"
#include"utils.h"

volatile boolean button_pressed=false;

void ButtonISR() {button_pressed=true;}

void setup() {

  Serial.begin(9600);
  pinMode(relay_pin, OUTPUT);
  pinMode(beep_pin, OUTPUT);
  pinMode(menu_pin, INPUT_PULLUP);
  pinMode(side_pin, INPUT_PULLUP);
  pinMode(enter_pin, INPUT_PULLUP);
  pinMode(down_pin, INPUT_PULLUP);

attachInterrupt(digitalPinToInterrupt(manual_pin),ButtonISR,FALLING);

  // screen initialization
  display.begin(0x3C, true);
  display.clearDisplay();
  display.drawBitmap(0, 0, splashbello_splash_0, 128, 64, SH110X_WHITE); // creative addis logo splash display
  display.display();

 //RTC initialization
  setSyncProvider(RTC.get);
  
 //loading from EEPROM
  EEPROM.begin();
  loadPeriods();


  delay(2000);
  display.clearDisplay();
  backbeep();

}

void loop() {

if(button_pressed){
Manual_ring();
button_pressed=false;
}

 if (menu_pressed()) {
    main_menu = true;
    beep();
  }

  if (!main_menu) {
    mainmenu();
    bell();
  }

  if (main_menu) {
    settings();
    bell();
  }
}

