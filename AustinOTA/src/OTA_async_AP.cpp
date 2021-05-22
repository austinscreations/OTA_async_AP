#include "main.h"

bool restartRequired = false;

#include "config.h" // Config for various items.  (HTML colours, BlinkIt() stuff, etc)

void setup(void)
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // turn led off

  Serial.begin(115200);
  WiFi.hostname(host);
  setup_wifi();

  // MQTT_Init();

  webInit();

}

void loop()
{
  if (restartRequired)
    OTA_Restart();

#ifdef BLINK
  Blinkit(ledPin, interval, millis());
#endif
}
