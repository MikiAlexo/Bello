#include"Network.h"

WebServer server(80);
int bell =2;


void handleRoot() {
    File file = SPIFFS.open("/index.html", "r");
    if (!file) {
        server.send(500, "text/plain", "Failed to open file");
        return;
    }
    server.streamFile(file, "text/html");
    file.close();
}


void handleSchedule() {
    StaticJsonDocument<512> doc;
    JsonArray periods = doc.createNestedArray("periods");

    byte schedule[10][4];  // [StartHour, StartMinute, EndHour, EndMinute]
    loadFromEEPROM(schedule);

    for (int i = 0; i < 10; i++) {
        JsonObject period = periods.createNestedObject();
       
        char startTime[6];
        snprintf(startTime, sizeof(startTime), "%02d:%02d", schedule[i][0], schedule[i][1]);

        char endTime[6];
        snprintf(endTime, sizeof(endTime), "%02d:%02d", schedule[i][2], schedule[i][3]);

        period["start"] = String(startTime);
        period["end"] = String(endTime);
    }

    String response;
    serializeJson(doc, response);
    
    Serial.print("JSON Response: ");
    Serial.println(response);  // Debugging

    server.send(200, "application/json", response);
}


// Handle the update and save to EEPROM
void handleUpdate() {
    if (server.hasArg("plain")) {
        StaticJsonDocument<512> doc;
        deserializeJson(doc, server.arg("plain"));

        JsonArray periods = doc["periods"];
        byte newSchedule[10][4]; //{[SH,EH],[SM,EM]}

        for (int i = 0; i < 10; i++) {
            const char* startTime = periods[i]["start"];
            const char* endTime = periods[i]["end"];

            int startHour, startMinute, endHour, endMinute;
            sscanf(startTime, "%d:%d", &startHour, &startMinute);
            sscanf(endTime, "%d:%d", &endHour, &endMinute);

            newSchedule[i][0] = startHour;   
            newSchedule[i][1] = startMinute; 
            newSchedule[i][2] = endHour;     
            newSchedule[i][3] = endMinute;   
        }

        saveToEEPROM(newSchedule);
        server.send(200, "text/plain", "OK");
    }
}

void handleExportCSV() {
    String csvData = "Period,Start Time,End Time\n";

    byte schedule[10][4];  
    loadFromEEPROM(schedule);  

    for (int i = 0; i < 10; i++) {
        char startTime[6], endTime[6];
        snprintf(startTime, sizeof(startTime), "%02d:%02d", schedule[i][0], schedule[i][1]);
        snprintf(endTime, sizeof(endTime), "%02d:%02d", schedule[i][2], schedule[i][3]);

        csvData += String(i + 1) + "," + startTime + "," + endTime + "\n";
    }

    server.sendHeader("Content-Disposition", "attachment; filename=schedule.csv");
    server.send(200, "text/csv", csvData);
}


void ring(){
digitalWrite(bell,HIGH);
delay(1000);
digitalWrite(bell,LOW);
delay(400);
digitalWrite(bell,HIGH);
delay(1000);
digitalWrite(bell,LOW);
delay(400);
digitalWrite(bell,HIGH);
delay(1000);
digitalWrite(bell,LOW);
delay(400);
}
void handleRing() {
    ring();
    server.send(200, "application/json", "{\"status\": \"ringing\"}");
}









// Helper function to read schedule from EEPROM
// String getScheduleFromEEPROM(int index) {
//   String period = "";
//   int start = index * 4;  // Each period takes 4 bytes (hour + minute)
//   for (int i = 0; i < 4; i++) {
//     period += char(EEPROM.read(start + i));
//   }
//   return period;
// }

// // Helper function to save schedule to EEPROM
// void saveScheduleToEEPROM(int index, String period) {
//   int start = index * 4;
//   for (int i = 0; i < 4; i++) {
//     EEPROM.write(start + i, period[i]);
//   }
//   EEPROM.commit();
// }






// old
/*
void handleRoot() {
  File file = SPIFFS.open("/index.html", "r");
  if (!file) {
    server.send(500, "text/plain", "File not found");
    return;
  }
  server.streamFile(file, "text/html");
  file.close();
}


*/
