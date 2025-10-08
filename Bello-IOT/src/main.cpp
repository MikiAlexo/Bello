#include <Arduino.h>
#include "SPIFFS.h"
#include"Network.h"
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <Wire.h>
#include <esp_sleep.h>

const char* ssid = "BELLO";
const char* password = "12345678";

// Static IP configuration
IPAddress local_IP(192, 168, 1, 100);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void setup() {
    Serial.begin(115200);
  pinMode(bell,OUTPUT);
   
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS Mount Failed");
        return;
    }

    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(local_IP, gateway, subnet);
    
    Serial.print("ESP32 Access Point IP: ");
    Serial.println(WiFi.softAPIP());

    server.on("/", HTTP_GET, handleRoot);
    server.on("/schedule", HTTP_GET, handleSchedule);
    server.on("/update", HTTP_POST, handleUpdate);
    server.on("/ring", HTTP_POST, handleRing);
    server.on("/export", HTTP_GET, handleExportCSV);

    server.begin();
}

void loop() {
    Serial.println("Checking for connected clients...");

    if (WiFi.softAPgetStationNum() > 0) {
        Serial.println("Client detected, Staying awake...");
        server.handleClient();
    } else {
        Serial.println("No clients. Sleeping for 5 seconds...");
        delay(5000);
    }
}

