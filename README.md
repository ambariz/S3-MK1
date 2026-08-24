# S3 MK-1

A compact Surveillance Security System built around a sensor-equipped cube and a wearable controller.

The S3 Cube monitors its surroundings using multiple sensors for motion, vibration, orientation, light, temperature, humidity, and sound. The data is sent to the S3 Watch, a small wearable controller with an OLED display and physical buttons for monitoring and controlling the cube.

The project includes custom PCBs designed in KiCad, custom component footprints, ESP8266 firmware, and fully 3D-printed enclosures designed in Onshape.

| S3 MK-1 Cube | S3 MK-1 Watch |
|-----------|------------|
| ![S3 Cube](./assets/readme-assets/cube.png) | ![S3 Watch](./assets/readme-assets/watch.png) |

# Features

- Wireless S3 Cube MK-1 to S3 Watch MK-1 communication
- Motion / Presence detection
- Vibration detection
- Tilt / Orientation detection
- Sound detection
- Light detection
- Temperature & Humidity monitoring
- OLED display
- Physical button controls
- Arm / Disarm system
- Status indication
- Custom KiCad PCBs
- Custom KiCad footprints
- ESP8266 firmware
- 3D-printed enclosures
- Weighted self-orienting cube design
- 20mm watch strap support

## CAD

> **Note:**
> S3 Cube MK-1 enclosure is made for rolling in a plain surface. This's the reason the edges are with R10.

| S3 Cube MK-1 | S3 Watch MK-1 |
|------|-------|
| ![S3 Cube](./assets/readme-assets/s3-cube-full-model-view.gif) | ![S3 Watch](./assets/readme-assets/watch1.png) |
| ![S3 Cube](./assets/readme-assets/cube1.png) | ![S3 Watch](./assets/readme-assets/watch2.png) |

## PCB

> **Note:**  
> The S3 Watch PCB is designed with a 20mm strap support, If you are 3D printing the enclosure for the watch, Feel free to break it with pliers.

| S3 MK-1 Cube PCB | S3 MK-1 Watch PCB |
|-----------|------------|
| ![Cube PCB](./assets/readme-assets/cube%20pcb.png) | ![Watch PCB](./assets/readme-assets/watch%20pcb.png) |
| ![Cube PCB](./assets/readme-assets/cube.png) | ![Watch PCB](./assets/readme-assets/watch.png) |

## Schematic

> **Note:**  
> The preview images may be scaled down and lose detail. Use the journal.md for a clear, full-resolution view.

| S3 MK-1 Cube | S3 MK-1 Watch |
|-----------|------------|
| ![Cube PCB](./assets/readme-assets/cube_sch.png) | ![Watch PCB](./assets/readme-assets/watch_sch.png) |

## BOM

| Product | Quantity | Source | Price (INR) | Link |
| :--- | :--- | :--- | :--- | :--- |
| D1 Mini ESP8266 | 2 | Robu | 199 | [Product Link](https://robu.in/product/d1-mini-v2-nodemcu-4m-bytes-lua-wifi-internet-of-things-development-board-based-esp8266/) |
| mmWave Sensor HLK-LD2410-AA | 1 | Robu | 639 | [Product Link](https://robu.in/product/hi-link-hlk-ld2410s/) |
| SW-420 Vibration Sensor Module | 1 | Robu | 42 | [Product Link](https://robu.in/product/vibration-sensor-module-alarm-motion-sensor-module-vibration-switch-sw-420/) |
| MPU-6050 3-Axis Accelerometer and Gyro Sensor | 1 | Robu | 154 | [Product Link](https://robu.in/product/mpu-6050-gyro-sensor-2-accelerometer/) |
| LDR 5mm | 1 | Robu | 59 | [Product Link](https://robu.in/product/1-month-warranty-1307/) |
| DHT11 | 1 | Robu | 51 | [Product Link](https://robu.in/product/dht11-digital-relative-humidity-temperature-sensor-module/) |
| LiPo Battery | 2 | Robu | 219 | [Product Link](https://robu.in/product/400mah-pcm-protected-micro-li-po-battery/) |
| Slide Switch | 2 | Robu | 2 | [Product Link](https://robu.in/product/1-month-warranty-255/) |
| Neopixel 5050 | 2 | Robu | 176 | [Product Link](https://robu.in/product/ws2812b-rgb-addressable-led-module/) |
| Buzzer | 2 | Robu | 47 | [Product Link](https://robu.in/product/1-month-warranty-1248/) |
| Tactile Push Button Switch | 4 | Robu | 1.26 | [Product Link](https://robu.in/product/6x6x5mm-tactile-push-button-switch-pack-of-20/) |
| ERM Coin Vibration Motor | 1 | Robu | 77 | [Product Link](https://robu.in/product/erm-coin-vibration-motor-d10mm-w-3-4mm/) |

