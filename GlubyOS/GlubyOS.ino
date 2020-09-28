#include <WiFiManager.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Ticker.h>
#include <WiFi.h>
#include <GxEPD.h>
#include "SPI.h"

// Device definitions
#define ATOM 2
#define CARD 3

// Select active device to build for
#define DEVICE CARD

enum statesEnum { OFF, BOOT, CONNECTED, ACCESSPOINT, READ, SLEEP, FAILURE };

Ticker ticker;
Ticker tickerAlarm;

bool tickState;
bool alarm_on = false;

time_t lastAlarm = time(nullptr);

const char* host = "nightscoutsanne.herokuapp.com";
const int httpsPort = 443;

time_t now = time(nullptr);

WiFiClientSecure client;

void setup()
{
//  pinMode(33, OUTPUT);
//  delay(10);
//  Serial.begin(115200);
//  
//  setupDisplay();
//  
//  showState("BOOTING");
//
//  wifiAPSetup();
//   
//  showState("CONNECTING");
//  connectNightscout();
//  showState("CONNECTED");
//  //lastAlarm = now;
//  refresh();
//  ticker.attach(118, refresh);
}

void refresh(){
 
//  showState("READING");
//
//  now = checkTime();
//  
//  String line = checkNightscout();
//
//  if(line.length() > 0){
//    Serial.println("Start parsing");
//    
//    float mmol = getMMOL(line);
//    String arrow = getArrow(line);
//    int timeSince = getTimeDiff(line);
//  
//    Serial.println("==========");
//
//    displayMmol(mmol);
//
////    setMmolToMatrix(mmol, arrow);
////  
////    setTimeSinceToMatrix(timeSince);
//    showState("ONLINE");
//    } else {
//    showState("ERROR");
//  }
}

void loop()
{

}
