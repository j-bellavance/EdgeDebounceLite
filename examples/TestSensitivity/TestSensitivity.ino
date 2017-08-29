/*
 * TestSensitivity.ino
 * By Jacques Bellavance, July 7 2017
 * Released under: GNU General Public License v3.0
 *  
 * To test what Sensitivity is best for a particular switch / application
 * Debug LED on pin 13 will light up when TEST_BUTTON is pressed
 * Pressing the MORE button will increase the sensitivity
 * Pressing the LESS button will decrease the sensitivity
 * The serial monitor will display the current sensitivity
 * 
 * Uses the internal pullup resistors
 * Arduino pin 2 --- LESS button ---+---GND
 * Arduino pin 3 --- TEST button ---|
 * Arduino pin 4 --- MORE button ---|
*/

#include <EdgeDebounceLite.h>

#define LESS_PIN 2      //decrease sensititivity
#define TEST_PIN 3      //Fires the test LED on pin 13 when pressed
#define MORE_PIN 4      //increase sensititivity
#define LED_PIN 13      //Debug led on pin 13

EdgeDebounceLite debounce;

void setup() {
  Serial.begin(9600);
  pinMode(LESS_PIN, INPUT_PULLUP);
  pinMode(TEST_PIN, INPUT_PULLUP);
  pinMode(MORE_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  Serial.println(F("Begining testing..."));
  Serial.print(F("Sensitivity is now at: "));
  Serial.println(debounce.getSensitivity());
  Serial.println(F("---------------------------"));
}

void loop() {
  if (!debounce.pin(MORE_PIN)) {
    debounce.setSensitivity(debounce.getSensitivity() + 1);
    Serial.print(F("Sensitivity is now at: "));
    Serial.println(debounce.getSensitivity());
    while (!debounce.pin(MORE_PIN)) {;}  //Wait for the button to be released
  }
  if (!debounce.pin(LESS_PIN)) {
    debounce.setSensitivity(debounce.getSensitivity() - 1);
    Serial.print(F("Sensitivity is now at: "));
    Serial.println(debounce.getSensitivity());
    while (!debounce.pin(LESS_PIN)) {;}  //Wait for the button to be released
  }
  //Place your test code here, using TEST_PIN
  if (debounce.pin(TEST_PIN)) digitalWrite(LED_PIN, LOW); 
  else                        digitalWrite(LED_PIN, HIGH); 
}

