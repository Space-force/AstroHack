#include <Adafruit_NeoPixel.h>

// How many leds in your strip?
#define PIN 14
#define NUM_LEDS 6

// Define the array of leds
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() { 
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  strip.show();
}


void loop() { 
setPixel(0, 0, 0, 255);
setPixel(1, 0, 255, 0);
//CylonBounce(0xff, 0, 0, 4, 10, 50);
}

void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){

  for(int i = 0; i < NUM_LEDS-EyeSize-2; i++) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    strip.show();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);

  for(int i = NUM_LEDS-EyeSize-2; i > 0; i--) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    strip.show();
    delay(SpeedDelay);
  }
 
  delay(ReturnDelay);
}

void breathe() 
{
    //fill_solid(leds, NUM_LEDS, CRGB::White);  // fill white
    //FastLED.show();
    //delay(1000);
    // Dim a color by 25% (64/256ths)
    // eventually fading to full black
    // for(int i = 0; i < NUM_LEDS; i++) {
    //  leds[i].nscale8( 192);
    //}
    //for(int i = 0; i < NUM_LEDS; i++) {
      //leds[i].fadeLightBy( 64 );
    //}
    //FastLED.show();
    //delay(1000);
}
