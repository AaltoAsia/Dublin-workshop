/*
 * Hardware connections:
 *  - S-100 TX line to ESP8266 RX line
 */

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>


ESP8266WiFiMulti WiFiMulti;
HTTPClient http;

void setup()
{
    // Use Receive line to get CO2 sensor values (disconnect to upload this program via USB)
    // Use Transmit line to print log messages via USB connection
    Serial.begin(38400); 
    Serial.println("Setup");
    
    // WiFi Access Point, change or add access points for different WiFi
    WiFiMulti.addAP("TP-LINK_C5E618", NULL); // no password

}

void loop()
{
   
    float co2 = Serial.parseFloat(); // Read co2 value in serial manner
    
    Serial.print("Time:");
    Serial.print(millis());
    Serial.print(" CO2:");
    Serial.print(co2, 1);
    Serial.print("ppm");
    Serial.println();

    if (WiFiMulti.run() == WL_CONNECTED) {
        
      // Check if we got a value yet or not (S-100 sensor has a hard-coded interval)
      if (co2 != 0) { 
          send(http, co2);
      }
      
    } else {
      Serial.println("Not connected to wifi yet");
    }
    
    delay(1000);
}
