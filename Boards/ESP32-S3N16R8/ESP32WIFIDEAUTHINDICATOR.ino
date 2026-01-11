#include <WiFi.h>
#include <Adafruit_NeoPixel.h>

const char* ssid = "Your_wifi_SSID/NAME";
const char* password = "YOUR_WIFI_pass";

#define LED_PIN 48
#define LED_COUNT 1

Adafruit_NeoPixel led(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

enum Mode {
  MODE_OK,       // is ok ithink
  ALERT,
  RED_IDLE,
  TRY_CONNECT,
  MODE_FLASH     // good
};

Mode mode = TRY_CONNECT;

unsigned long t0 = 0;
unsigned long t1 = 0;
bool on = false;
int flashes = 0;

void rgb(uint8_t r, uint8_t g, uint8_t b) {
  led.setPixelColor(0, led.Color(r, g, b));
  led.show();
}

void wifiStart() {
  WiFi.disconnect(true, true);
  delay(30);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
}
//test
void wifiStop() {
  WiFi.disconnect(true, true);
  WiFi.mode(WIFI_OFF);
}

void setup() {
  led.begin();
  led.clear();
  led.show();

  wifiStart();
  t0 = millis();
}

void loop() {
  unsigned long now = millis();
//test 5
  switch (mode) {

    case MODE_OK:
      rgb(0, 255, 0);
      if (WiFi.status() != WL_CONNECTED) {
        mode = ALERT;
        t0 = now;
        t1 = now;
        on = false;
      }
      break;

    case ALERT:
      if (now - t1 > 120) {
        t1 = now;
        on = !on;
        rgb(on ? 255 : 0, 0, 0);
      }
      if (now - t0 > 3000) {
        mode = RED_IDLE;
        t0 = now;
        rgb(255, 0, 0);
      }
      break;

    case RED_IDLE:
      rgb(255, 0, 0);
      if (now - t0 > 10000) {
        wifiStart();
        mode = TRY_CONNECT;
        t0 = now;
        t1 = now;
        on = false;
      }
      break;

    case TRY_CONNECT:
      if (now - t1 > 250) {
        t1 = now;
        on = !on;
        rgb(on ? 255 : 0, on ? 160 : 0, 0);
      }

      if (WiFi.status() == WL_CONNECTED) {
        mode = MODE_FLASH;
        t1 = now;
        flashes = 0;
        on = false;
      }

      if (now - t0 > 5000) {
        wifiStop();
        mode = RED_IDLE;
        t0 = now;
        rgb(255, 0, 0);
      }
      break;

    case MODE_FLASH:
      if (now - t1 > 250 && flashes < 4) {
        t1 = now;
        on = !on;
        rgb(0, on ? 255 : 0, 0);
        flashes++;
      }
      if (flashes >= 4) {
        mode = MODE_OK;
      }
      break;
  }
}

