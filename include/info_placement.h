#ifndef info_placement_h
#define info_placement_h

//#include "config.h"   // wifi and other config

extern const char *host;
extern const char *ssid;
extern const char *apssid;

String info_uptime(){ 
   String uptimeing = " " + ((String)(millis() / 1000 / 60)) +  " Mins " + ((String)((millis() / 1000) % 60)) + " Secs"; 
   return uptimeing;
  }
String info_chipid(){
    #ifdef ESP8266
      String chipid = (String(ESP.getChipId(),HEX));
    #elif defined ESP32
      uint32_t chipId = 0;
      for(int i=0; i<17; i=i+8) {
      chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
      }
      String chipid = ((String)(chipId));
    #endif
    return chipid;
}
String info_idesize(){
    String idesize = ((String)ESP.getFlashChipSize());
    return idesize;
}
String info_flashsize(){
    #ifdef ESP8266
      String flashsize = ((String)ESP.getFlashChipRealSize());
    #elif defined ESP32
      String flashsize = ((String)ESP.getPsramSize());      
    #endif
    return flashsize;
}
String info_sdkver(){
    #ifdef ESP32
    String sdkver = ((String)esp_get_idf_version());
    //(String)system_get_sdk_version()); // deprecated
    #else
    String sdkver = ((String)system_get_sdk_version());
    #endif
    return sdkver;
}
String info_cpufreq(){
    String cpufreq = ((String)ESP.getCpuFreqMHz());
    return cpufreq;
}
String info_freeheap(){
    String freeheap = ((String)ESP.getFreeHeap());
    return freeheap;
}
String info_memsketch(){
    String memsketch = ((String)(ESP.getSketchSize())) +  " / " + ((String)(ESP.getSketchSize()+ESP.getFreeSketchSpace())) + "  Used / Total";
    return memsketch;
}
String info_lastreset(){
    String lastreset = " Bork Gotta Add This ";
    return lastreset;
}
String info_conx(){
    String conx = (WiFi.isConnected() ? ("yes") : ("no"));
    return conx;
}
String info_stassid(){
    String stassid = ((String)ssid);
    return stassid;
}
String info_staip(){
    String staip = (WiFi.localIP().toString());
    return staip;
}
String info_stamac(){
    String stamac = (WiFi.macAddress());
    return stamac;
}
String info_stagw(){
    String stagw = (WiFi.gatewayIP().toString());
    return stagw;
}
String info_stasub(){
    String stasub = (WiFi.subnetMask().toString());
    return stasub;
}
String info_dnss(){
    String dnss = (WiFi.dnsIP().toString());
    return dnss;
}
//String info_hostnom(String x){
//    #ifdef ESP32
//    String hostnom = (x);
//    #else
//    String hostnom = (x);
//    #endif
//    return hostnom;
//}
String info_hostnom(){
    #ifdef ESP32
    String hostnom = ((String)host);
    #else
    String hostnom = ((String)host);
    #endif
    return hostnom;
}
String info_apssid(){
    String ap_ssid = ((String)apssid);
    return ap_ssid;
}
String info_apip(){
    String apip = (WiFi.softAPIP().toString());
    return apip;
}
String info_apmac(){
    String apmac = ((String)WiFi.softAPmacAddress());
    return apmac;
}

String info_memsmeter(){
    int remsize = (((ESP.getSketchSize()+ESP.getFreeSketchSpace()) / (ESP.getSketchSize())) / 4);
    String memsmeter = ((String)remsize) + "rem";
    return memsmeter;
}









//  else if(id==F("memsmeter")){
//    p = FPSTR("Memory Space: ");
//    p.replace(FPSTR(),(String)(ESP.getSketchSize()));
//    p.replace(FPSTR(),(String)(ESP.getSketchSize()+ESP.getFreeSketchSpace()));
//  }
  
//  else if(id==F("lastreset")){
//    #ifdef ESP8266
//      p = FPSTR("Last Reset: ");
//      p.replace(FPSTR(),(String)ESP.getResetReason());
//    #elif defined(ESP32) && defined(_ROM_RTC_H_)
//      // requires #include <rom/rtc.h>
//      p = FPSTR(HTTP_INFO_lastreset);
//      for(int i=0;i<2;i++){
//        int reason = rtc_get_reset_reason(i);
//        String tok = (String)T_ss+(String)(i+1)+(String)T_es;
//        switch (reason)
//        {
//          //@todo move to array
//          case 1  : p.replace(tok,F("Vbat power on reset"));break;
//          case 3  : p.replace(tok,F("Software reset digital core"));break;
//          case 4  : p.replace(tok,F("Legacy watch dog reset digital core"));break;
//          case 5  : p.replace(tok,F("Deep Sleep reset digital core"));break;
//          case 6  : p.replace(tok,F("Reset by SLC module, reset digital core"));break;
//          case 7  : p.replace(tok,F("Timer Group0 Watch dog reset digital core"));break;
//          case 8  : p.replace(tok,F("Timer Group1 Watch dog reset digital core"));break;
//          case 9  : p.replace(tok,F("RTC Watch dog Reset digital core"));break;
//          case 10 : p.replace(tok,F("Instrusion tested to reset CPU"));break;
//          case 11 : p.replace(tok,F("Time Group reset CPU"));break;
//          case 12 : p.replace(tok,F("Software reset CPU"));break;
//          case 13 : p.replace(tok,F("RTC Watch dog Reset CPU"));break;
//          case 14 : p.replace(tok,F("for APP CPU, reseted by PRO CPU"));break;
//          case 15 : p.replace(tok,F("Reset when the vdd voltage is not stable"));break;
//          case 16 : p.replace(tok,F("RTC Watch dog reset digital core and rtc module"));break;
//          default : p.replace(tok,F("NO_MEAN"));
//        }
//      }
//    #endif
//  }


#endif
