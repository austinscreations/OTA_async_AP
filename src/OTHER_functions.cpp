#include <Arduino.h>

extern unsigned long previousMillis; // will store last time LED was updated
// extern const long interval;          // interval at which to blink (milliseconds)

// extern const int ledPin; // the number of the LED pin
extern int ledState;     // ledState used to set the LED

void Blinkit(int ledPin, long interval, unsigned long currentMillis)
{
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        if (ledState == LOW)
        {
            ledState = HIGH;
        }
        else
        {
            ledState = LOW;
        }
        digitalWrite(ledPin, ledState);
    }
}
