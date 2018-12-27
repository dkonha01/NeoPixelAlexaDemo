#include <NeoEffects.h>
#include <NeoStrip.h>
#include <NeoWindow.h>
#include <Adafruit_NeoPixel.h>


#define SMALL_NEORING_SIZE 16
#define STRIP_PIN 6

const int RING_1_START = 0;
const int RING_2_START = 0;
const int RING_3_START = 0;
const int RING_4_START = 0;
const int RING_5_START = 0;
const int RING_6_START = 0;

const int numRings = 6;

NeoStrip strip1 = NeoStrip(SMALL_NEORING_SIZE * numRings, STRIP_PIN, NEO_GRB + NEO_KHZ800);

NeoWindow ring1 = NeoWindow(&strip1, RING_1_START, SMALL_NEORING_SIZE);
NeoWindow ring2 = NeoWindow(&strip1, RING_2_START, SMALL_NEORING_SIZE);
NeoWindow ring3 = NeoWindow(&strip1, RING_3_START, SMALL_NEORING_SIZE);
NeoWindow ring4 = NeoWindow(&strip1, RING_4_START, SMALL_NEORING_SIZE);
NeoWindow ring5 = NeoWindow(&strip1, RING_4_START, SMALL_NEORING_SIZE);
NeoWindow ring6 = NeoWindow(&strip1, RING_4_START, SMALL_NEORING_SIZE);

// pin for input
int switchPinA = 5;
int switchPinB = 9;
int switchPinC = 10;
int switchPinD = 11;
int switchPinE = 12;
int switchPinF = 13;


const uint32_t aNicePurple = strip1.Color(128, 0, 50);
const uint32_t redRed = strip1.Color(128, 0, 0);
const uint32_t soBlue = strip1.Color(0, 0, 128);

void setup() {
  // use serial line for debugging output
  Serial.begin(115200);
  delay(500); 
  
  Serial.println("Starting NeoEffects Test");
  
  strip1.begin();

    
    ring1.setCircleEfx(redRed, 117);   
    ring2.setSparkleEfx(aNicePurple,  7,  47, 77);
    ring3.setBlinkEfx(soBlue, 250, 10);
    ring4.setRainbowEfx( 3, 7 );
    ring5.setWipeEfx(redRed,187 );
  
    
Serial.println("Setup Done");
}

void loop() {

  // grab the current time using the class method. thus it is only called once, regardless of # windows
  NeoWindow::updateTime();

  if( digitalRead(switchPinA) == true )
  {
     ring5.updateWindow();  
     ring1.updateWindow();  
  }
  else if( digitalRead(switchPinB) == true )
  {
     ring2.updateWindow();   
  }
  else if( digitalRead(switchPinC) == true )
  {
     ring3.updateWindow();
  }
  else if( digitalRead(switchPinD) == true )
  {
     ring4.updateWindow();
  }
  else if(digitalRead(switchPinE) == true )
  {
     ring5.updateWindow();
  }
  else if( digitalRead(switchPinF) == true )
  {
     ring6.updateWindow();
  }
  else
   strip1.fillStrip(Adafruit_NeoPixel::Color(0,0,0));
     //delay(10)
 
  // if the strip changed, send commands out to it.
  strip1.show();
  
}
