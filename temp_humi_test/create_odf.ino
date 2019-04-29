
//#define OMI_URL "https://biotope.cs.hut.fi/omi/node/"
#define OMI_URL "http://192.168.1.103:8080/"

const char writeTemplate[] = 
"<omiEnvelope xmlns=\"http://www.opengroup.org/xsd/omi/1.0/\" version=\"1.0\" ttl=\"20\">"
  "<write msgformat=\"odf\">"
    "<msg>"
      "<Objects xmlns=\"http://www.opengroup.org/xsd/odf/1.0/\">"
        "<Object>"
          "<id>SHT20</id>"
          "<InfoItem name=\"Temperature\">"
            "<value>%f</value>"
          "</InfoItem>"
            "<InfoItem name=\"Humidity\">"
            "<value>%f</value>"
          "</InfoItem>"
        "</Object>"
      "</Objects>"
    "</msg>"
  "</write>"
"</omiEnvelope>";

char omiBuffer[1024];

void send(HTTPClient& http, float temperature, float humidity) {
  Serial.println("Connecting to http server");
  
  http.begin(OMI_URL);
  int httpCode = 0;

  sprintf(omiBuffer, writeTemplate, temperature, humidity);
  
  // start connection and send HTTP header
  httpCode = http.POST((uint8_t*)omiBuffer, strlen(omiBuffer));

  Serial.print("Sent, status code: ");
  Serial.println(httpCode);
  String payload = http.getString();
  Serial.println(payload);
  http.end();
}
