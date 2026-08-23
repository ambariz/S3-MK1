#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA D2
#define OLED_SCL D1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

float temperature = 27.4;
float humidity = 61.0;
int lightLevel = 184;
bool motionDetected = false;
bool vibrationDetected = false;

enum MenuState {MENU_MAIN,MENU_SENSORS,MENU_SYSTEM,MENU_SETTINGS,MENU_ABOUT};

MenuState currentMenu = MENU_MAIN;
int menuSelection = 0;
const int menuItems = 4;
String mainMenuItems[] = {"1. Sensors", "2. System", "3. Settings", "4. About"};

unsigned long lastUpdate = 0;
const unsigned long UPDATE_INTERVAL = 1000;

String serialInput = "";
bool serialMenuActive = true;

void showMainMenu(
{
  display.clearDisplay();
    display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("S3-MK1 MENU");
  
  for (int i = 0; i < menuItems; i++) 
  {
    display.setCursor(0, 12 + (i * 10));
    if (i == menuSelection
{
      display.print("> ");
    } else {
      display.print("  ");
    }
    display.println(mainMenuItems[i]);
  }
  
  display.setTextSize(0);
  display.setCursor(0, 54);
  display.println("Terminal: 1-4 Select");
  
  display.display();
}

void showSensorsMenu(
{
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  display.setCursor(0, 0);
  display.println("=== SENSORS ===");
  
  display.setCursor(0, 12);
  display.print("Temp: ");
  display.print(temperature, 1);
  display.println(" C");
  
  display.setCursor(0, 22);
  display.print("Humidity: ");
  display.print(humidity, 1);
  display.println(" %");
  
  display.setCursor(0, 32);
  display.print("Light: ");
  display.println(lightLevel);
  
  display.setCursor(0, 42);
  display.print("Motion: ");
  display.println(motionDetected ? "DETECTED" : "Clear");
  
  display.setCursor(0, 54);
  display.println("Press 0 for Main Menu");
  
  display.display();
}

void showSystemMenu(
{
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  display.setCursor(0, 0);
  display.println("=== SYSTEM INFO ===");
  
  display.setCursor(0, 12);
  display.println("Device: S3-MK1 Watch");
  
  display.setCursor(0, 22);
  display.println("Firmware: v0.1.0");
  
  display.setCursor(0, 32);
  display.println("Status: Online");
  
  display.setCursor(0, 42);
  display.println("Uptime: ");
  display.print(millis() / 1000);
  display.println("s");
  
  display.setCursor(0, 54);
  display.println("Press 0 for Main Menu");
  
  display.display();
}

void showSettingsMenu(
{
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  display.setCursor(0, 0);
  display.println("=== SETTINGS ===");
  
  display.setCursor(0, 12);
  display.println("1. Update Interval");
  
  display.setCursor(0, 22);
  display.println("2. Brightness");
  
  display.setCursor(0, 32);
  display.println("3. Auto-scroll");
  
  display.setCursor(0, 42);
  display.println("4. Reset Settings");
  
  display.setCursor(0, 54);
  display.println("Press 0 for Main Menu");
  
  display.display();
}

void showAboutMenu(
{
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  display.setCursor(0, 0);
  display.println("=== ABOUT ===");
  
  display.setCursor(0, 12);
  display.println("S3-MK1 Smart Watch");
  
  display.setCursor(0, 22);
  display.println("ESP8266 Based");
  
  display.setCursor(0, 32);
  display.println("OLED 128x64");
  
  display.setCursor(0, 54);
  display.println("Press 0 for Main Menu");
  
  display.display();
}

void updateValues(
{
  temperature += random(-3, 4) * 0.1;
  humidity += random(-5, 6) * 0.1;
  lightLevel += random(-15, 16);
  
  if (lightLevel < 0) lightLevel = 0;
  if (lightLevel > 1023) lightLevel = 1023;
  
  motionDetected = random(0, 10) > 7;
  vibrationDetected = random(0, 10) > 8;
}

void displayWelcomeScreen(
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 20);
  display.println("S3-MK1");
  display.setTextSize(1);
  display.setCursor(40, 40);
  display.println("Initializing...");
  display.display();
  delay(2000);
}

void handleSerialCommands() 
{
  if (Serial.available() > 0
{
    char cmd = Serial.read();
    
    while (Serial.available() > 0
{
      Serial.read();
    }
    
    switch (cmd
{
      case '1':
        menuSelection = 0;
        currentMenu = MENU_SENSORS;
        Serial.println(">> Switching to Sensors Menu");
        break;
        
      case '2':
        menuSelection = 1;
        currentMenu = MENU_SYSTEM;
        Serial.println(">> Switching to System Menu");
        break;
        
      case '3':
        menuSelection = 2;
        currentMenu = MENU_SETTINGS;
        Serial.println(">> Switching to Settings Menu");
        break;
        
      case '4':
        menuSelection = 3;
        currentMenu = MENU_ABOUT;
        Serial.println(">> Switching to About Menu");
        break;
        
      case '0':
        currentMenu = MENU_MAIN;
        Serial.println(">> Returning to Main Menu");
        break;
        
      case 'u':
      case 'U':
        updateValues();
        Serial.println(">> Sensors Updated");
        break;
        
      case 'h':
      case 'H':
        Serial.println("\n=== S3-MK1 COMMANDS ===");
        Serial.println("0 - Main Menu");
        Serial.println("1 - Sensors Menu");
        Serial.println("2 - System Menu");
        Serial.println("3 - Settings Menu");
        Serial.println("4 - About Menu");
        Serial.println("u - Update Sensors");
        Serial.println("h - Show this help");
        Serial.println("========================\n");
        break;
        
      default:
        if (cmd != '\n' && cmd != '\r'
{
          Serial.println("Unknown command. Press 'h' for help.");
        }
        break;
    }
  }
}

void setup(
{
  Serial.begin(115200);
  randomSeed(micros());
  
  Wire.begin(OLED_SDA, OLED_SCL);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)
{
    Serial.println("OLED failed!");
    while (true);
  }
  
  displayWelcomeScreen();
  showMainMenu();
  
  Serial.println("\n\n=== S3-MK1 SMART WATCH ===");
  Serial.println("Serial Menu Interface Active");
  Serial.println("Press 'h' for help");
  Serial.println("============================\n");
}

void loop(
{
  if (millis() - lastUpdate >= UPDATE_INTERVAL
{
    lastUpdate = millis();
    updateValues();
  }
  handleSerialCommands();
  switch (currentMenu
{
    case MENU_MAIN:
      showMainMenu();
      break;
    case MENU_SENSORS:
      showSensorsMenu();
      break;
    case MENU_SYSTEM:
      showSystemMenu();
      break;
    case MENU_SETTINGS:
      showSettingsMenu();
      break;
    case MENU_ABOUT:
      showAboutMenu();
      break;
  }
  delay(100);
}


