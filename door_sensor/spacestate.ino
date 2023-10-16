#include <FastLED.h>

#define NUM_LEDS 7
#define LED_PIN 0

CRGB leds [NUM_LEDS];

void setup() {
  pinMode(2, INPUT);
  Serial.begin(115200);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}



void loop () {
    static bool oldstate = !digitalRead(2);

    bool state = digitalRead(2);

    if (state != oldstate) {
        Serial.println(state ? "on" : "off");
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
