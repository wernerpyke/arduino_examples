#include <Arduino.h>

#include "random_functions.h"

void setupRandom() {
    randomSeed(analogRead(0));
}

int randomWaitTime() {
    return random(100, 1001);
}