#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA 21
#define OLED_SCL 22
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
String mainMenuItems[] = {"Sensors", "System", "Settings", "About"};

unsigned long lastUpdate = 0;
const unsigned long UPDATE_INTERVAL = 1000;

unsigned long lastBlinkTime = 0;
bool blinkState = false;
const unsigned long BLINK_INTERVAL = 500;

bool inSubMenu = false;

void drawTopBar(const char* title
{
  display.fillRect(0, 0, SCREEN_WIDTH, 10, SSD1306_WHITE);
  display.setTextColor(SSD1306_BLACK);
  display.setTextSize(1);
  display.setCursor(2, 2);
  display.print(title);
  display.drawLine(0, 10, SCREEN_WIDTH, 10, SSD1306_WHITE);
}

void drawBottomBar(const char* text
{
  display.fillRect(0, SCREEN_HEIGHT - 10, SCREEN_WIDTH, 10, SSD1306_WHITE);
  display.setTextColor(SSD1306_BLACK);
  display.setTextSize(0);
  display.setCursor(2, SCREEN_HEIGHT - 8);
  display.print(text);
}

void drawMenuItem(int y, const char* text, bool selected, bool isLast = false
{
  if (selected
{
    display.fillRect(0, y, SCREEN_WIDTH, 10, SSD1306_WHITE);
    display.setTextColor(SSD1306_BLACK);
    
    display.fillTriangle(
      SCREEN_WIDTH - 10, y + 2,
      SCREEN_WIDTH - 4, y + 5,
      SCREEN_WIDTH - 10, y + 8,
      SSD1306_BLACK
    );
  } else {
    display.setTextColor(SSD1306_WHITE);
  }
  
  display.setTextSize(1);
  display.setCursor(4, y + 1);
  display.print(text);
  
  if (!isLast
{
    display.drawLine(0, y + 10, SCREEN_WIDTH, y + 10, SSD1306_WHITE);
  }
}

void showMainMenu(
{
  display.clearDisplay();
  
  drawTopBar("S3-MK1 MENU");
  
  int startY = 14;
  for (int i = 0; i < menuItems; i++
{
    bool isSelected = (i == menuSelection);
    bool isLast = (i == menuItems - 1);
    drawMenuItem(startY + (i * 11), mainMenuItems[i].c_str(), isSelected, isLast);
  }
  
  drawBottomBar("[1] Up  [2] Down  [3] Select");
  display.display();
}

void showSensorsMenu(
{
  display.clearDisplay();
  
  drawTopBar("SENSORS");
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  int yPos = 14;
  
  display.setCursor(4, yPos);
  display.print("Temp:");
  display.setCursor(80, yPos);
  display.print(temperature, 1);
  display.print(" C");
  display.drawLine(0, yPos + 10, SCREEN_WIDTH, yPos + 10, SSD1306_WHITE);
  
  yPos += 12;
  display.setCursor(4, yPos);
  display.print("Humidity:");
  display.setCursor(80, yPos);
  display.print(humidity, 1);
  display.print(" %");
  display.drawLine(0, yPos + 10, SCREEN_WIDTH, yPos + 10, SSD1306_WHITE);
  
  yPos += 12;
  display.setCursor(4, yPos);
  display.print("Light:");
  display.setCursor(80, yPos);
  display.println(lightLevel);
  display.drawLine(0, yPos + 10, SCREEN_WIDTH, yPos + 10, SSD1306_WHITE);
  
  yPos += 12;
  display.setCursor(4, yPos);
  display.print("Motion:");
  display.setCursor(80, yPos);
  if (motionDetected
{
    display.setTextColor(SSD1306_WHITE);
    display.fillRect(75, yPos, 50, 9, SSD1306_WHITE);
    display.setTextColor(SSD1306_BLACK);
    display.print("DETECTED");
    display.setTextColor(SSD1306_WHITE);
  } else {
    display.print("Clear");
  }
  
  drawBottomBar("[0] Back  [u] Update");
  
  display.display();
}

void showSystemMenu(
{
  display.clearDisplay();
  
  drawTopBar("SYSTEM INFO");
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  int yPos = 14;
  
  display.setCursor(4, yPos);
  display.print("Device:");
  display.setCursor(80, yPos);
  display.println("S3-MK1");
  display.drawLine(0, yPos + 10, SCREEN_WIDTH, yPos + 10, SSD1306_WHITE);
  
  yPos += 12;
  display.setCursor(4, yPos);
  display.print("Firmware:");
  display.setCursor(80, yPos);
  display.println("v0.1.0");
  display.drawLine(0, yPos + 10, SCREEN_WIDTH, yPos + 10, SSD1306_WHITE);
  
  yPos += 12;
  display.setCursor(4, yPos);
  display.print("Status:");
  display.setCursor(80, yPos);
  if (blinkState
{
    display.fillRect(75, yPos, 50, 9, SSD1306_WHITE);
    display.setTextColor(SSD1306_BLACK);
    display.print("ONLINE");
    display.setTextColor(SSD1306_WHITE);
  } else {
    display.print("Online");
  }
  display.drawLine(0, yPos + 10, SCREEN_WIDTH, yPos + 10, SSD1306_WHITE);
  
  yPos += 12;
  display.setCursor(4, yPos);
  display.print("Uptime:");
  display.setCursor(80, yPos);
  display.print(millis() / 1000);
  display.println("s");
  
  drawBottomBar("[0] Back");
  
  display.display();
}

void showSettingsMenu(
{
  display.clearDisplay();
  
  drawTopBar("SETTINGS");
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  int yPos = 14;
  
  const char* items[] = {"Update Interval", "Brightness", "Auto-scroll", "Reset Settings"};
  
  for (int i = 0; i < 4; i++
{
    bool isSelected = (i == menuSelection % 4);
    
    if (isSelected
{
      display.fillRect(0, yPos, SCREEN_WIDTH, 10, SSD1306_WHITE);
      display.setTextColor(SSD1306_BLACK);
      display.fillTriangle(
        SCREEN_WIDTH - 10, yPos + 2,
        SCREEN_WIDTH - 4, yPos + 5,
        SCREEN_WIDTH - 10, yPos + 8,
        SSD1306_BLACK
      );
    } else {
      display.setTextColor(SSD1306_WHITE);
    }
    
    display.setCursor(4, yPos + 1);
    display.print(i + 1);
    display.print(". ");
    display.print(items[i]);
    
    display.setTextColor(SSD1306_WHITE);
    display.drawLine(0, yPos + 10, SCREEN_WIDTH, yPos + 10, SSD1306_WHITE);
    
    yPos += 11;
  }
    
  display.display();
}

void showAboutMenu(
{
  display.clearDisplay();
  
  drawTopBar("ABOUT");
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  int yPos = 14;
  
  display.setCursor(20, yPos);
  display.println("S3-MK1");
  
  display.drawLine(0, yPos + 12, SCREEN_WIDTH, yPos + 12, SSD1306_WHITE);
  
  yPos += 16;
  display.setCursor(15, yPos);
  display.println("ESP32 Smart Watch");
  
  yPos += 12;
  display.setCursor(15, yPos);
  display.println("OLED 128x64");
  
  yPos += 12;
  display.setCursor(20, yPos);
  
  display.drawRect(1, 12, SCREEN_WIDTH - 2, 40, SSD1306_WHITE);
  
  
  display.display();
}

void updateFakeValues(
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
  
  for (int i = 0; i < 3; i++
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(15, 20);
    display.println("S3-MK1");
    display.setTextSize(1);
    display.setCursor(40, 40);
    display.print("Loading");
    for (int j = 0; j <= i; j++
{
      display.print(".");
    }
    display.display();
    delay(500);
  }
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 20);
  display.println("S3-MK1");
  display.setTextSize(1);
  display.setCursor(30, 40);
  display.println("Ready!");
  display.display();
  delay(1000);
}

void handleSerialCommands(
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
        if (currentMenu == MENU_MAIN || currentMenu == MENU_SETTINGS
{
          menuSelection--;
          if (menuSelection < 0
{
            menuSelection = (currentMenu == MENU_MAIN) ? menuItems - 1 : 3;
          }
          Serial.print(">> Selection: ");
          Serial.println(menuSelection + 1);
        }
        break;
        
      case '2':
        if (currentMenu == MENU_MAIN || currentMenu == MENU_SETTINGS
{
          menuSelection++;
          if (menuSelection >= ((currentMenu == MENU_MAIN) ? menuItems : 4)
{
            menuSelection = 0;
          }
          Serial.print(">> Selection: ");
          Serial.println(menuSelection + 1);
        }
        break;
        
      case '3':
        if (currentMenu == MENU_MAIN
{
          switch (menuSelection
{
            case 0:
              currentMenu = MENU_SENSORS;
              Serial.println(">> Entering Sensors Menu");
              break;
            case 1:
              currentMenu = MENU_SYSTEM;
              Serial.println(">> Entering System Menu");
              break;
            case 2:
              currentMenu = MENU_SETTINGS;
              menuSelection = 0;
              Serial.println(">> Entering Settings Menu");
              break;
            case 3:
              currentMenu = MENU_ABOUT;
              Serial.println(">> Entering About Menu");
              break;
          }
        }
        break;
        
      case '0':
        if (currentMenu != MENU_MAIN
{
          currentMenu = MENU_MAIN;
          menuSelection = 0;
          Serial.println(">> Returning to Main Menu");
        }
        break;
        
      case 'u':
      case 'U':
        updateFakeValues();
        Serial.println(">> Sensors Updated");
        break;
        
      case 'h':
      case 'H':
        Serial.println("S3-MK1 COMMANDS");
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

void setup() 
{
  Serial.begin(115200);
  randomSeed(micros());
  
  Wire.begin(OLED_SDA, OLED_SCL);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)
{
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  
  display.clearDisplay();
  displayWelcomeScreen();
  showMainMenu();
  
  Serial.println("S3-MK1 SMART WATCH");
  Serial.println("Serial Menu Interface Active");
  Serial.println("Press 'h' for help");
}

void loop(
{
  if (millis() - lastUpdate >= UPDATE_INTERVAL
{
    lastUpdate = millis();
    updateFakeValues();
  }
  
  if (millis() - lastBlinkTime >= BLINK_INTERVAL
{
    lastBlinkTime = millis();
    blinkState = !blinkState;
  }
  
  handleSerialCommands();
  
  switch (currentMenu) 
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


