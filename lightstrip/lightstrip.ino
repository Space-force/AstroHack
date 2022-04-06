#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>

#define PIN 14
#define PIXEL 12

Adafruit_NeoPixel strip(PIXEL, PIN, NEO_GRB + NEO_KHZ800);

int buttonState = 0;         // variable for reading the pushbutton status
bool buttonReleased = false;         // variable to store if button has been released
int modeState = -1;   // variable for mode counter
int modes = 2; // variable that holds the number of modes for LEDs

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(115200);
  pinMode(13, INPUT_PULLUP);
}


void loop() {
button1();
}


void breathe()
{
  while(true) {
    int R = 1;
    //Fade in
    for(R; R<30; R++) {
      for(int i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(R, R, R));
        strip.show();
        delay(0);
      }
      delay(100);
      if (checkButton()) return;
    }
    //Fade Out
    for(R; R>1; R--) {
      Serial.println(R);
      for(int j=0; j<strip.numPixels(); j++) {
        strip.setPixelColor(j, strip.Color(R, R, R));
        strip.show();
        delay(0);
      }
      delay(100);
      if (checkButton()) return;
    }
    // strip.clear();
    delay(500);
    if (checkButton()) return;
  }
}

bool checkButton()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(13);
  if (buttonState == LOW) {
    if (buttonReleased == true) {
      buttonReleased = false;
      return true;
    };
  } else {
    buttonReleased = true;
  }
  return false;
}

void button1()
{

  // read the state of the pushbutton value:
  //buttonState = digitalRead(13);
  //if (buttonState == LOW) {
    if(modeState < modes-1)  {
      modeState++; //advance the counter by 1
      }
    else 
    {
      modeState = 0; //reset counter
    }

  switch (modeState){ 
    case 0:
      Serial.println("Case 0");
      strip.clear();
      rainbow(10);      
      break;
    case 1:
      Serial.println("Case 1");
      strip.clear();
      breathe();
      break;
  }
}

void rainbow(int wait) {
  while(true) {
    // Hue of first pixel runs 5 complete loops through the color wheel.
    // Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
    // means we'll make 5*65536/256 = 1280 passes through this loop:
    for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
      // strip.rainbow() can take a single argument (first pixel hue) or
      // optionally a few extras: number of rainbow repetitions (default 1),
      // saturation and value (brightness) (both 0-255, similar to the
      // ColorHSV() function, default 255), and a true/false flag for whether
      // to apply gamma correction to provide 'truer' colors (default true).
      strip.rainbow(firstPixelHue);
      // Above line is equivalent to:
      // strip.rainbow(firstPixelHue, 1, 255, 255, true);
      strip.show(); // Update strip with new contents
      if (checkButton()) return; // Check to make sure button hasn't been pressed    
      delay(wait);  // Pause for a moment
    }
  }
}
