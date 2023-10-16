#include "EspMQTTClient.h"

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
}

void onConnectionEstablished() {}

void loop()
{
  client.loop();

  static bool oldstate = !digitalRead(2);

  bool state = digitalRead(4);

  if (state != oldstate) {
    client.publish("hervanta/main_building/urbanum", state ? "on" : "off");
  }

  oldstate = state;
  delay(100);
}
