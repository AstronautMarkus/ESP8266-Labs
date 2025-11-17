#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define the width and height of the OLED display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Typical I2C address for SSD1306 (may vary, usually 0x3C)
#define OLED_ADDR 0x3C

// I2C pins for NodeMCU ESP8266 with integrated OLED (according to new information)
#define OLED_SDA 14 // D6
#define OLED_SCL 12 // D5

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Initialize I2C on the correct pins before any use of Wire or display
  Wire.begin(OLED_SDA, OLED_SCL);

  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
  Serial.println(F("SSD1306 allocation failed"));
  for(;;); // Do not continue if it fails
  }
  display.clearDisplay();
  display.setTextSize(2);      // Text size
  display.setTextColor(SSD1306_WHITE); // Text color
  display.setCursor(0,0);      // Initial position
  display.println("Hello!");
  display.setTextSize(1);
  display.println("ESP8266 OLED");
  display.println("SDA: D6 (GPIO14)");
  display.println("SCL: D5 (GPIO12)");
  display.display();           // Show on screen
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
  // Read the incoming byte:
    char incomingByte = Serial.read();

  // Print the received byte to the Serial Monitor
    Serial.print("I received: ");
    Serial.println(incomingByte);
  }
}