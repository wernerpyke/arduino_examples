#include <Arduino.h>
#include "Pyke.h"

void setupRandom() {
    randomSeed(analogRead(0));
}

int randomWaitTime() {
    return random(100, 1001);
}