#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
//#include <WebOTA_async.h>
#include "config.h"

AsyncWebServer server(80);

void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

//  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
//    request->send(200, "text/plain", "Hi! I am ESP8266.");
//  });

  server.on("/home", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", home_html );
  });

  server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", update_html );
  });

  server.begin();

//  webota.init(8888, "/update");
  Serial.println("HTTP server started");
}

void loop() {

  
//    webota.handle();
}
