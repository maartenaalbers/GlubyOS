// Debug == 0, Warn == 5, Error == 10
int logLevel = 0;

void logDebug(String message){
  if (logLevel == 0){
    Serial.println(message);
  }
}

void logWarn(String message){
  if (logLevel <= 5){
    Serial.println("WARN : " + message);
  }
}

void logError(String message){
  Serial.println("ERROR: " + message);  
}
