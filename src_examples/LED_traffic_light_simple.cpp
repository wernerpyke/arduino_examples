#include <Arduino.h>

int ledRed = 10;
int ledBlue = 9;
int ledYel = 8;

void setup()
{
    pinMode(ledRed, OUTPUT);
    pinMode(ledBlue, OUTPUT);
    pinMode(ledYel,OUTPUT);
}

void loop()
{
digitalWrite(ledRed,LOW);
digitalWrite(ledBlue,HIGH);
delay(1000);
digitalWrite(ledBlue,LOW);
digitalWrite(ledYel,HIGH);
delay(250);
digitalWrite(ledYel,LOW);
digitalWrite(ledRed,HIGH);
delay(500);
}
