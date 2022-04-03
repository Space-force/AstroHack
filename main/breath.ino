// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    14

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 6

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


// setup() function -- runs once at startup --------------------------------

void setup() {
  Serial.begin(115200);
  Serial.println("Entering Setup");
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.println("Strip Initialized");
  strip.fill(strip.Color(0, 0, 255));
  Serial.println("Strip filled");
  strip.show();            // Turn OFF all pixels ASAP
  Serial.println("Strip enabled");
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  Serial.println("Brightness at 50");
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  Serial.println("calling breath");
  breath(250);
  Serial.println("breath called");
}


// Some functions of our own for creating animated effects -----------------
int value = 255;
int valueStep = 34;
void breath(int wait) {
  Serial.print("breath is ");
  Serial.println(value);
  strip.setBrightness(value);
  strip.show();                          //  Update strip to match
  value+=valueStep;
  if(value >= 255){
    value = 255;
    valueStep*=-1;
  }else if(value <= 25){
    value = 25;
    valueStep*=-1;
  }
  delay(wait);                           //  Pause for a moment
}
