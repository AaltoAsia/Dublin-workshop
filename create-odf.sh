#!/bin/bash
#
# Create O-DF tree using "structurally named" variables.
#

Object="OneWireSensor"

OneWireSensor_Object="Sensor1"

Sensor1_InfoItems="Temperature Humidity"

#Sensor1_values="`eval "cat /mnt/1wire/26.0F85CB010000/temperature"` `eval "cat /mnt/1wire/26.0F85CB010000/humidity"`"

Sensor1_values="`eval "cat /mnt/1wire/<sensor-id>/temperature"` `eval "cat /mnt/1wire/<sensor-id>/humidity"`"