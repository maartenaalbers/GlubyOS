#if DEVICE == CUBE
  void initDevice(){
    M5.begin(true, false, true);
    pinMode(33, OUTPUT);
    delay(10);
    showState(BOOT);
  }
#endif
