#include <SimpleTimer.h>
#include "FastLED.h"
#define LED_TYPE    WS2811
#define NUM_LEDS 32  // # of LEDS in the strip
#define COLOR_ORDER GRB
#define NUM_STRIPS 3
CRGB leds[NUM_LEDS];
uint8_t gBrightness = 128;


int trigPin1 = 3;
int echoPin1 = 8;

int trigPin2 = 4;
int echoPin2 = 9;

int trigPin3 = 2;
int echoPin3 = 10;

int onTime = 2 * 1000; // 4 seconds

void setup() {
  Serial.begin (9600);

  FastLED.addLeds<WS2812, 11>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, 12>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, 13>(leds, NUM_LEDS);


  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void firstsensor() { // This function is for first sensor.
  int duration1, distance1;
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;

  Serial.print("1st Sensor: ");
  Serial.print(distance1);
  Serial.print("cm    ");

  if (distance1 < 30) {  // Change the number for long or short distances.

    {
      {
        fill_solid(leds, NUM_LEDS, CRGB::Red);
      }
      FastLED[0].showLeds(gBrightness);
      //delay(onTime);
    }
    //delay(onTime);
  }
  else {
    {
      fill_solid(leds, NUM_LEDS, CRGB::Green);
    }
    FastLED[0].showLeds(gBrightness);

  }
}

  void secondsensor() { // This function is for second sensor.
    int duration2, distance2;
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = (duration2 / 2) / 29.1;

    Serial.print("2nd Sensor: ");
    Serial.print(distance2);
    Serial.print("cm    ");

    if (distance2 < 20) {  // Change the number for long or short distances.

      {
        {
          fill_solid(leds, NUM_LEDS, CRGB::Red);
        }
        FastLED[2].showLeds(gBrightness);
        //delay(onTime);
      }
      //delay(onTime);
    }
    else {
      {
        fill_solid(leds, NUM_LEDS, CRGB::Green);
      }
      FastLED[2].showLeds(gBrightness);

    }
  }
  void thirdsensor() { // This function is for third sensor.
    int duration3, distance3;
    digitalWrite (trigPin3, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin3, LOW);
    duration3 = pulseIn (echoPin3, HIGH);
    distance3 = (duration3 / 2) / 29.1;

    Serial.print("3rd Sensor: ");
    Serial.print(distance3);
    Serial.print("cm");


    if (distance3 < 20) {  // Change the number for long or short distances.

      {
        {
          fill_solid(leds, NUM_LEDS, CRGB::Red);
        }
        FastLED[3].showLeds(gBrightness);
        //delay(onTime);
      }
      //delay(onTime);
    }
    else {
      {
        fill_solid(leds, NUM_LEDS, CRGB::Green);
      }
      FastLED[3].showLeds(gBrightness);

    }
  }
  void loop() {
    Serial.println("\n");
    firstsensor();
    secondsensor();
    thirdsensor();
 
  }
