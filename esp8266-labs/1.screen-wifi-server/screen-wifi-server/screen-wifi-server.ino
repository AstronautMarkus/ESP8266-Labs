#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;

// Define the width and height of the OLED display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C address for the SSD1306 
#define OLED_ADDR 0x3C

// I2C pins for NodeMCU ESP8266 with integrated OLED
#define OLED_SDA 14 // D6
#define OLED_SCL 12 // D5

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Include WiFi credentials
#include "secrets.h"

void showMessage(const char* msg, uint8_t textSize = 2, int y = 20) {
    display.clearDisplay();
    display.setTextSize(textSize);
    display.setTextColor(SSD1306_WHITE);
    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds(msg, 0, 0, &x1, &y1, &w, &h);
    int x = (SCREEN_WIDTH - w) / 2;
    display.setCursor(x, y);
    display.print(msg);
    display.display();
}

void setup() {
    Serial.begin(9600);

    // Start I2C communication
    Wire.begin(OLED_SDA, OLED_SCL);

    // Initialize OLED
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }

    // Connect to WiFi
    showMessage("Connecting to", 1, 24);
    display.setTextSize(1);
    display.setCursor(0, 40);
    display.print(ssid);
    display.display();

    WiFi.mode(WIFI_STA);
    WiFiMulti.addAP(ssid, password);

    // Try to connect to WiFi with timeout (simulate try-catch)
    const unsigned long wifiTimeout = 15000; // 15 seconds
    unsigned long startAttemptTime = millis();
    bool connected = false;

    while (millis() - startAttemptTime < wifiTimeout) {
        if (WiFiMulti.run() == WL_CONNECTED) {
            connected = true;
            break;
        }
        delay(500);
    }

    if (!connected) {
        // Show single centered error message and halt
        showMessage("Check credentials or network and restart device", 1, 24);
        Serial.println("WiFi connection failed. Check credentials or network and restart device.");
        while (true) {
            delay(1000);
        }
    }

    // Show success message
    showMessage("Connected!", 1, 24);
    delay(1000);

    // Show assigned IP address
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 10);
    display.print("Assigned IP:");
    display.setCursor(0, 28);
    display.print(WiFi.localIP());
    display.display();
}

void loop() {
    // Nothing for now
}