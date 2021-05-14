// #include "TopSecret.h"
const char* host     = "ESP-OTA";

/* HTML */
const char* htmltitle   = "WHO am I?"; // main title on the top of webpage --- if not defined will default to device name then host
const char* htmltype   = "WHAT am I?"; // Device type on the bottom of webpage --- if not defined will default to device name then host

// purple
const char* htmlcolor   = "#5900b8"; // main HTML webpage color
const char* htmlhover   = "#b370fa"; // html color for hovering over a menu button

//pink
// const char* htmlcolor   = "#ff0059"; // main HTML webpage color
// const char* htmlhover   = "#fa6197"; // html color for hovering over a menu button

//green
// const char* htmlcolor   = "#005500"; // main HTML webpage color
// const char* htmlhover   = "#00aa00"; // html color for hovering over a menu button

/* Blinkenlights */
unsigned long previousMillis = 0; // will store last time LED was updated
const long interval = 1000;       // interval at which to blink (milliseconds)

#if defined(ESP8266)
const int ledPin = LED_BUILTIN; // the number of the LED pin
#elif defined(ESP32)
const int ledPin = 2;
#endif
int ledState = LOW; // ledState used to set the LED
