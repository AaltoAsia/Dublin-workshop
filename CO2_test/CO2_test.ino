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

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>


ESP8266WiFiMulti WiFiMulti;
HTTPClient http;

void setup()
{
    Serial.begin(38400);
    Serial.println("Setup");
       
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
      if (co2 != 0) {
          send(http, co2);
      }
      
    } else {
      Serial.println("Not connected to wifi yet");
    }
    
    delay(1000);
}
