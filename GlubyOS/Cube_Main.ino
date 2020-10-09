#if DEVICE == CUBE
 void initDevice(){
    M5.begin(true, false, true);
    pinMode(33, OUTPUT);
    delay(10);
    showState(BOOT);
  }

  void nextLoop(){
    if (M5.Btn.wasPressed())
    {
        alarmOff();
        Serial.println("CLICK");
        refresh();
    }
  
    delay(50);
    M5.update();
  }
#endif
