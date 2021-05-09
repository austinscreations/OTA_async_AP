//#include <ESP8266WiFi.h>
//#include <ESPAsyncTCP.h>
//#include <ESPAsyncWebServer.h>

#if defined(ESP8266)
    #include "ESP8266WiFi.h"
    #include "ESPAsyncTCP.h"
//    #include "flash_hal.h"
#elif defined(ESP32)
    #include "WiFi.h"
    #include "AsyncTCP.h"
//    #include "Update.h"
//    #include "esp_int_wdt.h"
//    #include "esp_task_wdt.h"
#endif

#include "ESPAsyncWebServer.h"
#include "FS.h"



//#include <WebOTA_async.h>
#include "config.h"



String getID(){
            String id = "";
            #if defined(ESP8266)
                id = String(ESP.getChipId());
            #elif defined(ESP32)
                id = String((uint32_t)ESP.getEfuseMac(), HEX);
            #endif
            id.toUpperCase();
            return id;
        }

String _id = getID();


String processor(const String& var){ // change information at bottom page
  if(var == "hostplaceholder"){
    String hosting = "";
    hosting +=  host;
    return hosting;
  }
  if(var == "IDplaceholder"){
    String IDing = "";
    IDing +=   _id;
    return IDing;
  }
  if(var == "processorplaceholder"){
    String PROing = "";
                #if defined(ESP8266)
                      PROing += "ESP8266";
                #elif defined(ESP32)
                      PROing +=  "ESP32";
                #endif
    return PROing;
  }
  return String();
}

AsyncWebServer server(80);

void setup_wifi() {
  delay(10);
//   We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup(void) {
  Serial.begin(115200);
  WiFi.hostname(host);
  setup_wifi();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->redirect("/home");
  });

  server.on("/home", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", home_html, processor );
  });

  server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", update_html, processor );
  });

  server.begin();

//  webota.init(8888, "/update");
  Serial.println("HTTP server started");
}

void loop() {

  
//    webota.handle();
}
