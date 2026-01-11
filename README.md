# ESP32 Wi-Fi Deauth Indicator

ESP32 Wi-Fi Deauth Indicator is a monitoring project that uses an ESP32 and LED
outputs to visually indicate Wi-Fi connection status changes, including
unexpected disconnections that may be caused by interference or deauthentication.

This project does **not** perform any Wi-Fi attacks.
It only observes connection state changes and reacts through visual indicators.

The goal is to provide a simple, always-on Wi-Fi status indicator for desks,
PC setups, or small projects.

---

## Current Features
- Monitors Wi-Fi connection state using ESP32
- Visual status indication using LEDs
- Automatic reconnect logic with cooldown timers
- Designed to run continuously without freezing

---

## LED Status Behavior
- **Green (solid):** Wi-Fi connected and stable  
- **Green (blink x2):** Successful connection event  
- **Yellow (blinking):** Attempting to connect  
- **Red (fast blinking):** Wi-Fi disconnected / possible deauthentication  
- **Red (solid):** Idle state before next reconnect attempt  

---

## Supported Boards
- **ESP32-S3** (built-in RGB LED)
- **ESP32 WROOM-32** *(coming soon)*

---

## External Output Support (Planned)
Future versions will allow the ESP32 to control external lights such as
5V LED strips using GPIO pins and driver modules.

Planned capabilities:
- External LED strip control (5V VCC + GND)
- PWM dimming via GPIO
- Blinking patterns based on Wi-Fi state
- Support for MOSFET or relay driver modules

This will allow the indicator to control desk lights or ambient lighting
instead of relying only on the built-in RGB LED.

---

## How It Works
The ESP32 connects to a configured Wi-Fi network in station mode.
The device continuously checks the connection status.

When a disconnect is detected:
- The LED switches to alert mode
- Reconnection attempts are delayed to avoid lockups
- Visual feedback reflects the current state

This approach avoids blocking loops and keeps the device responsive.

---

## Flashing Instructions
1. Open the `.ino` file using Arduino IDE
2. Select the correct ESP32 board
3. Edit the Wi-Fi credentials
4. Upload the code to the ESP32

---

## Configuration
Before flashing, update the following lines in the code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
