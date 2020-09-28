#if DEVICE == CARD
 
  #define SPI_MOSI 23
  #define SPI_MISO -1
  #define SPI_CLK 18
  
  #define ELINK_SS 5
  #define ELINK_BUSY 4
  #define ELINK_RESET 16
  #define ELINK_DC 17
  
  String state = "";
  String value = "-.--";
  
  int bmpWidth = 150, bmpHeight = 39;
  
  GxIO_Class io(SPI, /*CS=5*/ ELINK_SS, /*DC=*/ ELINK_DC, /*RST=*/ ELINK_RESET);
  GxEPD_Class display(io, /*RST=*/ ELINK_RESET, /*BUSY=*/ ELINK_BUSY);
  
  SPIClass sdSPI(VSPI);
  int startX = 40, startY = 10;
  
  void setupDisplay(){
    SPI.begin(SPI_CLK, SPI_MISO, SPI_MOSI, ELINK_SS);
    display.init(); // enable diagnostic output on Serial
  
    display.setRotation(1);
    display.fillScreen(GxEPD_WHITE);
    display.update();
  }
  
 void showState(statesEnum stateEnum){
    state = "TEST"; 
    updateScreen();
  }
 
 void showCurrentBG(float bg) {
  value = String(bg);
  updateScreen();
  }
  
  void updateScreen() {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
  
    display.setCursor((display.width()  - display.width() / 2)-35, display.height() - 15);
    display.setFont(&FreeSansBold9pt7b);
    display.println(state);
    
    display.setCursor((display.width()  - display.width()), display.height() - 55);
    display.setFont(&FreeSansBold24pt7b);
    display.println(value);
  
    display.update();
  }
#endif
