#pragma once
#include<EEPROM.h>
// #include"TimeManager.h"


const int ADDR_PERIOD_H[10] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36};  
const int ADDR_PERIOD_M[10] = {1, 5, 9, 13, 17, 21, 25, 29, 33, 37};  
const int ADDR_END_H[10] = {2, 6, 10, 14, 18, 22, 26, 30, 34, 38};   
const int ADDR_END_M[10] = {3, 7, 11, 15, 19, 23, 27, 31, 35, 39};   


extern int EEPROM_SIZE;
void loadPeriods();
void save();
void loadFromEEPROM(byte schedule[10][4]);
void saveToEEPROM(byte schedule[10][4]);


