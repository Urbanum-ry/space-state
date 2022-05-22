#include "EspMQTTClient.h"
#include "FastLED.h"

#define NUM_LEDS 25
#define LED_PIN 27

CRGB leds [NUM_LEDS];

EspMQTTClient client(
  "SSID",
  "WiFi password",
  "Broker IP",
  "Client name"
);

void setup() {
  pinMode(33, INPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void onConnectionEstablished() {}

void loop() { 
    
    client.loop();
    
    static bool oldstate = !digitalRead(33);

    bool state = digitalRead(33);

    if (state != oldstate) {
      client.publish("/hervanta/main_building/urbanum", state ? "on" : "off");
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
