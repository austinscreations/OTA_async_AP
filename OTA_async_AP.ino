#if defined(ESP8266)
    #include "ESP8266WiFi.h"
    #include "ESPAsyncTCP.h"
//    #define U_PART U_FS
    #include "flash_hal.h"
#elif defined(ESP32)
    #include "WiFi.h"
    #include "AsyncTCP.h"
    #include "Update.h"
//    #define U_PART U_SPIFFS
    #include "esp_int_wdt.h"
    #include "esp_task_wdt.h"
#endif

#include "ESPAsyncWebServer.h"
#include "FS.h"

bool restartRequired = false;

#include "config.h"   // wifi and other config

/* include the webpages (done in HTML) */
#include "homepage.h"  // Homepage HTML
#include "updatepage.h"  // UPDATEpage HTML
//#include "doupdatepage.h"  // HTML to be created


AsyncWebServer server(80);
size_t content_len;

String getID(){ // get device ID for webpage
            String id = "";
            #if defined(ESP8266)
                id = String(ESP.getChipId());
            #elif defined(ESP32)
                id = String((uint32_t)ESP.getEfuseMac(), HEX);
            #endif
            id.toUpperCase();
            return id;
        }

String _id = getID(); // get device ID for webpage

String processor(const String& var){ // Change placeholders on webpage
  if(var == "hostplaceholder"){
    String hosting = "";
    hosting +=  host;
    return hosting;
  }
  if(var == "macplaceholder"){
    String macing = "";
    macing +=  WiFi.macAddress();
    return macing;
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

void setup_wifi() {//   We start by connecting to a WiFi network
  delay(10);
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
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
}

boolean webInit() {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->redirect("/home");
  });

  server.on("/home", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", home_html, processor );
  });

  server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", update_html, processor );
  });

  server.on("/doUpdate", HTTP_POST, [&](AsyncWebServerRequest *request) {
                // the request handler is triggered after the upload has finished... 
                // create the response, add header, and send response
                AsyncWebServerResponse *response = request->beginResponse((Update.hasError())?500:200, "text/plain", (Update.hasError())?"FAIL":"OK");
                response->addHeader("Connection", "close");
                response->addHeader("Access-Control-Allow-Origin", "*");
                request->send(response);
                restartRequired = true;
            }, [&](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {
                //Upload handler chunks in data
                
                if (!index) {
                    
                    #if defined(ESP8266)
                        int cmd = (filename == "filesystem") ? U_FS : U_FLASH;
                        Update.runAsync(true);
                        size_t fsSize = ((size_t) &_FS_end - (size_t) &_FS_start);
                        uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
                        if (!Update.begin((cmd == U_FS)?fsSize:maxSketchSpace, cmd)){ // Start with max available size
                    #elif defined(ESP32)
                        int cmd = (filename == "filesystem") ? U_SPIFFS : U_FLASH;
                        if (!Update.begin(UPDATE_SIZE_UNKNOWN, cmd)) { // Start with max available size
                    #endif
                        Update.printError(Serial);
                        return request->send(400, "text/plain", "OTA could not begin");
                    }
                }

                // Write chunked data to the free sketch space
                if(len){
                    if (Update.write(data, len) != len) {
                        return request->send(400, "text/plain", "OTA could not begin");
                    }
                }
                    
                if (final) { // if the final flag is set then this is the last frame of data
                    if (!Update.end(true)) { //true to set the size to the current progress
                        Update.printError(Serial);
                        return request->send(400, "text/plain", "Could not end OTA");
                    }
                }else{
                    return;
                }
                
            });

  server.onNotFound([](AsyncWebServerRequest *request){request->send(404);});
  server.begin();
}


const int ledPin =  LED_BUILTIN;// the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)


void setup(void) {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // turn led off
  
  Serial.begin(115200);
  WiFi.hostname(host);
  setup_wifi();

//  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
//    request->redirect("/home");
//  });
//
//  server.on("/home", HTTP_GET, [](AsyncWebServerRequest *request) {
//    request->send_P(200, "text/html", home_html, processor );
//  });
//
//  server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request) {
//    request->send_P(200, "text/html", update_html, processor );
//  });
//  server.begin();

   webInit();
} // end setup

void loop() {
if(restartRequired){
                yield();
                delay(1000);
                yield();
                #if defined(ESP8266)
                    ESP.restart();
                #elif defined(ESP32)
                    // ESP32 will commit sucide
                    esp_task_wdt_init(1,true);
                    esp_task_wdt_add(NULL);
                    while(true);
                #endif
            }
  


//unsigned long currentMillis = millis();
//  if (currentMillis - previousMillis >= interval) {
//    previousMillis = currentMillis;
//    if (ledState == LOW) {
//      ledState = HIGH;
//    } else {
//      ledState = LOW;
//    }
//    digitalWrite(ledPin, ledState);
//  }






} // end loop
