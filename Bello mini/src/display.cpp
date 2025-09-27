#include"display.h"

Adafruit_SSD1306 ddisplay(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//The mainmenu UI function
void mainMenu(){
 String next_bell = "??:??";
    String zero_ = ad_O();
    String timee =  "<" + String(hour()) + ":" + zero_ + String(minute()) + ">" ;
 
    ddisplay.clearDisplay();
    ddisplay.setTextSize(2);
    ddisplay.setTextColor(SSD1306_WHITE);
    ddisplay.setCursor(32, 10);
    ddisplay.println(F("BELLO"));
 
    ddisplay.setTextSize(1);
    ddisplay.setCursor(0, 0);//90,0
    ddisplay.println(timee);
    ddisplay.setCursor(32, 35);
    ddisplay.println(F("NEXT |"));
    //  display.println("");
    ddisplay.setCursor(32, 45);
    ddisplay.println(F("BELL |"));
    //  display.println("");
    ddisplay.setCursor(70, 40);
    //timee = nextbell();
    ddisplay.println(nextbell(next_bell));

    ddisplay.display();

  
}


