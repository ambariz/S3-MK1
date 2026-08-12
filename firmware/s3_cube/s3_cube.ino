#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <SoftwareSerial.h>

SoftwareSerial ld2410(LD2410_RX, LD2410_TX);

#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

#define MPU_SDA D2
#define MPU_SCL D1

#define LD2410_RX D5
#define LD2410_TX D6

#define VIBRATION_PIN D7

#define DHT_PIN D3

#define LDR_PIN A0

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("------");
  Serial.println("S3-MK1 STARTING!");
  Serial.println("------");

  initGPIO();
}

void initGPIO(){
  pinMode(VIBRATION_PIN, INPUT);
  Serial.println("GPIO Starting");
}

void initMPU6050() {
  Wire.begin(MPU_SDA, MPU_SCL);
  if (!mpu.begin()) 
  {
    Serial.println("MPU6050 is not working!");
  }
  else 
  {
    Serial.println("MPU6050 initialized");
  }
}

void readMPU6050() {
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;

  mpu.getEvent(&accel, &gyro, &temp);

  Serial.print("AX -");
  Serial.print(accel.acceleration.x);
  Serial.print("AY -");
  Serial.print(accel.acceleration.y);
  Serial.print("AZ -");
  Serial.print(accel.acceleration.z);
}

void intiDHT11() {
  dht.begin();
  Serial.println("DHT11 initialized");
}

void readDHT() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) 
  {
    Serial.println("DHT is not working!");
    return;
  }
  Serial.print("T - ");
  Serial.print(temperature);
  Serial.print("H - ");
  Serial.print(humidity);
}

void readLDR() {
  int light = analogRead(LDR_PIN);

  Serial.print("LDR - ");
  Serial.println(light);
}

void initSW420() {
  pinMode(VIBRATION_PIN, INPUT);
  Serial.println("SW-420 initialized");
}

void readSW420() {
  bool vibration = digitalRead(VIBRATION_PIN);
  Serial.print("VIB - ");
  if (vibration)
  {
    Serial.println("DETECTED");
  }
  else
  {
    Serial.println("NONE");
  }
}

void initLD2410() {
  ld2410.begin(256000);
  Serial.println("LD2410 initialized");
}

void readLD2410() {
  while (ld2410.available())
  {
    uint8_t data = id2410.read();

    Serial.print(data, HEX);
    Serial.print(" ");
  }
  Serial.println();
}

void readSensors() {
  readMPU6050();
  readDHT();
  readLDR();
  readSW420();
  readLD2410();
}

void loop() {
  Serial.println("S3-MK1 RUNNING...")
  readSensors();
  delay(500);

}
