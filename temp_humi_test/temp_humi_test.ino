/*!
 * @file  DFRobot_SHT20_test.ino
 * @brief DFRobot's SHT20 Humidity And Temperature Sensor Module
 * @n     This example demonstrates how to read the user registers to display resolution and other settings.
 *        Uses the SHT20 library to display the current humidity and temperature.
 *        Open serial monitor at 9600 baud to see readings.
 *        Errors 998 if not sensor is detected. Error 999 if CRC is bad.
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
       
    //WiFiMulti.addAP("TP-LINK_C5E618", NULL); // no password
    WiFiMulti.addAP("aj-ASUS", "Pakistan1947");


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
