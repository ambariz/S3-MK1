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

| ---------------- | --------------------------- | ------------------------------------------------------------------------ |
| **Controller**   | ESP8266 D1 Mini             | Small controller that fits perfectly inside the cube                     |
| **Motion**       | HLK-LD2410-AA mmWave Sensor | Detects motion and presence                                              |
| **Vibration**    | SW-420 Vibration Sensor     | Detects vibration and movement                                           |
| **Angle / Tilt** | MPU6050                     | 3-axis accelerometer and 3-axis gyroscope for tilt/orientation detection |
| **Light**        | LDR                         | Detects ambient light intensity                                          |
| **Temperature**  | DHT11                       | Measures temperature                                                     |
| **Humidity**     | DHT11                       | Measures humidity                                                        |

Footprint is not available for HLK-LD2410-AA, SW-420 , MPU6050, DHT11 in kicad. So I'm making custom footprints for the components.

------