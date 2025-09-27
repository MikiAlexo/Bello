#pragma once
#include <SPI.h>
#include <Wire.h>
#include"TimeManager.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C// the curent oled display i have has this address but if this doesn't work try 0X3D
extern Adafruit_SSD1306 ddisplay;

void mainMenu();