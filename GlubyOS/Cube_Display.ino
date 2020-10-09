#if DEVICE == CUBE

  void showState(statesEnum state){
    logDebug("Change state");
     if(state == OFF){
      box("off");
    } else if(state == BOOT){
      box("purple");
    }else if(state == CONNECTED){
      box("green");
    } else if( state == ACCESSPOINT){
      box("yellow");
    } else if(state == READ){
      box("blue");
    } else if(state == SLEEP){
      fourDots("off");
    } else if(state == FAILURE){
      cross("red");
    } else if(state == WARNING){
      box("orange");
    }
  }
  
  void showCurrentBG(float bg, String arrow) {
    if(bg < urgentLow) {
      setArrowWithColor(arrow, "red");
    }else if(bg < warningLow) {
      setArrowWithColor(arrow, "orange");
    } else if(bg < warningHigh) {
      setArrowWithColor(arrow, "green");
    } else if(bg < urgentHigh) {
      setArrowWithColor(arrow, "yellow");
    } else {
      setArrowWithColor(arrow, "purple");
    }
  }

  void showTimeSince(int timeSince){
    if(timeSince > staleDataError){
      showState(FAILURE);
    }else if(timeSince > staleDataWarning){
      showState(WARNING);
    }
  }

  //private
  void setArrowWithColor(String character, String color){
    Serial.print("setArrowWithColor : ");
    Serial.print(character);
    Serial.print(" - ");
    Serial.println(color);
    Serial.println("==========");
    
    if( character.indexOf("TripleDown") > 0){
      tripleArrowDown(color);
    } else if( character.indexOf("DoubleDown") > 0){
      doubleArrowDown(color);
    } else if( character.indexOf("SingleDown") > 0){
      singleArrowDown(color);
    } else if( character.indexOf("SingleUp") > 0){
      singleArrowUp(color);
    } else if( character.indexOf("DoubleUp") > 0){
      doubleArrowUp(color);
    } else if( character.indexOf("TripleDown") > 0){
      tripleArrowUp(color);
    } else {
      flatLine(color);
    }
  }
  
  String x = "";
  void p(int pix, String color){
    uint8_t r; uint8_t g; uint8_t b;
    
    if(color == "red"){
      r = 0xFF; g = 0x00; b = 0x00;
    } else if(color == "green"){
      r = 0x00; g = 0xFF; b = 0x00;
    } else if(color == "blue"){
      r = 0x00; g = 0x00; b = 0xFF;
    } else if(color == "white"){
      r = 0xFF; g = 0xFF; b = 0xFF;
    } else if(color == "yellow"){
      r = 0xFF; g = 0xD0; b = 0x00;
    } else if(color == "orange"){
      r = 0xFF; g = 0x77; b = 0x00;
    } else if(color == "purple"){
      r = 0xFF; g = 0x00; b = 0xEE;
    } else {
      r = 0x00; g = 0x00; b = 0x00;
    }
  
    DisBuff[2 + pix * 3 + 0] = r;
    DisBuff[2 + pix * 3 + 1] = g;
    DisBuff[2 + pix * 3 + 2] = b;
  }


  void fill(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, c); p(15, c); p(10, c); p(5, c); p(0, c); 
    p(21, c); p(16, c); p(11, c); p(6, c); p(1, c); 
    p(22, c); p(17, c); p(12, c); p(7, c); p(2, c); 
    p(23, c); p(18, c); p(13, c); p(8, c); p(3, c); 
    p(24, c); p(19, c); p(14, c); p(9, c); p(4, c); 
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void tripleArrowUp(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, x); p(15, x); p(10, x); p(5, x); p(0, x); 
    p(21, x); p(16, x); p(11, c); p(6, x); p(1, x); 
    p(22, x); p(17, c); p(12, c); p(7, c); p(2, x); 
    p(23, c); p(18, c); p(13, c); p(8, c); p(3, c); 
    p(24, c); p(19, c); p(14, c); p(9, c); p(4, c);
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void doubleArrowUp(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, x); p(15, x); p(10, x); p(5, x); p(0, x); 
    p(21, x); p(16, x); p(11, c); p(6, x); p(1, x); 
    p(22, x); p(17, c); p(12, c); p(7, c); p(2, x); 
    p(23, c); p(18, c); p(13, x); p(8, c); p(3, c); 
    p(24, c); p(19, x); p(14, x); p(9, x); p(4, c);  
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void singleArrowUp(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, x); p(15, x); p(10, x); p(5, x); p(0, x); 
    p(21, x); p(16, x); p(11, c); p(6, x); p(1, x); 
    p(22, x); p(17, c); p(12, x); p(7, c); p(2, x); 
    p(23, c); p(18, x); p(13, x); p(8, x); p(3, c); 
    p(24, x); p(19, x); p(14, x); p(9, x); p(4, x); 
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void flatLine(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, x); p(15, x); p(10, x); p(5, x); p(0, x); 
    p(21, x); p(16, x); p(11, x); p(6, x); p(1, x); 
    p(22, c); p(17, c); p(12, c); p(7, c); p(2, c); 
    p(23, x); p(18, x); p(13, x); p(8, x); p(3, x); 
    p(24, x); p(19, x); p(14, x); p(9, x); p(4, x); 
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void singleArrowDown(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, x); p(15, x); p(10, x); p(5, x); p(0, x); 
    p(21, c); p(16, x); p(11, x); p(6, x); p(1, c); 
    p(22, x); p(17, c); p(12, x); p(7, c); p(2, x); 
    p(23, x); p(18, x); p(13, c); p(8, x); p(3, x); 
    p(24, x); p(19, x); p(14, x); p(9, x); p(4, x); 
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void doubleArrowDown(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, c); p(15, x); p(10, x); p(5, x); p(0, c); 
    p(21, c); p(16, c); p(11, x); p(6, c); p(1, c); 
    p(22, x); p(17, c); p(12, c); p(7, c); p(2, x); 
    p(23, x); p(18, x); p(13, c); p(8, x); p(3, x); 
    p(24, x); p(19, x); p(14, x); p(9, x); p(4, x);  
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void tripleArrowDown(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, c); p(15, c); p(10, c); p(5, c); p(0, c); 
    p(21, c); p(16, c); p(11, c); p(6, c); p(1, c); 
    p(22, x); p(17, c); p(12, c); p(7, c); p(2, x); 
    p(23, x); p(18, x); p(13, c); p(8, x); p(3, x); 
    p(24, x); p(19, x); p(14, x); p(9, x); p(4, x);  
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void topDot(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, c); p(15, c); 
    p(21, c); p(16, c);
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void fourDots(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, c); p(0, c); 
    p(24, c); p(4, c);
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void box(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, c); p(15, c); p(10, c); p(5, c); p(0, c); 
    p(21, c); p(1, c); 
    p(22, c); p(2, c); 
    p(23, c); p(3, c); 
    p(24, c); p(19, c); p(14, c); p(9, c); p(4, c); 
  
     M5.dis.displaybuff(DisBuff);
  }
  
  void cross(String c)
  {
    DisBuff[0] = 0x05; DisBuff[1] = 0x05;
  
    p(20, c); p(0, c); 
    p(16, c); p(6, c); 
    p(12, c);
    p(18, c); p(8, c);
    p(24, c); p(4, c); 
  
     M5.dis.displaybuff(DisBuff);
  }
#endif
