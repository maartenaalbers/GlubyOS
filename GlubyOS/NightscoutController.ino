const char* root_ca= \
"-----BEGIN CERTIFICATE-----\n" \
"MIICiTCCAg+gAwIBAgIQH0evqmIAcFBUTAGem2OZKjAKBggqhkjOPQQDAzCBhTEL\n" \
"MAkGA1UEBhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UE\n" \
"BxMHU2FsZm9yZDEaMBgGA1UEChMRQ09NT0RPIENBIExpbWl0ZWQxKzApBgNVBAMT\n" \
"IkNPTU9ETyBFQ0MgQ2VydGlmaWNhdGlvbiBBdXRob3JpdHkwHhcNMDgwMzA2MDAw\n" \
"MDAwWhcNMzgwMTE4MjM1OTU5WjCBhTELMAkGA1UEBhMCR0IxGzAZBgNVBAgTEkdy\n" \
"ZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgGA1UEChMRQ09N\n" \
"T0RPIENBIExpbWl0ZWQxKzApBgNVBAMTIkNPTU9ETyBFQ0MgQ2VydGlmaWNhdGlv\n" \
"biBBdXRob3JpdHkwdjAQBgcqhkjOPQIBBgUrgQQAIgNiAAQDR3svdcmCFYX7deSR\n" \
"FtSrYpn1PlILBs5BAH+X4QokPB0BBO490o0JlwzgdeT6+3eKKvUDYEs2ixYjFq0J\n" \
"cfRK9ChQtP6IHG4/bC8vCVlbpVsLM5niwz2J+Wos77LTBumjQjBAMB0GA1UdDgQW\n" \
"BBR1cacZSBm8nZ3qQUfflMRId5nTeTAOBgNVHQ8BAf8EBAMCAQYwDwYDVR0TAQH/\n" \
"BAUwAwEB/zAKBggqhkjOPQQDAwNoADBlAjEA7wNbeqy3eApyt4jf/7VGFAkK+qDm\n" \
"fQjGGoe9GKhzvSbKYAydzpmfz1wPMOG+FDHqAjAU9JM8SaczepBGR7NjfRObTrdv\n" \
"GDeAU/7dIOA1mjbRxwG55tzd8/8dLDoWV9mSOdY=\n" \
"-----END CERTIFICATE-----\n";

void connectNightscout() {
  configTime(10800, 0, "pool.ntp.org", "time.nist.gov");

  now = checkTime();
}

String checkNightscout(){

  HTTPClient http;
  String payload = "";
 
  http.begin("https://nightscoutsanne.herokuapp.com/api/v1/entries/sgv?count=1&token=api-2b65457a63c7cf92", root_ca);
  int httpCode = http.GET();                                                  
  Serial.print("httpCode = ");
  Serial.println(httpCode);
  if (httpCode > 0) { //Check for the returning code

      payload = http.getString();
      Serial.println(httpCode);
      Serial.println(payload);
    }

  else {
    Serial.println("Error on HTTP request");
  }

  http.end(); //Free the resources

  return payload;
}

float getMMOL(String line){
  Serial.println("==========");
  String gluc = getValue(line, '\u0009', 2);
  Serial.println(gluc);
  int mmdl = gluc.toInt();
  float mmol = (float)mmdl * 0.0555;
  
  Serial.println(mmdl);
  Serial.println("==========");
  Serial.println(mmol);
  Serial.println("==========");
  return mmol;
}

int getTimeDiff(String line) {
  
  String datetime = getValue(line, '\u0009', 1);
  String seconds = getValue(line, '\u0009', 1);
  seconds.remove((seconds.length()-3), (seconds.length()-1));
  int sec = seconds.toInt();
  
  Serial.println("seconds: ");
  Serial.println(datetime);
  Serial.println(sec);

  Serial.println(seconds);
  Serial.println("---");
  Serial.println(now);
  Serial.println("secDiff");
  int secdiff = (now - sec);
  Serial.println(secdiff);
  return secdiff;
}

String getArrow(String line) {
  Serial.println("==========");
  String arrow = getValue(line, '\u0009', 3);
  Serial.println(arrow);
  Serial.println("==========");
  return arrow;
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
