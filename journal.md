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
# date:13/08/2026
# time spent:1.5hr
## description:
I made custom footprint for audio sensor, and reconnected the whole circuit and PCB. I started making the circuit for S3 watch which will communicate with the S3 cube, I wrote down all the ideas, features and components required of the S3 watch. And wrote down all the required measurements for the S3 cube since we'll be needing a CAD for the enclosure for S3 cube. All the components are placed and started connecting it. For footprints I'm using ScottoKiCad repository, I used this repository for blueprint. Next is to complete the connection and creating the PCB of S3 watch.
## images:
<img width="708" height="507" alt="image" src="/assets/journal8.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal8.2.png" />

------
# date:13/08/2026
# time spent:2hr
## description:
I created the PCB for S3 watch, initial design was large but after lot of tries and moving the components in right order, I came up with the best possible PCB. Which is small in size (smallest) I'm using D1 mini, I added all the components inside the dimentions of the D1 mini itself. Instead of using regular size components I'm using the mini versions of it, for eg, instead of normal push button I'm using two terminal mini push buttons. 
Next is to complete the PCB, I'm thinking of adding a strap cutout in the pcb itself or I can create a strap mechanism while doing enclosure CAD but I've to think on this :)
## images:
<img width="708" height="507" alt="image" src="/assets/journal9.png" />

------
# date:16/08/2026
# time spent:1hr
## description:
I connected the S3 watch PCB with 2 layers, After few revisions the S3 watch PCB connection is without the errors in DRC, and also researched on watches about how the strap (strap is the part which connected to the watch, band like thing) and I found there are fixed sizes available like 18mm, 20mm, 22mm these are the widely used ones. I went with 20mm because 22mm will be too big for the PCB and 18mm I think this's small and 20mm is in the middle so went with it. and added a 3.5mm space to slide the strap. And I thought of creating two version of the watches one is with the PCB strap and another with the strap in the enclosure (case of the PCB watch). Next is to write firmware for the S3 watch and I will try to test the firmware I wrote :)
## images:
<img width="708" height="507" alt="image" src="/assets/journal10.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal10.2.png" />
<img width="708" height="507" alt="image" src="/assets/journal10.3.png" />

------
# date:17/08/2026
# time spent:1.5hr
## description:
I drew the sketch for the CAD in OnShape, first I measured all the dimentions form the KiCAD PCB, and then drew that in sketch named PCB, and then added drill holes. I created three more sketches one is for innerTop, another is for outerTop. The thickness is 2mm while creating it I came across one issue, if I create a radius of R10 (10mm radius is called R10) so Inner and Outer corner radius is R10 but when i overlap the two sketches in OnShape it's walls are 2mm and then when coming to corners it's getting bit big.. I searched for this issue and found out that ```Outer radius − wall thickness = inner radius``` and it's called inconsistent radius issue.
If my outside is:
70 × 70 × 70 mm
R10 mm
then the inside should be: R9 mm

## images:
<img width="708" height="507" alt="image" src="/assets/journal11.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal11.2.png" />
<img width="708" height="507" alt="image" src="/assets/journal11.3.png" />
<img width="708" height="507" alt="image" src="/assets/journal11.4.png" />
<img width="708" height="507" alt="image" src="/assets/journal11.5.png" />

------
# date:18/08/2026
# time spent:1hr
## description:
I started creating the enclosure for S3 Cubed, yesterday I created the sketch for Extrude with the PCB dimentions. Today I did Extrude but when i try to do it for the top and bottom covers, it should be in cuboid shape with R10 so that if we throw this cube this will roll and land in top facing (always!) (yet to do this mechanism) After few revisions I realised, I can do it with the options which are available in the OnShape itself, so just creating a cube and using those pre built options I can create what i want. Next is to complete the enclosure using those and Start sketching the enclosure for the S3 Watch.

## images:
<img width="708" height="507" alt="image" src="/assets/journal12.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal12.2.png" />

------
# date:18/08/2026
# time spent:1.5hr
## description:
I completed the enclosure of S3 cube. Now I have Base of the cube along with the HEX shaped pillar supports (four of them to support the PCB, we can screw the PCB into this HEX shaped supports), Top cover of the enclosure, we can easily screw and place the top side and also there's inner top side (this inner enclosure is to add weights, I'm thinking of the battery which serves as powersource as well as the wight for the cube). And added all the CAD files in .step .stl and .3mf formats for 3d printing.
Why we need weight in the bottom side of the cube? Because if we throw the cube it should be rolled and the top will come up easily. 

## images:
<img width="708" height="507" alt="image" src="/assets/journal13.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal13.2.png" />
<img width="708" height="507" alt="image" src="/assets/journal13.3.png" />
<img width="708" height="507" alt="image" src="/assets/journal13.4.png" />
<img width="708" height="507" alt="image" src="/assets/journal13.5.png" />
<img width="708" height="507" alt="image" src="/assets/journal13.6.png" />
<img width="500" height="500" alt="image" src="/assets/journal13.7.gif" />

------
# date:19/08/2026
# time spent:1.5hr
## description:
I have two esp8266 and oled, instead of simulating the esp8266 I'm writing the firmware for the S3 watch and testing directly in the hardware I bought for previous projects. The firmware (main.ino i) wrote will show the value from the S3 cube. Currently it has a booting text like UI with shows the initial text But the final one I planned will have the menu like UI. And can be controlled by the push buttons in the PCB itself.
Next is to create a UI which is controlled by the push buttons and also to make a good UI for the S3 watch.

## images:
<img width="708" height="507" alt="image" src="/assets/journal14.1.png" />

------
# date:22/08/2026
# time spent:1.5hr
## description:
After booting text now i'm showing the menu like screen, it's not fully feels like menu but now it's better with a table like UI showing all the data got from the S3 cube. I updated with some formating in the table like UI (you can see in the gif below). Now it's auto showing the various data but in the full version of the code there will be push button navigation where the S3 can be controlled from the S3 watch itself. Next is to upgrade this firmware and to create a CAD for the watch. And I'm also thinking to simulate S3 cube in online, Because I don't have all the required sensors for this.

## images:
<img width="708" height="507" alt="image" src="/assets/journal15.1.png" />
<img width="708" height="507" alt="image" src="/assets/journal15.2.png" />

------