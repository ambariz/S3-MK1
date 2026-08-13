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
After connecting I started arranging them in PCB editor.
## images:
<img width="708" height="507" alt="image" src="/assets/journal4.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal4.2.png" />

------
# date:09/08/2026
# time spent:1hr
## description:
I started assembling the footprints in PCB editor for S3 MK-1, drew a PCB of 8x8cm and tried to fit all the components footprint inside the box. The initial plan is to create a enclosure for this PCB,So I added M3 screws since this will be inside a box, and after a lot of movements I reduced the PCB size into 66.5mm X 57mm PCB. Now footprint placement is complete next I will route them one by one.
## images:
<img width="708" height="507" alt="image" src="/assets/journal5.png" />

------
# date:10/08/2026
# time spent:1hr
## description:
I started routing the PCB, Before routing I checked for errors in the circuit with DRC, I got two errors and few warnings, Error: Footprint has malformed courtyard (not a closed shape). I resolved this by correcting the F.courtyard position in the footprint. After solving this issues I started routing the PCB manually, after few revisions I completed the routing (not the best routing but I'm able to connect all the terminal pads) after routing I checked for the errors.. there are no errors, I viewed the pcb in 3D viewer now the PCB is looking very good. Next is the check for few more components I'm thinking of adding.
## images:
<img width="708" height="507" alt="image" src="/assets/journal6.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal6.2.png" />

------
# date:12/08/2026
# time spent:1.5hr
## description:
I wrote firmware for S3 cube, All the components data is now able to sense by the esp8266, this firmware is the initial version which does not include the communication. And while writing the firmware I thought of adding a Audio detection in the S3 cube, so I went back to KiCAD and created a custom symbol (footprint not yet created). And placed it in the circuit and connected it. This audio sensor will help to find noise or sound alerts.

I'm attaching a sample image of firmware I took while writing this! Plese check the repo for full firmware.
## images:
<img width="708" height="507" alt="image" src="/assets/journal7.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal7.2.png" />

------
# date:12/08/2026
# time spent:1.5hr
## description:
I made custom footprint for audio sensor, and reconnected the whole circuit and PCB. I started making the circuit for S3 watch which will communicate with the S3 cube, I wrote down all the ideas, features and components required of the S3 watch. And wrote down all the required measurements for the S3 cube since we'll be needing a CAD for the enclosure for S3 cube. All the components are placed and started connecting it. For footprints I'm using ScottoKiCad repository, I used this repository for blueprint. Next is to complete the connection and creating the PCB of S3 watch.
## images:
<img width="708" height="507" alt="image" src="/assets/journal8.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal8.2.png" />

------