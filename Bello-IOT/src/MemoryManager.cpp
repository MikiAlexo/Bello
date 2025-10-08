#include"MemoryManager.h"

int EEPROM_SIZE = 512;

byte period_h[10];
byte period_m[10];


void loadFromEEPROM(byte schedule[10][4]) {
    EEPROM.begin(EEPROM_SIZE);
    for (int i = 0; i < 10; i++) {
        schedule[i][0] = EEPROM.read(ADDR_PERIOD_H[i]);  // Start hour
        schedule[i][1] = EEPROM.read(ADDR_PERIOD_M[i]);  // Start minute
        schedule[i][2] = EEPROM.read(ADDR_END_H[i]);     // End hour
        schedule[i][3] = EEPROM.read(ADDR_END_M[i]);     // End minute
        period_h[i]=schedule[i][0];
        period_m[i]=schedule[i][1];
    }
    EEPROM.end();
}


void saveToEEPROM(byte schedule[10][4]) {  
    EEPROM.begin(EEPROM_SIZE);
    
    for (int i = 0; i < 10; i++) {
        EEPROM.write(ADDR_PERIOD_H[i], schedule[i][0]);  // Start hour
        EEPROM.write(ADDR_PERIOD_M[i], schedule[i][1]);  // Start minute
        EEPROM.write(ADDR_END_H[i], schedule[i][2]);     // End hour
        EEPROM.write(ADDR_END_M[i], schedule[i][3]);     // End minute
    }
    
    EEPROM.commit();
    EEPROM.end();
}

