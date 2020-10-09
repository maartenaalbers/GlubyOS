void configModeCallback (WiFiManager *myWiFiManager) {
  showState(ACCESSPOINT);
  logDebug("Entered AP mode");
  logDebug(WiFi.softAPIP().toString());
  logDebug(myWiFiManager->getConfigPortalSSID());
}

void wifiAPSetup() {
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  WiFiManager wm;

  //reset settings - wipe credentials for testing
  //wm.resetSettings();

  wm.setAPCallback(configModeCallback);

  bool res;
  res = wm.autoConnect("SETUP GLUBY"); // anonymous ap

  if(!res) {
    showState(FAILURE);
    logDebug("Failed to connect");
    ESP.restart();
  } 
  else {
    logDebug("connected...yeey :)");
    showState(CONNECTED);
  }
}
