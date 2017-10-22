/*
 * ArrayOfPins.ino
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

byte buttonPins[] {2, 3, 4, 5};

void setup() {
  for (byte i = 0 ; i <4 ; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  for ( byte i = 0 ; i < 4 ; i++) {
    if (debounce.pin(buttonPins[i]) == LOW) {
      Serial.print(F("Button on pin "));
      Serial.print(buttonPins[i]);
      Serial.println(F(" was pressed."));
    }
  }
}
