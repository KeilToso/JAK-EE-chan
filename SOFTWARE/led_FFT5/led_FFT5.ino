// EE 403
// Team JAK-EE chan
// Authors: Jeremy Doll, Ahmad Mostafa, Keil Toso

// LED library
#include "FastLED.h"

// FFT setup
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// Number of total LED's
#define NUM_LEDS 16

// Data pin for writing out LED data
#define DATA_PIN 3

// Clock pin for LED's
#define CLOCK_PIN 8

// Array of LED's; one item for each LED.
CRGB leds[NUM_LEDS];

const int myInput = AUDIO_INPUT_LINEIN;
//const int myInput = AUDIO_INPUT_MIC;

// Create the Audio components.  These should be created in the
// order data flows, inputs/sources -> processing -> outputs
//
AudioInputI2S          audioInput;         // audio shield: mic or line-in
AudioAnalyzeFFT1024    myFFT;
AudioOutputI2S         audioOutput;        // audio shield: headphones & line-out

// Connect either the live input or synthesized sine wave
AudioConnection patchCord1(audioInput, 0, myFFT, 0);
AudioControlSGTL5000 audioShield;

void setup() 
{
  // Sanity check delay
  delay(2000);
  //Serial.begin(38400); uncomment to read analog pins to test buttons
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // Required audio for memory connections
  AudioMemory(12);

  // Enable the audio shield and set the output volume.
  audioShield.enable();
  audioShield.inputSelect(myInput);
  audioShield.volume(0.5);

  // Configure the desired window function for FFT use.
  myFFT.windowFunction(AudioWindowHanning1024);

// Start-up Sequence
  for(int k=0; k<8; k++)
    {
      // red
      leds[15-k].setRGB(0,0,255);
      // blue
      leds[k].setRGB(255,0,0);
      FastLED.show();
      delay(150);
    }

   for(int k=0; k<16; k++)
    {
      // purple
      leds[k].setRGB(255,0,255);
      // green
      leds[15-k].setRGB(0,255,0);
      FastLED.show();
      delay(100);
    }

   for(int k=0; k<16; k++)
    {
      // cyan
      leds[k].setRGB(255,255,0);
      // yellow
      leds[15-k].setRGB(0,255,255);
      FastLED.show();
      delay(50);
    }
   
    // Turn off all LED's
    for(int k=0; k<16; k++)
    {
      leds[k].setRGB(0,0,0);
      FastLED.show();
    }
}

// Button variables store voltages at analog inputs (0-1023)
int button1;
int button2;
int button3;

// Count variables keep track of LED colors
int count1 = 0;
int count2 = 0;
int count3 = 0;

// Store values corresponding to LED colors for each button
int color1 = 0;
int color2 = 0;
int color3 = 0;

// RGB values for each button
int r1 = 0;
int g1 = 0;
int b1 = 0;
int r2 = 0;
int g2 = 0;
int b2 = 0;
int r3 = 0;
int g3 = 0;
int b3 = 0;


void loop()                     
{
  // Read voltages at analog pins to determine whether or not a button was pressed
  button1 = analogRead(2);
  button2 = analogRead(3);
  //button3 = analogRead(6);


////////////        buttons    ///////////////////////////////////////////////////
  
  // Row 1 
  if ((button1 <= 500) && (count1 == 0))
  {
    // Green
    b1 = 0;
    g1 = 255;
    r1 = 0;
    count1 = 1;
    delay(200);
  }

  else if ((button1 <= 500) && (count1 == 1))
  {
      // Blue
      b1 = 255;
      g1 = 0;
      r1 = 0;
      count1 = 2;
      delay(200);
  }

  else if ((button1 <= 500) && (count1 == 2))
  {
      // Red
      b1 = 0;
      g1 = 0;
      r1 = 255;
      count1 = 3;
      delay(200);
  }

  else if ((button1 <= 500) && (count1 == 3))
  {
      // Cyan
      b1 = 255;
      g1 = 255;
      r1 = 0;
      count1 = 4;
      delay(200);
  }

 else if ((button1 <= 500) && (count1 == 4))
  {
      // Purple
      b1 = 255;
      g1 = 0;
      r1 = 255;
      count1 = 5;
      delay(200);
  }

 else if ((button1 <= 500) && (count1 == 5))
  {
      // Yellow
      b1 = 0;
      g1 = 255;
      r1 = 255;
      count1 = 6;
      delay(200);
  }

 else if ((button1 <= 500) && (count1 == 6))
  {
      // White
      b1 = 255;
      g1 = 255;
      r1 = 255;
      count1 = 7;
      delay(200);
  }

 else if ((button1 <= 500) && (count1 == 7))
  {
      // Black (off)
      b1 = 0;
      g1 = 0;
      r1 = 0;
      count1 = 0;
      delay(200);
  }

  // Row 2 
  if ((button2 <= 500) && (count2 == 0))
  {
    // Green
    b2 = 0;
    g2 = 255;
    r2 = 0;
    count2 = 1;
    delay(200);
  }

  else if ((button2 <= 500) && (count2 == 1))
  {
      // Blue
      b2 = 255;
      g2 = 0;
      r2 = 0;
      count2 = 2;
      delay(200);
  }

  else if ((button2 <= 500) && (count2 == 2))
  {
      // Red
      b2 = 0;
      g2 = 0;
      r2 = 255;
      count2 = 3;
      delay(200);
  }

    else if ((button2 <= 500) && (count2 == 3))
  {
      // Cyan
      b2 = 255;
      g2 = 255;
      r2 = 0;
      count2 = 4;
      delay(200);
  }

 else if ((button2 <= 500) && (count2 == 4))
  {
      // Purple
      b2 = 255;
      g2 = 0;
      r2 = 255;
      count2 = 5;
      delay(200);
  }

 else if ((button2 <= 500) && (count2 == 5))
  {
      // Yellow
      b2 = 0;
      g2 = 255;
      r2 = 255;
      count2 = 6;
      delay(200);
  }

 else if ((button2 <= 500) && (count2 == 6))
  {
      // White
      b2 = 255;
      g2 = 255;
      r2 = 255;
      count2 = 7;
      delay(200);
  }

 else if ((button2 <= 500) && (count2 == 7))
  {
      // Black (off)
      b2 = 0;
      g2 = 0;
      r2 = 0;
      count2 = 0;
      delay(200);
  }

////////////////////////////////////////////////////////////
  float n;
  int i;
  
  // Only operate if FFT data available
  if (myFFT.available()) 
  {
    Serial.print("FFT: ");

    // Print only FFT data that exceeds threshold (n)
    // i is the FFT bin (512 total, spaced ~ 43 Hz apart)
    for (i=0; i<512; i++) 
    {
      n = myFFT.read(i);
      if (n >= 0.03) 
      {
        Serial.print(n);
        Serial.print(" ");

        // Bass frequencies
        if ((n >= 0.05) && (i < 12)) 
        {
          for(int j=0; j<8; j++)
          {
            leds[j].setRGB(b1,g1,r1);
          }
          FastLED.show();
          delay(10);
          for(int j=0; j<8; j++)
          {
            leds[j].setRGB(0,0,0);
          }
          FastLED.show();
        }
      
        // Treble Frequencies
        else if (i >= 22) 
        {
          for(int j=8; j<16; j++)
          {
            leds[j].setRGB(b2,g2,r2);
          }
          FastLED.show();
          delay(10);
          for(int j=8; j<16; j++)
          {
            leds[j].setRGB(0,0,0);
          }
          FastLED.show();
        }
        /*
        // Treble frequencies
        else if (i >= 37) 
        {
          for(int j=16; j<24; j++)
          {
            leds[j].setRGB(r3,g3,b3);
          }
          FastLED.show();
          delay(100);
          for(int j=16; j<24; j++)
          {
            leds[j].setRGB(0,0,0);
          }
          FastLED.show(); 
        }
        */

      }
      else
      {
        Serial.print(" low ");
      }      
    }
    Serial.println();
  }
} 

  




