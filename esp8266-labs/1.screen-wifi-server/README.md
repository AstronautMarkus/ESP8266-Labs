# Screen WiFi Server Template for ESP8266 (NodeMCU)

This project provides a simple template for connect your ESP8266 NodeMCU board to a WiFi network and shows current IP address on an OLED screen. The code is ready to use, with the correct I2C pins already configured for typical NodeMCU boards (SDA: D6/GPIO14, SCL: D5/GPIO12). You can use this as a starting point for your own projects that require WiFi connectivity and display capabilities.

## Features

- Pre-configured I2C pins for NodeMCU ESP8266.
- Connects to a specified WiFi network.
- Displays the assigned IP address on an OLED screen.

## Required Libraries

Make sure to install the following libraries via the Arduino Library Manager:

- **ESP8266WiFi** (by ESP8266 Community)  

- **Adafruit SSD1306** (by Adafruit)  

- **Adafruit GFX Library** (by Adafruit)  

- **Wire** (built-in for ESP8266 boards)

## Required secrets.h File

You need to create a `secrets.h` file in the same directory as your main `.ino` file. This file should contain your WiFi credentials in the following format:

```cpp
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
```

You can copy this file from the `secrets.h.example` provided in the repository.

```bash
cp secrets.h.example secrets.h
```

Then, change ssid and password for your real WiFi network credentials.

> You can use this code as a starting point for your own projects that require WiFi connectivity and display capabilities.
