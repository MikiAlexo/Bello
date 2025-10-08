#include <Arduino.h>
#include"display.h"
#include"TimeManager.h"
#include"MemoryManager.h"

#define Buzzer_pin 8

volatile bool buttonPressed = false;
//interupt service routine
void buttonISR() {
    buttonPressed = true; 
}

void setup() {
pinMode(Relay_pin,OUTPUT);
pinMode(Buzzer_pin,OUTPUT);
pinMode(Manual_pin,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(Manual_pin),buttonISR,FALLING);
//initializations
Serial.begin(9600);
RTC.begin();
EEPROM.begin();
delay(500);

//loading the time schedule from EEPROM to RAM
loadPeriods();
//checking if the display is connected properly
if(!ddisplay.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }

  ddisplay.clearDisplay();
  ddisplay.drawPixel(10, 10, SSD1306_WHITE);
  ddisplay.display();
  delay(2000);

setSyncProvider(RTC.get);
//  setTimeDate(8,0,00);


}

void loop() {
//manual ring function implemented using interrupt
if(buttonPressed){
  Serial.println("resetting");
Manual_ring();
buttonPressed=false;
}

mainMenu();
    
bell();
}

