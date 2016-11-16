#include <Wire.h>
#include <Adafruit_ADS1015.h>

#define ANALOG_MAX 1024
#define PIN 4

#include "private.h"
#include "routes.h"
#include "wifi.h"

bool switch_open = true;

void setup() {
    Serial.begin(115200);
    Serial.println("+------------+");
    Serial.println("| booting up |");
    Serial.println("+------------+");

    delay(1000); // Wait a moment before starting up

    Serial.println();

    pinMode(PIN, OUTPUT);
    wifi_setup();
    routes_setup();
}

void loop() {
    digitalWrite(PIN, switch_open ? LOW : HIGH);
    routes_loop();
}
