#pragma once
#define ARDUINOJSON_DEPRECATED(message)

#include <Arduino.h>
#include "SPIFFS.h"
#include <WiFi.h>
#include <WebServer.h>
#include"MemoryManager.h"
#include <ArduinoJson.h>

extern int bell;
extern WebServer server; 
void handleRoot();
void handleSchedule();
void handleUpdate();
void handleRing();
void handleExportCSV();
void ring();

