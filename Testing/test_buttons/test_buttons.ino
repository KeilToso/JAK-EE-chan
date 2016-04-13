
#include "FastLED.h"

///////////////////////////////////////////////////////////////////////////////////////////

// Number of total LED's
#define NUM_LEDS 24

// Data pin that led data will be written out over
#define DATA_PIN 3

// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define CLOCK_PIN 8

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// FFT setup
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>



void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);
    Serial.begin(38400);
    FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  
}

int button1;
int button2;
int button3;
int row1[] = {0,1,2,3,4,5,6,7};
int row2[] = {8,9,10,11,12,13,14,15};
int row3[] = {16,17,18,19,20,21,22,23};
int count1 = 0;
int count2 = 0;
int count3 = 0;

void loop()                     
{
  button1 = analogRead(2);
  button2 = analogRead(3);
  button3 = analogRead(6);

// Row 1 
  if ((button1 <= 500) && (count1 == 0)){
    for(int n=0; n<8; n++){
      leds[n] = CRGB::Green;
    }
      FastLED.show();
      count1 = 1;
      delay(500);
  }

   else if ((button1 <= 500) && (count1 == 1)){
      for(int n=0; n<8; n++){
      leds[n] = CRGB::Blue;
      }
      FastLED.show();
      count1 = 2;
      delay(500);
  }

   else if ((button1 <= 500) && (count1 == 2)){
      for(int n=0; n<8; n++){
      leds[n] = CRGB::Black;
      }
      FastLED.show();
      count1 = 0;
      delay(500);
  }

  // Row 2 
  if ((button2 <= 500) && (count2 == 0)){
    for(int n=8; n<16; n++){
      leds[n] = CRGB::Green;
    }
      FastLED.show();
      count2 = 1;
      delay(500);
  }

   else if ((button2 <= 500) && (count2 == 1)){
      for(int n=8; n<16; n++){
      leds[n] = CRGB::Blue;
      }
      FastLED.show();
      count2 = 2;
      delay(500);
  }

   else if ((button2 <= 500) && (count2 == 2)){
      for(int n=8; n<16; n++){
      leds[n] = CRGB::Black;
      }
      FastLED.show();
      count2 = 0;
      delay(500);
  }

  // button 3

    if ((button3 <= 500) && (count3 == 0)){
    for(int n=16; n<23; n++){
      leds[n] = CRGB::Green;
    }
      FastLED.show();
      count3 = 1;
      delay(500);
  }

   else if ((button3 <= 500) && (count3 == 1)){
      for(int n=16; n<23; n++){
      leds[n] = CRGB::Blue;
      }
      FastLED.show();
      count3 = 2;
      delay(500);
  }

   else if ((button3 <= 500) && (count3 == 2)){
      for(int n=16; n<23; n++){
      leds[n] = CRGB::Black;
      }
      FastLED.show();
      count3 = 0;
      delay(500);
  }

  // Testing
  Serial.print("Button 3: ");
  Serial.println(button3);
  delay(100);
}
