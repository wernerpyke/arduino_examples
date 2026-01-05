#include <Arduino.h>
#include <Pyke.h>

const int led1 = 9;
const int led2 = 10;
const int led3 = 11;
const int led4 = 12;
const int echo = 6;
const int trig = 7;

int duration = 0;
int distance = 0;

void setup()
{
    setupPyke();

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

void loop()
{
    digitalWrite(trig, HIGH);
    delay(100);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = (duration / 2) / 28.5;

    if (distance <= 50)
    {
        debugMessage("DISTANCE %d", distance);
        digitalWrite(led1, HIGH);
    }
    else
    {
        digitalWrite(led1, LOW);
    }
    
    if (distance <= 25)
    {
        debugMessage("DISTANCE %d", distance);
        digitalWrite(led2, HIGH);
    }
    else
    {
        digitalWrite(led2, LOW);
    }

    if (distance <= 10)
    {
        debugMessage("DISTANCE %d", distance);
        digitalWrite(led3, HIGH);
    }
    else
    {
        digitalWrite(led3, LOW);
    }

    if (distance <= 5)
    {
        debugMessage("DISTANCE %d", distance);
        digitalWrite(led4, HIGH);
    }
    else
    {
        digitalWrite(led4, LOW);
    }
}
