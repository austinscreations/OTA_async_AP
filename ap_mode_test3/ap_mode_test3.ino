/*
 *  Started 2021-07-09
 *  
 *  AP - basic connection works - 2021-07-12
 *  basis of client connection works - 2021-07-13
 * 
 * Goal - Have Wifi credentials and AP mode availble                                
 * Automatic rollover if wifi fails
 * Veiw main page and config page on both wifi and ap                              - done
 * if wifi configured - go to wifi                                                 - **************
 * if no wifi config - jump right to ap mode                                       - done
 * if wifi configured connect - 1 minute timeout start ap mode                     -
 * Keeps AP alive while no wifi
 * try wifi again
 * When wifi but no ap client , kill AP
 * 
 * homepage and config page availible in both modes
 * 
 * auto reconnect can work like the online status where it expects a respones / request every so often...? - YES THIS WORKS
 * 
 * 
 */

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

#include "config.h"             // wifi and other config
#include "homepage.h"           // website home page
#include "config_page.h"        // website configuration page
#include "processing_items.h"   // processor for webpage varibles

AsyncWebServer server(80);

uint8_t ap_client_connected = false;      //do we have a client connected to ap mode
uint8_t prev_ap_client_connected = false; //last state the client was in.
uint8_t ap_start = false;
unsigned long prev_client;                // last time since a client was connected in AP mode
unsigned long prevAPmillis;
unsigned long wifimillis;

const char* PARAM_INPUT_1 = "state";

void access_point_init(){
    // Access Point Mode
    WiFi.softAPdisconnect(false);
//    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(AP_SSID);
//    WiFi.softAP(AP_SSID, AP_PASS, AP_CHANNEL, AP_HIDDEN, AP_MAX_CON);
    Serial.print("IP address for network ");
    Serial.print(AP_SSID);
    Serial.print(" : ");
    Serial.println(WiFi.softAPIP());
    ap_start = true;
//    webInit(); // start ASYNC server
}

void setup_wifi() {//   We start by connecting to a WiFi network
  delay(10);
  Serial.println();
  Serial.print("Connecting to : ");
  Serial.println(ssid);
//  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  prevAPmillis = millis();
  }


boolean webInit() {
  
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->redirect("/home");
  });

  server.on("/home", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", home_html, processor);
    });

    server.on("/config", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", config_html, processor);
    });

    server.on("/state", HTTP_GET, [](AsyncWebServerRequest *request){ // sets onlien status and alerts us that a client is connected
    request->send(200, "text/plain", "true");
    ap_client_connected = true;
    prev_client = millis();
//    Serial.print("Received request from client with IP: ");         /////////////
//    Serial.println(request->client()->remoteIP());                  /////////////
  });

  server.on("/darkmode", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage1;
    if (request->hasParam(PARAM_INPUT_1)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      if (inputMessage1 == "1"){ darkState = !darkState;}
    }
    request->send(200, "text/plain", "OK");
  });

  server.onNotFound([](AsyncWebServerRequest *request){request->send(404);});
  server.begin();
}

void wifi_checkup(){                                                    // this still causes issues
  if (WiFi.status() != WL_CONNECTED) 
  {
    if (ap_start == false)
    {
     if ((millis() - prevAPmillis) > 30000)  // start AP mode
     {
      Serial.println("\n wifi not connecting - starting AP");
      access_point_init(); // start AP for config
     }
    }
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC address: ");
    Serial.println(WiFi.macAddress());
    prevAPmillis = millis();
  }
  wifimillis = millis();
}


void setup() {

   WiFi.mode(WIFI_AP_STA);
  
  Serial.begin(115200);
  delay(200);
    
  Serial.println("\n Starting");

  if (ssid == "0")
  {
    Serial.println("wifi not defined - starting AP");
    access_point_init(); // start AP for config
  }
  else
  {
    Serial.println(ssid);
    setup_wifi(); // start regular wifi
  }

  Serial.println("Starting ASYNC server");
  webInit(); // start ASYNC server

}

void loop() {

 if ((millis() - wifimillis) > 2000)
 {
 wifi_checkup(); // see if we are conenct or if we need to run AP mode
 }
  

if (ap_client_connected == true) // last we heard there is a client connected to ap mode
{
  if ((millis() - prev_client) > 6000) // if the client hasn't confirmed connection in some time
  {
    ap_client_connected = false; // reset that client is connected
  }
}

  // add an if ssid - to report if staying in ap mode because of no wifi alternative.
if (ap_client_connected != prev_ap_client_connected) // client has connected or disconnected
{
  if (ap_client_connected == true) // client has connected
  {
    Serial.println("client connected");
  }
  else
  {
    Serial.println("client disconnected");
  }
  prev_ap_client_connected = ap_client_connected;
}


}
