# date:02/08/2026
# time spent:1.5hr
## description:
I made a blueprint for S3 Mark 1, I researched for features and possibilities which can be built in MK1. I learned about making a blueprint diagram, I'm attaching the image too. In that you can see the diagram for S3 cube and it's controller. The S3 cube will do three S ( Surveillance Security System ) and send it to the controller. Controller will have the display, LEDs, and few buttons for arming and disarming the cube. 

The cube will have the following surveillance features :
- Motion
- Sound
- Vibration
- Angle
- Video (not possible ig)
- Light 
- Temperature
- Humidity
## images:
<img width="708" height="507" alt="image" src="/assets/journal1.jpeg" />

------
# date:02/08/2026
# time spent:0.5hr
## description:
For the features, I searched for the sensors and listed it down in the components.md, placed the components in kicad schematic.

| | | |
|---|---|---|
| **Controller** | ESP8266 D1 Mini | Small and fits perfectly inside the cube |
| **Motion** | HLK-LD2410-AA mmWave Sensor | Motion and presence detection |
| **Vibration** | SW-420 Vibration Sensor | Vibration detection |
| **Angle / Tilt** | MPU6050 | 3-axis accelerometer + 3-axis gyroscope |
| **Light** | LDR | Ambient light detection |
| **Temperature** | DHT11 | Temperature measurement |
| **Humidity** | DHT11 | Humidity measurement |

Footprint is not available for HLK-LD2410-AA, SW-420 , MPU6050, DHT11 in kicad. So I'm making custom footprints for the components.

------
# date:04/08/2026
# time spent:1hr
## description:
Since footprint is not available for HLK-LD2410-AA, SW-420 , MPU6050 in kicad. So I made custom footprints for the missing component's symbol and footprint. 
I searched for the exact component model and pinout, matching it with the datasheet and created custom symbols and footprints.
Now all the components for the circuit is ready and in place.
## images:
<img width="708" height="507" alt="image" src="/assets/journal3.png" />

------
# date:09/08/2026
# time spent:1.5hr
## description:
I connected the components and added footprints but most of the footprints were not there so I created custom footprints for the components and connected them. I added few more symbols for battery, DPDT slide switch, 5050 neopixel led for showing the status, connected them too.
After connecting I started arranging them in pcb editor.
## images:
<img width="708" height="507" alt="image" src="/assets/journal4.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal4.2.png" />

------
