# ESP32 Wi-Fi Deauth Indicator

ESP32 Wi-Fi Deauth Indicator is a simple project that uses an ESP32 and an RGB LED
to visually indicate the current Wi-Fi connection status.

This project does NOT perform any Wi-Fi attacks.
It only monitors the connection state and reacts visually when a disconnect
or possible deauthentication occurs.

## Supported Boards
- ESP32-S3 (built-in RGB LED)
- ESP32 WROOM-32 (external LED or module maybe) **(coming soon)**

## LED Behavior
- Green: Wi-Fi connected
- Yellow blinking: attempting to connect
- Red fast blinking: Wi-Fi disconnected / possible deauthentication
- Red solid: idle state before next reconnect attempt

## How It Works
The ESP32 connects to a configured Wi-Fi network.
If the connection drops, the device changes LED color and behavior.
After a delay, the ESP32 attempts to reconnect automatically.

This makes it useful as a simple Wi-Fi status or deauthentication indicator
near your PC or desk.

## Flashing Instructions
1. Open the `.ino` file using Arduino IDE
2. Select the correct ESP32 board
3. Edit the Wi-Fi credentials
4. Upload the code to the ESP32

## Configuration
Before flashing, change the following lines in the code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

## External Output Support (Planned)

Future versions will allow the ESP32 to control external lights such as
5V LED strips using GPIO pins and driver modules.

Planned capabilities:
- External LED strip control (5V VCC + GND)
- Blinking patterns based on Wi-Fi status
- Dimming using PWM
- Support for driver modules (MOSFET / relay)

This will allow the indicator to control desk lights or room lighting
instead of only using the built-in RGB LED.
