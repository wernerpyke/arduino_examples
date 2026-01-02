#include <Arduino.h>

int ledPin = 10;
bool isLedOn = false;

int delayLength = 100;
int numberOfBlinks = 0;

void setup()
{
	pinMode(ledPin, OUTPUT);// define pin with LED connected as output.
    isLedOn = false;
}

void loop()
{
    numberOfBlinks = numberOfBlinks + 1;
    if (numberOfBlinks > 5) {
        delayLength = delayLength + 100;
        numberOfBlinks = 0;
    }

    if (isLedOn == true) {
        digitalWrite(ledPin, LOW); // set the LED off.
        isLedOn = false;
    } else {
        digitalWrite(ledPin, HIGH); // set the LED on.
        isLedOn = true;
    }
    delay(delayLength);
}