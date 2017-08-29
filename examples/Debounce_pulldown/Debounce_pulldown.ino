/*
 * Debounce_pulldown.ino
 * Author: Jacques Bellavance August 19, 2017
 * Released under: GNU General Public License v3.0
 * 
 * EdgeDebounceLite allows to have a debouncer on any Arduino pin
 * Just create an instance of EdgeDebounceLite and use its .pin() method
 * to read the pin.
 * 
 * Just use debounce.pin(x); instead of digitalRead(x);
 * 
*/

#define BUTTON_PIN 6
#define LED_PIN 13

#include <EdgeDebounceLite.h>
EdgeDebounceLite debounce;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (debounce.pin(BUTTON_PIN)) digitalWrite(LED_PIN, HIGH);
  else                          digitalWrite(LED_PIN, LOW);
}

