Dublin workshop
=======
Tutorial to get familiar with connnecting sensors to O-MI Node the simple way, and introducting subscriptions.


## Scripts

### co2-omi-sent.py: (CO2 sensor with Raspberry Pi)

This script is used to obtain CO2 value through serial interface and send to the O-MI node. Change myhost:post to the address of receiving O-MI node. 
- For RPi 1, the serial port is linked to /dev/serial0  
- For RPi 3, the port is linked to /dev/ttyS0


### ht-omi-sent.py: (Humidity and Temperature Sensor with Raspberry Pi)

This script is used to obtain humidity and temperature value from SHT-20 sensor through I2C interface and send to the O-MI node. 
Change myhost:post to the address of receiving O-MI node.


### omi-write.sh: (1-wire sensor)

This bash script library is used to construct O-MI write requests. 



### create-odf.sh: (structure definition for omi-write.sh)

This script defines the O-DF structure and where to get values. It reads values of Raspberry pi I2C/OneWire sensors.



## Links

* [Gauge visualization source code](https://github.com/AaltoAsia/o-mi-subscription-demo)
* [O-MI Node reference implementation](https://github.com/AaltoAsia/O-MI)

