#include <FastLED.h>

#define NUM_LEDS 64

#define DATA_PIN1 24
#define DATA_PIN2 25

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];

#define laser1 2
#define laser2 3
#define laser3 4
#define laser4 5

#define laser5 6
#define laser6 7
#define laser7 8
#define laser8 9

#define laser9 10
#define laser10 11
#define laser11 12
#define laser12 13

#define laser13 22
#define laser14 23
#define laser15 24
#define laser16 25

#define receiver1 A0
#define receiver2 A1
#define receiver3 A2
#define receiver4 A3

#define receiver5 A4
#define receiver6 A5
#define receiver7 A6
#define receiver8 A7

#define receiver9 A8
#define receiver10 A9
#define receiver11 A10
#define receiver12 A11

#define receiver13 A12
#define receiver14 A13
#define receiver15 A14
#define receiver16 A15

#define buzzer 53

#define TrigPin1 26  
#define EchoPin1 27 

#define TrigPin2 28  
#define EchoPin2 29  

#define TrigPin3 30 
#define EchoPin3 31 

#define TrigPin4 32 
#define EchoPin4 33  

#define TrigPin5 34 
#define EchoPin5 35 

#define TrigPin6 36 
#define EchoPin6 37  

#define TrigPin7 38  
#define EchoPin7 39  

#define TrigPin8 40  
#define EchoPin8 41  

#define TrigPin9 42
#define EchoPin9 43  

#define TrigPin10 44  
#define EchoPin10 45  

const float DISTANCE_THRESHOLD = 14;

float duration1;
float duration2;
float duration3;
float duration4;
float duration5;
float duration6;
float duration7;
float duration8;
float duration9;
float duration10;

float distance1;
float distance2;
float distance3;
float distance4;
float distance5;
float distance6;
float distance7;
float distance8;
float distance9;
float distance10;

void setup() {
  Serial.begin(9600);  
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds1, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN2>(leds2, NUM_LEDS);

  FastLED.setBrightness(5);

  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser3, OUTPUT);
  pinMode(laser4, OUTPUT);

  pinMode(laser5, OUTPUT);
  pinMode(laser6, OUTPUT);
  pinMode(laser7, OUTPUT);
  pinMode(laser8, OUTPUT);

  pinMode(laser9, OUTPUT);
  pinMode(laser10, OUTPUT);
  pinMode(laser11, OUTPUT);
  pinMode(laser12, OUTPUT);

  pinMode(laser13, OUTPUT);
  pinMode(laser14, OUTPUT);
  pinMode(laser15, OUTPUT);
  pinMode(laser16, OUTPUT);

  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);
  digitalWrite(laser3, HIGH);
  digitalWrite(laser4, HIGH);

  digitalWrite(laser5, HIGH);
  digitalWrite(laser6, HIGH);
  digitalWrite(laser7, HIGH);
  digitalWrite(laser8, HIGH);

  digitalWrite(laser9, HIGH);
  digitalWrite(laser10, HIGH);
  digitalWrite(laser11, HIGH);
  digitalWrite(laser12, HIGH);

  digitalWrite(laser13, HIGH);
  digitalWrite(laser14, HIGH);
  digitalWrite(laser15, HIGH);
  digitalWrite(laser16, HIGH);

  pinMode(receiver1, INPUT);
  pinMode(receiver2, INPUT);
  pinMode(receiver3, INPUT);
  pinMode(receiver4, INPUT);

  pinMode(receiver5, INPUT);
  pinMode(receiver6, INPUT);
  pinMode(receiver7, INPUT);
  pinMode(receiver8, INPUT);

  pinMode(receiver9, INPUT);
  pinMode(receiver10, INPUT);
  pinMode(receiver11, INPUT);
  pinMode(receiver12, INPUT);

  pinMode(receiver13, INPUT);
  pinMode(receiver14, INPUT);
  pinMode(receiver15, INPUT);
  pinMode(receiver16, INPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(TrigPin1, OUTPUT);   
  pinMode(EchoPin1, INPUT);   

  pinMode(TrigPin2, OUTPUT);   
  pinMode(EchoPin2, INPUT);  

  pinMode(TrigPin3, OUTPUT);  
  pinMode(EchoPin3, INPUT); 

  pinMode(TrigPin4, OUTPUT);  
  pinMode(EchoPin4, INPUT); 

  pinMode(TrigPin5, OUTPUT);   
  pinMode(EchoPin5, INPUT); 

  pinMode(TrigPin6, OUTPUT);  
  pinMode(EchoPin6, INPUT); 

  pinMode(TrigPin7, OUTPUT);   
  pinMode(EchoPin7, INPUT);  

  pinMode(TrigPin8, OUTPUT);   
  pinMode(EchoPin8, INPUT);  

  pinMode(TrigPin9, OUTPUT);   
  pinMode(EchoPin9, INPUT); 

  pinMode(TrigPin10, OUTPUT); 
  pinMode(EchoPin10, INPUT);  

  delay(3000);                 
}

void loop() {

  for (int i = 0; i < NUM_LEDS; i++) {
    leds1[i] = CRGB::Black;
    leds2[i] = CRGB::Black;
  }
  FastLED.show();

  bool isReceiver1Blocked = digitalRead(receiver1) == LOW;
  bool isReceiver2Blocked = digitalRead(receiver2) == LOW;
  bool isReceiver3Blocked = digitalRead(receiver3) == LOW;
  bool isReceiver4Blocked = digitalRead(receiver4) == LOW;

  bool isReceiver5Blocked = digitalRead(receiver5) == LOW;
  bool isReceiver6Blocked = digitalRead(receiver6) == LOW;
  bool isReceiver7Blocked = digitalRead(receiver7) == LOW;
  bool isReceiver8Blocked = digitalRead(receiver8) == LOW;

  bool isReceiver9Blocked = digitalRead(receiver9) == LOW;
  bool isReceiver10Blocked = digitalRead(receiver10) == LOW;
  bool isReceiver11Blocked = digitalRead(receiver11) == LOW;
  bool isReceiver12Blocked = digitalRead(receiver12) == LOW;

  bool isReceiver13Blocked = digitalRead(receiver13) == LOW;
  bool isReceiver14Blocked = digitalRead(receiver14) == LOW;
  bool isReceiver15Blocked = digitalRead(receiver15) == LOW;
  bool isReceiver16Blocked = digitalRead(receiver16) == LOW;

  if (isReceiver1Blocked || isReceiver2Blocked || isReceiver3Blocked || isReceiver4Blocked || isReceiver5Blocked 
  || isReceiver6Blocked || isReceiver7Blocked || isReceiver8Blocked || isReceiver9Blocked|| isReceiver10Blocked
  || isReceiver11Blocked || isReceiver12Blocked|| isReceiver13Blocked || isReceiver14Blocked || isReceiver15Blocked || isReceiver16Blocked) 
  {
    activateBuzzer();
  } else {
    turnBuzzerOFF();
  }

  if (isReceiver1Blocked || isReceiver2Blocked || isReceiver3Blocked || isReceiver4Blocked) 
  {
    digitalWrite(TrigPin4, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin4, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin4, LOW);
    duration4 = pulseIn(EchoPin4, HIGH);
    distance4 = duration4 * 0.017;

    if (distance4 < DISTANCE_THRESHOLD) {
      activateAlarm();
    }
  }

  if (isReceiver5Blocked || isReceiver6Blocked ||isReceiver7Blocked || isReceiver8Blocked) 
  {
    digitalWrite(TrigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin1, LOW);

    duration1 = pulseIn(EchoPin1, HIGH);
    distance1 = duration1 * 0.017;

    digitalWrite(TrigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin2, LOW);

    duration2 = pulseIn(EchoPin2, HIGH);
    distance2 = duration2 * 0.017;

    digitalWrite(TrigPin3, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin3, LOW);

    duration3 = pulseIn(EchoPin3, HIGH);
    distance3 = duration3 * 0.017;

    digitalWrite(TrigPin5, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin5, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin5, LOW);

    duration5 = pulseIn(EchoPin5, HIGH);
    distance5 = duration5 * 0.017;

    if (distance1 < DISTANCE_THRESHOLD || distance2 < DISTANCE_THRESHOLD || distance3 < DISTANCE_THRESHOLD || distance5 < DISTANCE_THRESHOLD) 
    {
      activateAlarm();
    }
  }

  if (isReceiver9Blocked || isReceiver10Blocked || isReceiver11Blocked || isReceiver12Blocked) 
  {
    digitalWrite(TrigPin10, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin10, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin10, LOW);

    duration10 = pulseIn(EchoPin10, HIGH);
    distance10 = duration10 * 0.017;

    if (distance10 < DISTANCE_THRESHOLD) {
      activateAlarm();
    }
  }

  if (isReceiver13Blocked || isReceiver14Blocked || isReceiver15Blocked || isReceiver16Blocked) 
  {
    digitalWrite(TrigPin6, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin6, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin6, LOW);

    duration6 = pulseIn(EchoPin6, HIGH);
    distance6 = duration6 * 0.017;

    digitalWrite(TrigPin7, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin7, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin7, LOW);

    duration7 = pulseIn(EchoPin7, HIGH);
    distance7 = duration7 * 0.017;

    digitalWrite(TrigPin8, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin8, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin8, LOW);

    duration8 = pulseIn(EchoPin8, HIGH);
    distance8 = duration8 * 0.017;

    digitalWrite(TrigPin9, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin9, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin9, LOW);

    duration9 = pulseIn(EchoPin9, HIGH);
    distance9 = duration9 * 0.017;

    if (distance6 < DISTANCE_THRESHOLD || distance7 < DISTANCE_THRESHOLD || distance8 < DISTANCE_THRESHOLD || distance9 < DISTANCE_THRESHOLD) 
    {
      activateAlarm();
    }
  }
}

void activateBuzzer() 
{
  digitalWrite(buzzer, HIGH);
}

void turnBuzzerOFF() {
  digitalWrite(buzzer, LOW);
}

void activateAlarm() {
  for (int i = 0; i < 5000; i++) {
    activateBuzzer();
    for (int i = 0; i < NUM_LEDS; i++) {
      leds1[i] = CRGB::Red;
      leds2[i] = CRGB::Red;
    }
    FastLED.show();
    delay(250);
    turnBuzzerOFF();
    // Change LED colors again
    for (int i = 0; i < NUM_LEDS; i++) {
      leds1[i] = CRGB::Purple;
      leds2[i] = CRGB::Purple;
    }
    FastLED.show();
    delay(250);
  }
}