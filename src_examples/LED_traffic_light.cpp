#include <Arduino.h>

// Describe what a light is. Each light has a name, a pin and a delay
struct Light {
    String name;
    int pin;
    int delay;
};

// Make a list of lights, the size of the list is 3
Light listOfLights[3];

int onLightIndex = 0;

void setup()
{
    // fill up the list with the details of the the individual lights
    listOfLights[0] = { "Red", 10, 3000 };
    listOfLights[1] = { "Blue", 9, 1000 };
    listOfLights[2] = { "Yellow", 8, 2000 };
    
    // make an index with which to loop over the list
    int index = 0; 

    // loop over the list to set the pinMode for each light
    while (index <= 2) { // while the index is within the list
        
        // fetch one item from the list
        Light item = listOfLights[index];

        // set the pin of the item's mode to OUTPUT
        pinMode(item.pin, OUTPUT); 
        
        // increment the index
        index = index + 1;
    }
}

void loop() {
    int delayTime = 0;
    int index = 0;
    while (index <= 2) {
        Light l = listOfLights[index];
        if (index == onLightIndex) {
            digitalWrite(l.pin,HIGH);
            delayTime = l.delay; 
        } else {
            digitalWrite(l.pin,LOW);
        }
    }
    delay(delayTime);

    onLightIndex += 1;
    if (onLightIndex == 3) {
        onLightIndex = 0;
    }
}