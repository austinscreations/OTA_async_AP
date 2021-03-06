#include "main.h"
#include "HTML/css.h"
#include "info_placement.h"

/* For Platform.IO */
/* Sets Device Name Flag */
#define ST(A) #A
#define STR(A) ST(A)
////////////////////

const char* PARAM_dark_1 = "state";
int deviceREBOOTED = true;

extern const char *host;

String DeviceID()
{
#if defined(DeviceName)
    String id = STR(DeviceName);
#else
    String id = host;
#endif
    return id;
}

String DeviceTP()
{
#if defined(DeviceType)
    String id = STR(DeviceType);
#else
    String id = host;
#endif
    return id;
}

String ip3string(IPAddress ip)
{
    String ret = String(ip[0]) + "." + String(ip[1]) + "." + String(ip[2]) + "." + String(ip[3]);
    return ret;
}

extern const char *htmlcolor;
extern const char *htmlhover;
extern const char *htmltitle;
extern const char *htmltype;

extern int darkState;

String processor(const String &var) // Change placeholders on webpage
{
    //////////////////////////////////////////////  How to add a block to a web page...
    if (var == "Verkz")                      // The placeholder
    {
        extern const char *Verkz;               // The block (See testpage.h)
        return Verkz;
    }
    //////////////////////////////////////////////
    //////////////////////////////////////////////  How to add a block to a web page...
    if (var == "Poem")                      // The placeholder
    {
        extern const char *Poem;               // The block (See testpage.h)
        return Poem;
    }
    //////////////////////////////////////////////
    if (var == "title")
    {
        String titleing = "";
#if defined(DeviceName)
        titleing += DeviceID();
#else
        titleing += htmltitle;
#endif
        return titleing;
    }
    if(var == "dark")
    {
        String dark = "";
     if (darkState == false){
      dark += "body { background-color: white; color: black; }";
     }else{
      dark += "body { background-color: black; color: white; }";
     }
     return dark;
    }
    if (var == "type")
    {
        String typeing = "";
#if defined(DeviceType)
        typeing += DeviceTP();
#else
        typeing += htmltype;
#endif
        return typeing;
    }
    if (var == "color")
    {
        String coloring = "";
        coloring += htmlcolor;
        return coloring;
    }
    if (var == "hover")
    {
        String hovering = "";
        hovering += htmlhover;
        return hovering;
    }
    if (var == "ipplaceholder")
    {
        String iping = "";
        iping += ip3string(WiFi.localIP());
        return iping;
    }
    if (var == "macplaceholder")
    {
        String macing = "";
        macing += WiFi.macAddress();
        return macing;
    }
    if (var == "IDplaceholder")
    {
        String IDing = "";
        IDing += DeviceID();
        return IDing;
    }
    if (var == "processorplaceholder")
    {
        String PROing = "";
#if defined(ESP8266)
        PROing += "ESP8266";
#elif defined(ESP32)
        PROing += "ESP32";
#endif
        PROing += " (";
        PROing += String(ESP.getFlashChipSize() / 1024 / 1024, DEC);
        PROing += "MB )";
        return PROing;
    }
    if (var == "errorplaceholder")
    {
        String erroring = "";
        if (deviceREBOOTED == false){
         erroring += "";
        } else {
         erroring += "Device Rebooted";
         deviceREBOOTED = false;
            erroring += " (";

         #if defined(ESP8266)
            String RebootReason =
                ESP.getResetReason().c_str();
          #elif defined(ESP32)
            String RebootReason =
                return_reset_reason(rtc_get_reset_reason(0));
            erroring += RebootReason;
            erroring += "/";
            RebootReason =
                return_reset_reason(rtc_get_reset_reason(1));
          #endif
            erroring += RebootReason;
            erroring += ")";
        }
        return erroring;
    }
    if(var == "uptime")
    {
     String infos = info_uptime();
     return infos;
    }
    if(var == "chipid")
    {
     String infos = info_chipid();
     return infos;
    }
    if(var == "idesize")
    {
      String infos = info_idesize();
     return infos;
    }
    if(var == "flashsize")
    {
      String infos = info_flashsize();
     return infos;
    }
    if(var == "sdkver")
    {
      String infos = info_sdkver();
     return infos;
    }
    if(var == "cpufreq")
    {
      String infos = info_cpufreq();
     return infos;
    }
    if(var == "freeheap")
    {
      String infos = info_freeheap();
     return infos;
    }
    if(var == "memsketch")
    {
      String infos = info_memsketch();
     return infos;
    }
    if(var == "lastreset")
    {
      String infos = info_lastreset();
     return infos;
    }
    if(var == "conx")
    {
      String infos = info_conx();
     return infos;
    }
    if(var == "stassid")
    {
      String infos = info_stassid();
     return infos;
    }
    if(var == "staip"){
      String infos = info_staip();
     return infos;
    }
    if(var == "stamac")
    {
      String infos = info_stamac();
     return infos;
    }
    if(var == "stagw")
    {
      String infos = info_stagw();
     return infos;
    }
    if(var == "stasub")
    {
      String infos = info_stasub();
     return infos;
    }
    if(var == "dnss")
    {
      String infos = info_dnss();
     return infos;
    }
    if(var == "hostnom")
    {
      String infos = info_hostnom();
     return infos;
    }
    if(var == "apssid")
    {
      String infos = info_apssid();
     return infos;
    }
    if(var == "apip")
    {
      String infos = info_apip();
     return infos;
    }
    if(var == "apmac")
    {
      String infos = info_apmac();
     return infos;
    }
    if(var == "memsmeter")
    {
      String infos = info_memsmeter();
     return infos;
    }
    return String();
}


AsyncWebServer server(80);

/* include the webpages (done in HTML) */
#include "HTML/homepage.h"   // Homepage HTML
#include "HTML/updatepage.h"  // UPDATEpage HTML
#include "HTML/failedOTA.h"   // HTML to be created
#include "HTML/reboot.h"      // HTML to be created
#include "HTML/testpage.h"    //  HTML
#include "HTML/Finished.h"    //  HTML

extern bool restartRequired;

boolean webInit()
{
    //////////////////////////////////////////////////////////////////////////
        server.on("/TheCSS.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", TheCSS, processor);
    });
    //////////////////////////////////////////////////////////////////////////

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->redirect("/home");
    });

    server.on("/home", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", home_html, processor);
    });

    server.on("/management", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", update_html, processor);
    });

    server.on("/complete", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", done_html, processor );
    });

    server.on("/failedOTA", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", failOTA_html, processor );
    });

    server.on("/reboot", HTTP_GET, [](AsyncWebServerRequest *request) {
     request->send_P(200, "text/html", reboot_html, processor );
     restartRequired = true;
    });

    server.on("/darkmode", HTTP_GET, [] (AsyncWebServerRequest *request) {
     String inputMessage1;
      if (request->hasParam(PARAM_dark_1)) 
      {
       inputMessage1 = request->getParam(PARAM_dark_1)->value();
       if (inputMessage1 == "1"){ darkState = !darkState;}
      }
     request->send(200, "text/plain", "OK");
    });
 
    server.on("/test", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", test_html, processor);
    });

    server.on("/management", HTTP_POST, [&](AsyncWebServerRequest *request) {
                // the request handler is triggered after the upload has finished... 
                // create the response, add header, and send response
                AsyncWebServerResponse *response = request->beginResponse((Update.hasError())?500:200, "text/plain", (Update.hasError())?"FAIL":"OK");
                response->addHeader("Connection", "close");
                response->addHeader("Access-Control-Allow-Origin", "*");
                request->send(response);
                restartRequired = true;
            }, [&](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {
                //Upload handler chunks in data
                
                if (!index) 
                {

#if defined(ESP8266)
                int cmd = (filename == "filesystem") ? U_FS : U_FLASH;
                Update.runAsync(true);
                size_t fsSize = ((size_t)&_FS_end - (size_t)&_FS_start);
                uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
                if (!Update.begin((cmd == U_FS) ? fsSize : maxSketchSpace, cmd))
                { // Start with max available size
#elif defined(ESP32)
                int cmd = (filename == "filesystem") ? U_SPIFFS : U_FLASH;
                if (!Update.begin(UPDATE_SIZE_UNKNOWN, cmd))
                { // Start with max available size
#endif
                    Update.printError(Serial);
                    return request->send(400, "text/plain", "OTA could not begin");
                }
            }

            // Write chunked data to the free sketch space
            if (len)
            {
                if (Update.write(data, len) != len)
                {
                    return request->send(400, "text/plain", "OTA could not begin");
                }
            }

            if (final)
            { // if the final flag is set then this is the last frame of data
                if (!Update.end(true))
                { //true to set the size to the current progress
                    Update.printError(Serial);
                    return request->send(400, "text/plain", "Could not end OTA");
                }
            }
             else
             {
                return;
             } } 
        );

    server.onNotFound([](AsyncWebServerRequest *request) { request->send(404); });
    server.begin();
    ////////////////////////////////////////////////////////////
    return (true);
    ////////////////////////////////////////////////////////////
}

void OTA_Restart()
{

    // if (restartRequired)
    //   {
    yield();
    delay(1000);
    yield();
#if defined(ESP8266)
    ESP.restart();
#elif defined(ESP32)
    // ESP32 will commit sucide
    esp_task_wdt_init(1, true);
    esp_task_wdt_add(NULL);
    while (true)
        ;
#endif
    //   }
}
