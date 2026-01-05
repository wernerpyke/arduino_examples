#include <Arduino.h>
#include <Pyke.h>

const int servoPin = 8;

int servoAngle = 0;
 

void holdPosition(int angle, unsigned long holdTimeMS)
{
    // 1. Constrain the angle to stay within 0-180 to prevent servo damage
    angle = constrain(angle, 0, 180);

    // 2. Map the angle (0-180) to the pulse width (1000-2000 microseconds)
    int pulseWidth = map(angle, 0, 180, 1000, 2000);
    
    // 3. Work out how long we have to wait after each pulse
    // Standard servo pulse period is 20ms (20,000us)
    int periodDelay = 20000  - pulseWidth;

    // Record when we started
    unsigned long startTime = millis();
    debugMessage("HOLD FROM %lu", startTime);

    // Keep looping until the difference between NOW and START is greater than DURATION
    while (millis() - startTime < holdTimeMS)
    {        
        // A servo doesn't just need a single command to move; 
        // it needs a constant, repeating pulse to maintain its position.
        
        // The first delay determines the width of the pulse
        // This is the "Data" part of the signal.
        digitalWrite(servoPin, HIGH);
        delayMicroseconds(pulseWidth);
        digitalWrite(servoPin, LOW);

        // The second delay determines the frequency (how often the pulse repeats)
        // Servo motors expect a new update roughly every $20ms$ ($20,000\mu s$). This is known as the Period.
        delayMicroseconds(periodDelay);
    }
}

void setup()
{
    setupPyke();
    pinMode(servoPin, OUTPUT);
}

void loop()
{
     
    debugMessage("SERVO ANGLE %d", servoAngle);
    holdPosition(servoAngle, 1000); // Move to the angle and stay there for 1 second
    
    servoAngle = servoAngle + 10;
    
    if (servoAngle >= 90) {
        servoAngle = 0;
    }
}