/* Webpage HTML - this is the homepage*/ 

#ifndef processing_items_h
#define processing_items_h

#include "CSS.h"
#include "SCRIPTS.h"
#include "config.h"
#include "MCU_functions.h"

uint8_t deviceREBOOTED = true;

String DeviceID()
{
#if defined(DeviceName)
  String id = STR(DeviceName);
#else
  String id = host;
#endif
  return id;
}

String ip3string(IPAddress ip) {
  String ret = String(ip[0]) + "." +  String(ip[1]) + "." + String(ip[2]) + "." + String(ip[3]);
  return ret;
}

String processor(const String& var){ // Change placeholders on webpage

//  if(var == "The_CSS")
//  {
//    String css = "";
//    css += CSS_STYLE;
//   return css;
//  }

  if(var == "The_CSS")
  {
   return CSS_STYLE;
  }
  
  if(var == "The_SCRIPTS")
  {
   return CSS_SCRIPTS;
  }

  if(var == "title"){
    String titleing = "";
            #if defined(htmltitle)
                titleing += htmltitle;
            #else
                titleing +=  DeviceID();
            #endif
    return titleing;
  }
  if(var == "dark"){
    String dark = "";
    if (darkState == false){
      dark += "body { background-color: white; color: black; }";
    }else{
      dark += "body { background-color: black; color: white; }";
    }
    return dark;
  }
  if(var == "online"){
    String online = "";
    if (WiFi.status() == WL_CONNECTED) 
      {
        online += "background:green";
      }
      else
      {
        online += "background:orange";
      }
    return online;
  }
  
  if(var == "color"){
    String coloring = "";
    coloring +=  htmlcolor;
    return coloring;
  }
  if(var == "hover"){
    String hovering = "";
    hovering +=  htmlhover;
    return hovering;
  }
  if(var == "ipplaceholder"){
    String iping = "";
    iping += ip3string(WiFi.localIP());
    return iping;
  }
  if(var == "macplaceholder"){
    String macing = "";
    macing +=  WiFi.macAddress();
    return macing;
  }
  if(var == "IDplaceholder"){
    String IDing = "";
    IDing +=   DeviceID();
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
  if(var == "type"){
    String typeing = "";
                #if defined(htmltype)
                      typeing += htmltype;
                #else 
                      typeing +=  "WHAT AM I?";
                #endif
    return typeing;
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

  return String();
}

#endif
