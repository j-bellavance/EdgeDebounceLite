/*
 * Debounce_pullup.ino
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

#include <EdgeDebounceLite.h>

EdgeDebounceLite debounce;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  if (!debounce.pin(2)) digitalWrite(13, HIGH);
  else                  digitalWrite(13, LOW);
}

