#include <Arduino.h>

#include "random_functions.h"

struct Test {
  int value;
  String str;
};

Test red;
Test next;

void blah(Test& t) {
  String d = t.str;

  next.str;
}

void setup() {
  setupRandom();
  
  pinMode(LED_BUILTIN, OUTPUT);

  red = {
    10, 
    "Hello"
  };

  next = red;
}

void loop() {
  
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);

  int wait = randomWaitTime();
  delay(wait);

  digitalWrite(LED_BUILTIN, LOW);
  
  wait = randomWaitTime();
  delay(wait);
}