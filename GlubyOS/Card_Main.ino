#if DEVICE == CARD
  void initDevice(){
    setupDisplay();
    
    showState(BOOT);
  }
#endif
