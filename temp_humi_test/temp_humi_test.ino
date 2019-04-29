/*!
 * Hardware Connections:
 * -VCC = 3.3V
 * -GND = GND
 * -SDA = A4 (use inline 330 ohm resistor if your board is 5V)
 * -SCL = A5 (use inline 330 ohm resistor if your board is 5V)
 */

#include <Wire.h>
#include "DFRobot_SHT20.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>


DFRobot_SHT20    sht20;
ESP8266WiFiMulti WiFiMulti;
HTTPClient http;


void setup()
{
    Serial.begin(115200);
    Serial.println("Setup");
       
    WiFiMulti.addAP("TP-LINK_C5E618", NULL); // no password


    sht20.initSHT20();                                  // Init SHT20 Sensor
    delay(100);
    sht20.checkSHT20();                                 // Check SHT20 Sensor
}

void loop()
{
    float humd = sht20.readHumidity();                  // Read Humidity
    float temp = sht20.readTemperature();               // Read Temperature
    Serial.print("Time:");
    Serial.print(millis());
    Serial.print(" Temperature:");
    Serial.print(temp, 1);
    Serial.print("C");
    Serial.print(" Humidity:");
    Serial.print(humd, 1);
    Serial.print("%");
    Serial.println();

    if (WiFiMulti.run() == WL_CONNECTED) {
      send(http, temp, humd);
    } else {
      Serial.println("Not connected to wifi yet");
    }
    
    delay(3000);
}
