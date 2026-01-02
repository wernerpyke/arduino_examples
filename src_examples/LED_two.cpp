#include <Arduino.h>

int ledRed = 10;
int ledBlue = 9;

bool isBlueOn=false;

void setup()
{
    pinMode(ledRed, OUTPUT);
    pinMode(ledBlue, OUTPUT);
}

void loop()
{

    if (isBlueOn == false)
    {
        digitalWrite(ledBlue, HIGH);
        digitalWrite(ledRed, LOW);
        isBlueOn=true;
    }
    else
    {
        digitalWrite(ledRed, HIGH);
        digitalWrite(ledBlue, LOW);
        isBlueOn=false;
    }
    delay(100);
}
