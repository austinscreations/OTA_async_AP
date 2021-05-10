#if defined(ESP8266)
    #include "ESP8266WiFi.h"
    #include "ESPAsyncTCP.h"
//    #include "flash_hal.h"
#elif defined(ESP32)
    #include "WiFi.h"
    #include "AsyncTCP.h"
    #include "Update.h"
//    #include "esp_int_wdt.h"
//    #include "esp_task_wdt.h"
#endif

#include "ESPAsyncWebServer.h"
//#include "FS.h"

//#include <WebOTA_async.h>
//#include "OTA_ASYNC.h"
#include "config.h"

AsyncWebServer server(80);

long max_sketch_size() {
  long ret = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
  return ret;
}

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
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
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

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->redirect("/home");
  });

  server.on("/home", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", home_html, processor );
  });

  server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", update_html, processor );
  });

  // Handling uploading firmware file
//  server.on("/update", HTTP_POST, [&](AsyncWebServerRequest *request) {
//    request->send_P(200, "text/plain", (Update.hasError()) ? "Update: fail\n" : "Update: OK!\n");
//    delay(500);
//    ESP.restart();
//  },[&](AsyncWebServerRequest *request) {
//    
//HTTPUpload& upload = server.upload();
//
//    if (upload.status == UPLOAD_FILE_START) {
//      Serial.printf("Firmware update initiated: %s\r\n", upload.filename.c_str());
//
//      //uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
//      uint32_t maxSketchSpace = max_sketch_size();
//
//      if (!Update.begin(maxSketchSpace)) { //start with max available size
//        Update.printError(Serial);
//      }
//    } else if (upload.status == UPLOAD_FILE_WRITE) {
//      /* flashing firmware to ESP*/
//      if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
//        Update.printError(Serial);
//      }
//
//      // Store the next milestone to output
//      uint16_t chunk_size  = 51200;
//      static uint32_t next = 51200;
//
//      // Check if we need to output a milestone (100k 200k 300k)
//      if (upload.totalSize >= next) {
//        Serial.printf("%dk ", next / 1024);
//        next += chunk_size;
//      }
//    } else if (upload.status == UPLOAD_FILE_END) {
//      if (Update.end(true)) { //true to set the size to the current progress
//        Serial.printf("\r\nFirmware update successful: %u bytes\r\nRebooting...\r\n", upload.totalSize);
//      } else {
//        Update.printError(Serial);
//      }
//    }
//  });

  server.begin();
  
//  OTA_ASYNC.begin(&server);    // Start OTA

//  Serial.println("HTTP server started")




;
}

void loop() {

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


//OTA_ASYNC.loop();
//    webota.handle();
}
