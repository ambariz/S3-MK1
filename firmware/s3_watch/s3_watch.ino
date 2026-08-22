#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA D2
#define OLED_SCL D1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

float temperature = 27.4;
float humidity = 61.0;
int lightLevel = 184;

bool motionDetected = false;
bool vibrationDetected = false;


int currentScreen = 0;

unsigned long lastScreenChange = 0;

const unsigned long SCREEN_INTERVAL = 3000;

void showWelcomeScreen() 
{

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(25, 20);
  display.println("WELCOME");

  display.display();
}

void showBootScreen() 
{

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(28, 8);
  display.println("S3-MK1");

  display.setTextSize(1);

  display.setCursor(48, 32);
  display.println("WATCH");

  display.setCursor(28, 48);
  display.println("Initializing...");

  display.display();
}

void updateFakeValues() 
{

  temperature += random(-3, 4) * 0.1;

  humidity += random(-5, 6) * 0.1;

  lightLevel += random(-15, 16);

  if (lightLevel < 0)
    lightLevel = 0;

  if (lightLevel > 1023)
    lightLevel = 1023;

  motionDetected = random(0, 10) > 7;

  vibrationDetected = random(0, 10) > 8;
}

void showStatusScreen() 
{

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("Cube Connected");

  display.setCursor(0, 15);
  display.println("Cube Armed");

  display.setCursor(0, 30);
  display.println("Signal -54 dBm");

  display.setCursor(0, 45);
  display.println("Watch Online");

  display.display();
}


void showSensorScreen() 
{

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);

  display.print("Temperature: ");
  display.print(temperature, 1);
  display.println(" C");

  display.setCursor(0, 15);

  display.print("Humidity: ");
  display.print(humidity, 1);
  display.println(" %");

  display.setCursor(0, 30);

  display.print("Light: ");
  display.println(lightLevel);

  display.setCursor(0, 45);

  display.print("Motion: ");

  if (motionDetected)
    display.println("Detected");
  else
    display.println("Clear");

  display.display();
}

void showSystemScreen() 
{

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("S3-MK1 Watch");

  display.setCursor(0, 15);
  display.println("Firmware v0.1.0");

  display.setCursor(0, 30);
  display.println("ESP8266 Online");

  display.setCursor(0, 45);
  display.println("Cube Linked");

  display.display();
}

void setup() 
{

  Serial.begin(115200);

  randomSeed(micros());

  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC,OLED_ADDRESS)) 
{

    Serial.println("OLED failed!");
    while (true);
}

  showWelcomeScreen();

  delay(1500);

  showBootScreen();

  delay(2000);

  updateFakeValues();

  showStatusScreen();

  lastScreenChange = millis();
}

void loop() 
{

  if (millis() - lastScreenChange >= SCREEN_INTERVAL) 
  {

    lastScreenChange = millis();
    currentScreen++;

    if (currentScreen > 2)
      currentScreen = 0;

    updateFakeValues();

    switch (currentScreen) 
    {

      case 0:
        showStatusScreen();
        break;

      case 1:
        showSensorScreen();
        break;

      case 2:
        showSystemScreen();
        break;
    }
  }
}