#include <Arduino.h>
#include <Pyke.h>

const int led = 9; 
const int echo = 6;
const int trig = 7;

int duration = 0;
int distance = 0;

void setup()
{
    setupPyke();

    debugMessage("STARTING");

    pinMode(led, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    debugMessage("SETUP DONE");
}

void loop()
{
    digitalWrite(trig, HIGH);
    delay(1000);
    digitalWrite(trig, LOW);

    debugMessage("TRIGGER DONE");

    duration = pulseIn(echo, HIGH);
    distance = (duration / 2) / 28.5;
    
    if (distance <= 100) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }

    debugMessage("READ DONE");

    debugMessage("FINISHED READING %i", distance);
}