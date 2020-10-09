#include <WiFiManager.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Ticker.h>
#include <WiFi.h>

// Device definitions
#define DISK 1
#define CUBE 2
#define CARD 3

// Select active device to build for
#define DEVICE CUBE

#if DEVICE == DISK

#elif DEVICE == CUBE
  #include "M5Atom.h"
  uint8_t DisBuff[2 + 5 * 5 * 3];
#elif DEVICE == CARD
  #include <GxEPD.h>
  #include "SPI.h"
  #include <GxGDEH0213B73/GxGDEH0213B73.h>  // 2.13" b/w newer panel
  #include <Fonts/FreeSansBold9pt7b.h>
  #include <Fonts/FreeSansBold12pt7b.h>
  #include <Fonts/FreeSansBold18pt7b.h>
  #include <Fonts/FreeSansBold24pt7b.h>
  #include <GxIO/GxIO_SPI/GxIO_SPI.h>
  #include <GxIO/GxIO.h>
#endif

float errorLow = 0.5;
float urgentLow = 3.5;
float warningLow = 4.0;
float warningHigh = 10.0;
float urgentHigh = 12.0;

float alarmLow = 3.5;
float alarmHigh = 13.5;

int staleDataWarning = 900;
int staleDataError = 1800;

enum statesEnum { OFF, BOOT, CONNECTED, ACCESSPOINT, READ, SLEEP, CALIBRATE, FAILURE, WARNING };

Ticker ticker;
Ticker tickerAlarm;

time_t lastAlarm = time(nullptr);
time_t now = time(nullptr);

WiFiClientSecure client;

void setup()
{
  Serial.begin(115200);
  delay(10);
  
  showState(OFF);
  
  initDevice();

  wifiAPSetup();

  connectNightscout();

  refresh();
  ticker.attach(118, refresh);
}

void refresh(){
 
  showState(READ);

  now = checkTime();
  
  String line = checkNightscout();

  if(line.length() > 0){
    Serial.println("Start parsing");
    
    float bg = getMMOL(line);
    String arrow = getArrow(line);
    int timeSince = getTimeDiff(line);
 
    showCurrentBG(bg, arrow);
    showTimeSince(timeSince);
    alarmForBG(bg);

  } else {
    showState(FAILURE);
  }
}

void loop()
{
  nextLoop();
  delay(50);
}
