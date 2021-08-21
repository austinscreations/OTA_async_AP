/* This page and fuctions handle filling in %varibles% in HTML webpages*/

#ifndef processing_items_h
#define processing_items_h

#include "CSS.h"
#include "SCRIPTS.h"
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

String info_memsketch(){
    String memsketch = ((String)(ESP.getSketchSize())) +  " / " + ((String)(ESP.getSketchSize()+ESP.getFreeSketchSpace())) + "  Used / Total";
    return memsketch;
   }

String ip3string(IPAddress ip) {
  String ret = String(ip[0]) + "." +  String(ip[1]) + "." + String(ip[2]) + "." + String(ip[3]);
  return ret;
}

String processor(const String& var){ // Change placeholders on webpage

  if(var == "The_CSS")
  {
   return CSS_STYLE;
  }
  
  if(var == "The_SCRIPTS")
  {
   return CSS_SCRIPTS;
  }

  if(var == "memsketch")
    {
      String infos = info_memsketch();
     return infos;
    }

  if(var == "title"){
    String titleing = "";
    titleing += htmltitle;
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
     typeing += htmltype;
    return typeing;
  }

  if(var == "IDfactory"){
    String idfing = "";
     idfing += hostFACTORY;
    return idfing;
  }

  if(var == "IDssid"){  // filling in the config page with ssid if configured
    String ssing = "";
    if (strcmp(ssid, "0") == 0)
    {
      ssing += "ssid";
      return ssing;
    }
    else
    {
     ssing += "ssid = "; 
     ssing += ssid; 
     return ssing;
    }
  }

  if(var == "whatpass"){  // filling in the config page with ssid password
    String whatping = "";
    if (strcmp(password, "0") == 0)
    {
      whatping += "WiFi password";
      return whatping;
    }
    else
    {
     whatping += "Password Set"; 
     return whatping;
    }
  }

  if(var == "passwhat"){  // filling in the config page ap password
    String whatsping = "";
     whatsping += "Password Set"; 
     return whatsping;
  }

  if(var == "apss"){  // filling in the config page ap ssid
    String apssing = "";
     apssing += "AP SSID = ";
     apssing += AP_SSID; 
     return apssing;
  }

  if(var == "aphid"){  // filling in the config page ap hidden value
    String aphing = "";
     aphing += "AP hidden = ";
     aphing += AP_HIDDEN; 
     return aphing;
  }

  if(var == "broker"){  // filling in the config page with ssid if configured
    String brokeing = "";
    if (strcmp(mqtt_broker, "0") == 0)
    {
      brokeing += "mqtt broker";
      return brokeing;
    }
    else
    {
     brokeing += "mqtt broker = ";
     brokeing += mqtt_broker; 
     return brokeing;
    }
  }

  if(var == "port"){  // filling in the config page with ssid if configured
    String porting = "";
     porting += "port = ";
     porting += mqtt_port; 
     return porting;
  }

  if(var == "userID"){  // filling in the config page with ssid if configured
    String ming = "";
    if (strcmp(mqtt_username, "0") == 0)
    {
      ming += "mqtt username"; 
      return ming;
    }
    else
    {
      ming += "mqtt username = ";
      ming += mqtt_username; 
     return ming;
    }
  }

  if(var == "notpass"){  // filling in the config page with ssid if configured
    String mping = "";
    if (strcmp(mqtt_password, "0") == 0)
    {
      mping += "mqtt password";
      return mping;
    }
    else
    {
     mping += "Password Set"; 
     return mping;
    }
  }

  if(var == "darkmode"){  // filling in the config page ap hidden value
    String dming = "";
     dming += "Dark Mode = ";
     dming += darkState; 
     return dming;
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
