Dublin workshop
=======
Tutorial to get familiar with connnecting sensors to O-MI Node the simple way, and introducting subscriptions.


## Scripts for Raspberry Pi

### co2-omi-send.py: (CO2 sensor with Raspberry Pi)

This script is used to obtain CO2 value through serial interface and send to the O-MI node. Change myhost:post to the address of receiving O-MI node. 
- For RPi 1, the serial port is linked to /dev/serial0  
- For RPi 3, the port is linked to /dev/ttyS0


### ht-omi-send.py: (Humidity and Temperature Sensor with Raspberry Pi)

This script is used to obtain humidity and temperature value from SHT-20 sensor through I2C interface and send to the O-MI node. 
Change myhost:post to the address of receiving O-MI node.


### omi-write.sh: (1-wire sensor)

This bash script library is used to construct O-MI write requests. 



### create-odf.sh: (structure definition for omi-write.sh)

This script defines the O-DF structure and where to get values. It reads values of Raspberry pi I2C/OneWire sensors.


## Programs for ESP8266

### temp_humi_test

Reads temperature and humidity from SHT-20 sensors and send to a hard-coded O-MI node.


### CO2_test

Reads CO2 from S-100 sensors and send to a hard-coded O-MI node.


## Reading Laptop Temperature

### omi-send-linux.py:

A python script to send O-MI write request.

### omi-send-mac.py:

A python script to remove extra characters and send O-MI write request.


## Links

* [O-MI Node reference implementation](https://github.com/AaltoAsia/O-MI)
* [Gauge visualization source code](https://github.com/AaltoAsia/o-mi-subscription-demo)

