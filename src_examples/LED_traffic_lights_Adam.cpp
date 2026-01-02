#include <Arduino.h>
#include "logging_functions.h"

// Describe what a light is. Each light has a name, a pin and a delay
struct Light {
   int pin;
   int delay;
};

// Make a list of lights, the size of the list is 3
Light CatalogOfLigfhts[3];

int activeLightIndex = 0;

void setup()
{
    startLogging();

    debugMessage("SETTING UP LIGHTS");

    // fill up the list with the details of the the individual lights
    CatalogOfLigfhts[0] ={9,3000};
    CatalogOfLigfhts[1] ={8,1000};
    CatalogOfLigfhts[2] ={10,2000};

    // make an index with which to loop over the list
     int index =0;

    // loop over the list to set the pinMode for each light
    while ((index <= 2))
    {
        Light item = CatalogOfLigfhts[index];
        pinMode(item.pin,OUTPUT);
        index = index+1;
    }
}

void loop()
{
    int index =0;
    while (index <=2){
        Light c=CatalogOfLigfhts[index];
        if(index==activeLightIndex){
            digitalWrite(c.pin,HIGH);
        }
        else {
            digitalWrite(c.pin,LOW);
        }
        index = index + 1;
    };

    debugMessage("TURN ON %i", activeLightIndex);

    activeLightIndex = activeLightIndex + 1;
    if(activeLightIndex==3) {
        activeLightIndex = 0;
    };

    delay(1000);
}
