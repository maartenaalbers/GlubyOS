#if DEVICE == CUBE
  void alarmForBG(float bg){
    if((bg < alarmLow && bg > errorLow) || bg > alarmHigh){
      Serial.println("alarm for mmol");
      Serial.print("mmol = ");
      Serial.println(bg);
      Serial.print("last alarm = ");
      Serial.println(lastAlarm);
      Serial.print("now = ");
      Serial.println(now);
      
      if((lastAlarm + (60 * 60)) < now){
        Serial.println("SOUND ALARM");
        alarmOn();
        lastAlarm = now;
      }
    }
  }

  void alarmOn(){
    tickerAlarm.attach(2, alarmSound);
  }
  
  void alarmOff(){
    tickerAlarm.detach();
  }
  
  void alarmSound(){
    Serial.println("Alarm HIGH");
    digitalWrite(33, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(5);                       // wait for a second
    digitalWrite(33, LOW); 
  }
#endif
