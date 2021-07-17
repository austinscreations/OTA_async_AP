/*
 *  Started 2021-07-09
 *  // issue with online status for tri color operation
 *  
 *  AP - basic connection works         - 2021-07-12
 *  basis of client connection works    - 2021-07-13
 *  ap - wifi failover, and ap disabled - 2021-07-17
 * 
 * Goal - Have Wifi credentials and AP mode availble                                
 * Automatic rollover if wifi fails                                                - done
 * Add config feilds to config page                                                -
 * save new configuration elements                                                 -
 * recall saved config upon startup                                                -
 * factory reset                                                                   -
 * Veiw main page and config page on both wifi and ap                              - done
 * if wifi configured - go to wifi                                                 - done
 * if no wifi config - jump right to ap mode                                       - done
 * if wifi configured connect - ~30 second timeout start ap mode                   - done
 * Keeps AP alive while no wifi                                                    - done
 * try wifi again                                                                  - done
 * When wifi but no ap client , kill AP                                            - done
 * online status                                                                   - done
 *   - green for active wifi webpage - red when no server    
 *   - orange for webpage from AP wifth no wifi connected
 *       - will go green when wifi conencted or red for no server
 * 
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

uint8_t wifi_confirmed = false;
uint8_t ap_client_connected = false;      //do we have a client connected to ap mode
uint8_t ap_connected = false;             //station conencted to AP
uint8_t ap_msg_timeout = false;
uint8_t prev_ap_client_connected = false; //last state the client was in.
uint8_t ap_start = false;
unsigned long prev_client;                // last time since a client was connected in AP mode
unsigned long prevAPmillis;
unsigned long wifimillis;
unsigned long timer;
unsigned long ap_timeout;


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
//    request->send(200, "text/plain", "true");
//    request->send_P(200, "text/plain", "green");
     if (WiFi.status() != WL_CONNECTED)
     {
      request->send_P(200, "text/plain", "orange");
     }
     else
     {
      request->send_P(200, "text/plain", "green");
     }
     
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

  return true;
}

void wifi_checkup(){
  if (WiFi.status() != WL_CONNECTED) 
  {
    wifi_confirmed = false;
    if (ap_start == false)
    {
     if ((millis() - prevAPmillis) > 30000)  // start AP mode
     {
      Serial.println("\n wifi not connecting - starting AP");
      ap_msg_timeout = false;
      access_point_init(); // start AP for config
     }
    }
    ap_timeout = millis();
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    if (wifi_confirmed == false){
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC address: ");
    Serial.println(WiFi.macAddress());
    wifi_confirmed = true;
    }
    prevAPmillis = millis();

    if (ap_connected == false) // no one is connected to AP
    {
       if (ap_msg_timeout == false)
       {
         if ((millis() - ap_timeout) > 30000); // haven't seen an AP station in 30 seconds turn off AP
         {
           WiFi.softAPdisconnect(true);
           Serial.println("AP mode disabled - wifi restored");
           ap_msg_timeout = true;
         }
       }
    }
    else
    {
      ap_timeout = millis();
    }

  }
  wifimillis = millis();
}


void setup() {

   WiFi.mode(WIFI_AP_STA);
  
  Serial.begin(115200);
  delay(200);
    
  Serial.println("\n Starting");

  if (strcmp(ssid, "0") == 0)
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
  if ((millis() - prev_client) > 11000) // if the client hasn't confirmed connection in some time
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

if ((millis() - timer) > 5000) // this works - shows number of stations conencted to AP wifi
{
  if (ap_start == true)
  {
//    Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
    ap_connected = WiFi.softAPgetStationNum();
  }
  timer = millis();
}


}
