#include "FastLED.h"

// Number of total LED's
#define NUM_LEDS 16

// Data pin for writing out LED data
#define DATA_PIN 3

// Clock pin for LED's
#define CLOCK_PIN 8

// Array of LED's; one item for each LED.
CRGB leds[NUM_LEDS];


void setup() {
 delay(2000);
  //Serial.begin(38400); uncomment to read analog pins to test buttons
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  
  
  // put your setup code here, to run once:

}

void loop() {
  leds[0].setRGB(0,255,255);
  leds[1].setRGB(255,255,0);
  leds[2].setRGB(255,0,255);
  leds[3].setRGB(100,126,0);
  leds[4].setRGB(50,220,140);
  FastLED.show();
  // put your main code here, to run repeatedly:

}
