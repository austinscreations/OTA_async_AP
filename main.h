#if defined(ESP8266)
    #include "ESP8266WiFi.h"
    #include "ESPAsyncTCP.h"
    #include "flash_hal.h"
#elif defined(ESP32)
    #include "WiFi.h"
    #include "AsyncTCP.h"
    #include "Update.h"
    #include "esp_int_wdt.h"
    #include "esp_task_wdt.h"
#endif

#include "ESPAsyncWebServer.h"
#include "FS.h"

String DeviceID();
String DeviceTP();

String ip3string(IPAddress ip);
String processor(const String &var);

void setup_wifi();

boolean webInit();

void Blinkit(int ledPin, long interval, unsigned long currentMillis);

void OTA_Restart();
