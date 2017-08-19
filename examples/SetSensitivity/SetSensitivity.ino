/*
 * SetSensitivity.ino
 * By Jacques Bellavance, July 7 2017
 * Shows how to change the sensitivity of the Debounce Library
 * This sketch is for switches that uses the internal pullup resistor
 * Switch pin A : Ground
 * Switch pin B : Arduino's pin 2
*/

#include <EdgeDebounceLite.h>

#define BUTTON_PIN 2

//Create an instance of EdgeDebounceLite
EdgeDebounceLite debounce;  

void setup() {
  debounce.setSensitivity(8);            //sensitivity defaults to 16. Now changed to 8
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  if (!debounce.pin(BUTTON_PIN)) digitalWrite(13, HIGH);
  else                           digitalWrite(13, LOW);
} 

