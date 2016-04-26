
#include "FastLED.h"

///////////////////////////////////////////////////////////////////////////////////////////

// Number of total LED's
#define NUM_LEDS 16

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

const int myInput = AUDIO_INPUT_LINEIN;
//const int myInput = AUDIO_INPUT_MIC;

// Create the Audio components.  These should be created in the
// order data flows, inputs/sources -> processing -> outputs
//
AudioInputI2S          audioInput;         // audio shield: mic or line-in
AudioSynthWaveformSine sinewave;
AudioAnalyzeFFT1024    myFFT;
AudioOutputI2S         audioOutput;        // audio shield: headphones & line-out

// Connect either the live input or synthesized sine wave
AudioConnection patchCord1(audioInput, 0, myFFT, 0);
//AudioConnection patchCord1(sinewave, 0, myFFT, 0);

AudioControlSGTL5000 audioShield;


void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);
    //Serial.begin(38400);
    FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // Required audio for memory connections
    AudioMemory(12);

  // Enable the audio shield and set the output volume.
  audioShield.enable();
  audioShield.inputSelect(myInput);
  audioShield.volume(1);

  // Configure the window algorithm to use
  myFFT.windowFunction(AudioWindowHanning1024);
  //myFFT.windowFunction(NULL);

  for(int j=0; j<16; j++){
     leds[j] = CRGB::Black;
     FastLED.show();
      }
}

int button1;
int button2;
int button3;
int count1 = 0;
int count2 = 0;
int count3 = 0;

void loop()                     
{
  button1 = analogRead(2);
  button2 = analogRead(3);
  button3 = analogRead(6);

  float n;
  int i;

  if (myFFT.available()) {
    // each time new FFT data is available
    // print it all to the Arduino Serial Monitor
    Serial.print("FFT: ");
    
    for (i=0; i<512; i++) {
      n = myFFT.read(i);
      if (n >= 0.04) {
        Serial.print(n);
        Serial.print(" ");
///////////////////////////////////////////////////////
  if ((button1 <= 500) && (count1 == 0)){
    for(int n=0; n<8; n++){
      leds[n] = CRGB::Green;
    }
      
      count1 = 1;
      delay(500);
  }

   else if ((button1 <= 500) && (count1 == 1)){
      for(int n=0; n<8; n++){
      leds[n] = CRGB::Blue;
      }
      
      count1 = 2;
      delay(500);
  }

   else if ((button1 <= 500) && (count1 == 2)){
      for(int n=0; n<8; n++){
      leds[n] = CRGB::White;
      }
      
      count1 = 0;
      delay(500);
  }


//////////////////////////////////////////////////
 
        if ((i >= 0) && (i < 14)) {
          leds[0] = CRGB::Green;
          //for(int j=0; j<8; j++){
           // leds[j] = CRGB::Blue;
           // }
      FastLED.show();
      delay(100);
      leds[0] = CRGB::Black;
      FastLED.show();
     
        }
        else if ((i>= 14) && (i < 37)) {
          leds[8] = CRGB::Green;
         // for(int j=8; j<16; j++){
          //  leds[j] = CRGB::Blue;
         //   }
      FastLED.show();
      delay(100);
      leds[8] = CRGB::Black;
      FastLED.show();
  }
          
        else if (i >= 37) {
          leds[12] = CRGB::Green;
          //for(int j=16; j<23; j++){
            //leds[j] = CRGB::White;
            //}
      FastLED.show();
      delay(100);
      leds[12] = CRGB::Black;
      FastLED.show();
      
        }
        
        }
        else{
          
          //for (int j = 0; j<24; j++){
            //leds[j] = CRGB::Black;
            
            
            Serial.print("  -  ");
          }
        }
    }
          
        
        
        Serial.println();
        
    } 
  



/*

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
*/
