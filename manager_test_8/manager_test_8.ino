/*
 * started 2021-08-19
 * 
 * adding better debug output
 * 
 * AP mode works - needs 8 charater minamum of the password
 * 
 * config page has been added and formated since v3 2021-07-29
 * version 4 - has all pages working - no saved config
 * 
 * version 5 - working on saving config details with arduinoJSON
 * 
 * version 7 - all varibles work
 * 
 * TO DO
 * finish full config param saving                             // done
 * finish config - reboot option?                              // done - hard coded - automatic
 * button library add                                          // not needed for this demo
 * fix page redirects with better info                         // done
 * better debug window output                                  // done
 * fill in config page with data                               // done
 * 
 * version 4 - intergrate all needed webpages
 * - add save config page                                      // done
 * - add arduinojson for config saving                         // done
 * - add factory reset button - delete wifi and delete json    // done
 * - add full ota                                              // done
 * - upload button password                                    // commented
 * 
 *  *DEMOS*
 * - wifi button USM control                                   // working demo - 2021-07-29 (in low cost button folder)
 * - add button_GPIO USM                                       //
 * - create demo on smart switch                               //
 * - then smart usb hub                                        //
 * 
 */

#include "FS.h"
#include "ESPAsyncWebServer.h"
#include <ArduinoJson.h>
#include "debug.h"

#if defined(ESP8266)
    #include "ESP8266WiFi.h"
    #include "ESPAsyncTCP.h"
    #include "flash_hal.h"
    #include <LittleFS.h>
#elif defined(ESP32)
    #include "WiFi.h"
    #include "AsyncTCP.h"
    #include "Update.h"
    #include "esp_int_wdt.h"
    #include "esp_task_wdt.h"
    #include "LITTLEFS.h"
#endif

#include "config.h"             // config information
#include "factory_settings.h"   // factory reset config

/* WEB PAGES */
#include "homepage.h"           // website home page
#include "management.h"         // Website OTA page
#include "config_page.h"        // ESP html configuration page
#include "failed.h"             // Something failed webpage
#include "reboot.h"             // Website - ESP rebooting
#include "finished.h"           // OTA success Webpage
#include "config_finished.h"    // Saved Config Message Webpage
#include "factory_html.h"       // Factory Reset Performed Webpage

AsyncWebServer server(80);      // declare ASYNC server library

bool restartRequired = false;   // have we told the device to restart?
bool factoryRequired = false;   // have we told the device to factory reset?

unsigned long lastDelete = 0;   // gives time for factory reset to change url then delete data and reboot

#include "wifisave.h"           // Saving new Config information              should be cpp
#include "processing_items.h"   // processor for webpage varibles             should be cpp
#include "customserver.h"       // manages the ASYNC server webpage serving   should be cpp
#include "wifi.h"               // manages the wifi and AP conenctions        should be cpp

uint8_t ledPin =  LED_BUILTIN;// the number of the LED pin
uint8_t LEDState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;   // will store last time LED was updated


void setup() 
{
  Serial.begin(115200);
  delay(500); // There has GOT to be a better way!!!
  DEBUG_Boot();

 DEBUG_Reset();     // print reset reason

 parameterSETUP(); // wifisave.h
 
 wifi_start();     // start wifi   - will start AP / WiFi as needed - wifi.h

 customInit();     // start server - starts ASYNC server - customserver.h
 
 DEBUG_Running();  // prints running ; as most items are setup at this point

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // turn led off
}

void loop() 
{
 wifi_checkup();                        // checks if wifi is still connected and starts AP as needed - wifi.h
 if (restartRequired){OTA_Restart();}   // checks if the esp needs a reboot        - done via webpage / OTA - customserver.h
 if (factoryRequired){deleteData();;}   // checks if the esp needs a factory reset - done via webpage / OTA - customserver.h and wifisave.h

//  if (millis() - previousMillis >= 1000) {
//    previousMillis = millis();
//    if (LEDState == LOW) {
//      LEDState = HIGH;
//    } else {
//      LEDState = LOW;
//    }
//    digitalWrite(ledPin, LEDState);
//  }
  
}
