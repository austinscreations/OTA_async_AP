/* Webpage HTML - this is the homepage*/ 

#ifndef processing_items_h
#define processing_items_h

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
  if(var == "title"){
    String titleing = "";
            #if defined(htmltitle)
                titleing += htmltitle;
            #else defined(DeviceName)
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
                #if defined(typetitle)
                      typeing += typetitle;
                #else 
                      typeing +=  "WHAT AM I?";
                #endif
    return typeing;
  }
  


   

  
  return String();
}

#endif
