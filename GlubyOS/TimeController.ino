time_t checkTime(){
  time_t now = time(nullptr);
  Serial.print("Waiting for NTP time sync: ");
  
  while (now < 57600) {
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("");
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  Serial.println("Current time: ");
  Serial.println(now);
  //Serial.println(asctime(&timeinfo));
  return now;
}

time_t convertToTime(String calTimestamp) {
  struct tm tm;
  Serial.println("Parsing " + calTimestamp);
  String year = calTimestamp.substring(0, 4);
  String month = calTimestamp.substring(4, 6);
  if (month.startsWith("0")) {
    month = month.substring(1);
  }
  String day = calTimestamp.substring(6, 8);
  if (day.startsWith("0")) {
    month = day.substring(1);
  }
  tm.tm_year = year.toInt() - 1900;
  tm.tm_mon = month.toInt() - 1;
  tm.tm_mday = day.toInt();
  tm.tm_hour = calTimestamp.substring(9, 11).toInt();
  tm.tm_min = calTimestamp.substring(11, 13).toInt();
  tm.tm_sec = calTimestamp.substring(13, 15).toInt();
  return mktime(&tm);
}
