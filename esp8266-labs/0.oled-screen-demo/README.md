# OLED Screen Demo Template for ESP8266 (NodeMCU)

This project provides a simple template for using an OLED screen with the ESP8266 NodeMCU board. The code is ready to use, with the correct I2C pins already configured for typical NodeMCU boards (SDA: D6/GPIO14, SCL: D5/GPIO12). You can use this as a starting point for your own projects that require displaying information on an OLED screen.

> This project shows a "Hello" message in yellow text on the OLED display and shows the pin configuration used. (SDA: D6, SCL: D5)

## Features

- Pre-configured I2C pins for NodeMCU ESP8266.
- Simple demo displaying text on the OLED.
- Easy to modify for your own needs.

## Required Libraries

Make sure to install the following libraries via the Arduino Library Manager:

- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- Wire (usually included with Arduino IDE)

## Usage

1. Connect your OLED display to the NodeMCU using the following pins:
   - **SDA:** D6 (GPIO14)
   - **SCL:** D5 (GPIO12)
2. Upload the code to your ESP8266 NodeMCU.
3. The display will show a welcome message and pin configuration.

You can use this template as a base for your own OLED projects with the ESP8266.