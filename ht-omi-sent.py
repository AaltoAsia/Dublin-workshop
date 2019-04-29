#!/usr/bin/python3
import requests
from sensor.SHT20 import SHT20
import time

while True:
    # I2C bus=1, Address=0x40
    sht = SHT20(1, 0x40)

    h = sht.humidity()  # read humidity
    #print(h)            # namedtuple
    print('Humidity:', h.RH)         # relative humidity

    t = sht.temperature()  # read temperature
    #print(t)               # namedtuple
    print('Temperature:', t.C)             # Celsius
    print("\n")
    #h, t = sht.all()  # read both at once

    requests.post("http://myhost:port", data =
"""<omiEnvelope xmlns="http://www.opengroup.org/xsd/omi/1.0/" version="1.0" ttl="0">
  <write msgformat="odf">
    <msg>
      <Objects xmlns="http://www.opengroup.org/xsd/odf/1.0/">
        <Object>
          <id>SHT20-Sensor</id>
          <InfoItem name="Humidity">
            <value>""" + str(h.RH) + """</value>
          </InfoItem>
          <InfoItem name="Temperature">
            <value>""" + str(t.C) + """</value>
          </InfoItem>
        </Object>
      </Objects>
    </msg>
  </write>
</omiEnvelope>""")
    time.sleep(5)