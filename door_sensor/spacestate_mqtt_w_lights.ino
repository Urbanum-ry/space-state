#include "EspMQTTClient.h"
#include "FastLED.h"

#define NUM_LEDS 8
#define LED_PIN 5

CRGB leds [NUM_LEDS];

EspMQTTClient client(
  "SSID",
  "Wi-Fi password",
  "Broker IP",
  "mqtt username",
  "mqtt password",
  "client name",
  1883
);

void setup()
{
  Serial.begin(115200);
  pinMode(4, INPUT);
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void onConnectionEstablished() {}

void loop()
{
  client.loop();

  static bool oldstate = !digitalRead(4);

  bool state = digitalRead(4);

  if (state != oldstate) {
    client.publish("hervanta/main_building/into", state ? "on" : "off");
  }

  if (state == 0) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
  }

  if (state == 1) {
    fill_solid(leds, NUM_LEDS, CRGB::Green);
    FastLED.show();
  }

  oldstate = state;
  delay(100);
}
