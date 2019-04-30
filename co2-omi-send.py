#!/usr/bin/python3
import requests
import time
import serial

ser=serial.Serial('/dev/ttyS0', 38400, timeout=1)
while True:
    st=ser.readline()
    #val=st[2:5].strip()
    val=st.decode("utf-8")
    print('sensor value:', val[0:5].strip(), 'ppm')

    requests.post("http://myhost:port", data =
"""<omiEnvelope xmlns="http://www.opengroup.org/xsd/omi/1.0/" version="1.0" ttl="0">
  <write msgformat="odf">
    <msg>
      <Objects xmlns="http://www.opengroup.org/xsd/odf/1.0/">
        <Object>
          <id>CO2-Sensor</id>
          <InfoItem name="co2Value">
            <value>""" + val[0:5].strip() + """</value>
          </InfoItem>
        </Object>
      </Objects>
    </msg>
  </write>
</omiEnvelope>""")
    time.sleep(5)