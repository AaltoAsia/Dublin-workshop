#!/usr/bin/env python3
import requests

while True:
   requests.post("http://localhost:8080", data =
"""<omiEnvelope xmlns="http://www.opengroup.org/xsd/omi/1.0/" version="1.0" ttl="0">
 <write msgformat="odf">
   <msg>
     <Objects xmlns="http://www.opengroup.org/xsd/odf/1.0/">
       <Object>
         <id>MAC-Computer</id>
         <InfoItem name="CPUTemperature">
           <value>""" + input().replace('°C','') + """</value>
         </InfoItem>
       </Object>
     </Objects>
   </msg>
 </write>
</omiEnvelope>""")
