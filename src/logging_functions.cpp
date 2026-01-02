#include "logging_functions.h"

void startLogging()
{
    // Start serial communication at 9600 bits per second
    Serial.begin(9600);
    delay(1000);
}

void debugMessage(const char *format, ...)
{
    char loc_buf[64];
    char *temp = loc_buf;
    va_list arg;
    va_list copy;
    va_start(arg, format);
    va_copy(copy, arg);
    int len = vsnprintf(temp, sizeof(loc_buf), format, copy);
    va_end(copy);
    
    if (len < 0)
    {
        va_end(arg);
        Serial.println(String(""));
        return;
    }

    if (len >= (int)sizeof(loc_buf))
    {
        temp = (char *)malloc(len + 1);
        if (temp == NULL)
        {
            va_end(arg);
            Serial.println(String(""));
            return;
        }

        vsnprintf(temp, len + 1, format, arg);
    }

    va_end(arg);
    String s(temp);
    
    if (temp != loc_buf)
        free(temp);
    
    Serial.println(s);
}