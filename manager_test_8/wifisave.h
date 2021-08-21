/* saving incoming parameters from webpage config and handle factory reset */ 

#ifndef wifisave_h
#define wifisave_h

uint8_t new_update = false;

#if defined(ESP8266) // LittleFS used for esp8266

void deleteData()
{
  DEBUG_Init("Data Delete");
   if ((millis() - lastDelete) > 250)
   {
    LittleFS.remove("/config.json"); // Remove the file
    WiFi.disconnect(true);           // Remove SSID creds
    DEBUG_Success("Deleted Data - deleteData");
    ESP.restart();
   }
}

bool saveFACTORY() { // esp8266
    DEBUG_Init("Saving FACTORY Settings");
    DynamicJsonDocument json(1024);
    json["host"]          = hostFACTORY;
    json["ssid"]          = ssidFACTORY;
    json["password"]      = passwordFACTORY;
    json["AP_SSID"]       = AP_SSIDFACTORY;
    json["AP_PASS"]       = AP_PASSFACTORY;
      char cstr1[1];
      itoa(AP_HIDDENFACTORY, cstr1, 10);
      json["AP_HIDDEN"] = cstr1;
    json["mqtt_broker"]   = mqtt_brokerFACTORY;
      char cstr2[8];
      itoa(mqtt_portFACTORY, cstr2, 10);
      json["mqtt_port"] = cstr2;
    json["mqtt_username"] = mqtt_usernameFACTORY;
    json["mqtt_password"] = mqtt_passwordFACTORY;
      char cstr3[1];
      itoa(darkStateFACTORY, cstr3, 10);
      json["darkState"] = cstr3;
    json["htmltitle"]     = htmltitleFACTORY;
    json["htmltype"]      = htmltypeFACTORY;
    json["htmlcolor"]     = htmlcolorFACTORY;
    json["htmlhover"]     = htmlhoverFACTORY;

    File configFile = LittleFS.open("/config.json", "w");
    if (!configFile) {
      DEBUG_Trouble("failed to open config file for writing - saveFACTORY");
      return false;
    }

//    serializeJson(json, Serial);
    serializeJson(json, configFile);
   
    configFile.close();
    //end save
    DEBUG_Success("Saved FACTORY Settings - saveFACTORY");
    return true;
  }

  bool saveConfignew() { // esp8266
    DEBUG_Init("saving NEW config");
    DynamicJsonDocument json(1024);
    json["host"]          = host;
    json["ssid"]          = ssid;
    json["password"]      = password;
    json["AP_SSID"]       = AP_SSID;
    json["AP_PASS"]       = AP_PASS;
      char cstr1[1];
      itoa(AP_HIDDEN, cstr1, 10);
      json["AP_HIDDEN"] = cstr1;
    json["mqtt_broker"]   = mqtt_broker;
      char cstr2[8];
      itoa(mqtt_port, cstr2, 10);
      json["mqtt_port"] = cstr2;
    json["mqtt_username"] = mqtt_username;
    json["mqtt_password"] = mqtt_password;
      char cstr3[1];
      itoa(darkState, cstr3, 10);
      json["darkState"] = cstr3;
    json["htmltitle"]     = htmltitle;
    json["htmltype"]      = htmltype;
    json["htmlcolor"]     = htmlcolor;
    json["htmlhover"]     = htmlhover;

    File configFile = LittleFS.open("/config.json", "w");
    if (!configFile) {
      DEBUG_Trouble("failed to open config file for writing - saveConfignew");
      return false;
    }

//    serializeJson(json, Serial);
    serializeJson(json, configFile);
   
    configFile.close();
    //end save
    DEBUG_Success("Saved NEW Settings - saveConfignew");
    return true;
  }

bool loadConfig(){ // esp8266
    DEBUG_Init("Config");
    if (LittleFS.exists("/config.json")) {
      //file exists, reading and loading
      DEBUG_Success("reading config file - loadConfig");
      File configFile = LittleFS.open("/config.json", "r");
      
      if (configFile) {
        DEBUG_Success("opened config file - loadConfig");
        size_t size = configFile.size();
        // Allocate a buffer to store contents of the file.
        std::unique_ptr<char[]> buf(new char[size]);

        configFile.readBytes(buf.get(), size);
        
        DynamicJsonDocument json(1024);
        auto deserializeError = deserializeJson(json, buf.get());
//        serializeJson(json, Serial);
        if ( ! deserializeError ) {
       
//          Serial.println("\nparsed json");

          strcpy(host, json["host"]);
          strcpy(ssid, json["ssid"]);
          strcpy(password, json["password"]);
          strcpy(AP_SSID, json["AP_SSID"]);
          strcpy(AP_PASS, json["AP_PASS"]);
            String convert1 = json["AP_HIDDEN"];
            AP_HIDDEN = convert1.toInt();
          strcpy(mqtt_broker, json["mqtt_broker"]);
            String convert2 = json["mqtt_port"];
            mqtt_port = convert2.toInt();
          strcpy(mqtt_username, json["mqtt_username"]);
          strcpy(mqtt_password, json["mqtt_password"]);
            String convert3 = json["darkState"];
            darkState = convert3.toInt();
          strcpy(htmltitle, json["htmltitle"]);
          strcpy(htmltype, json["htmltype"]);
          strcpy(htmlcolor, json["htmlcolor"]);
          strcpy(htmlhover, json["htmlhover"]);

        } else {
          DEBUG_Trouble("failed to load json config - loadConfig");
          return false;
        }
        configFile.close();
        DEBUG_Success("file closed - loadConfig");
        return true;
      }
    }
    DEBUG_Trouble("config file doesn't exist - loadConfig");
    return false;
  }

#elif defined(ESP32) // LITTLEFS used for esp32

void deleteData()    // LITTLEFS used for esp32
{
  DEBUG_Init("Data Delete");
  if ((millis() - lastDelete) > 250)
   {
    LITTLEFS.remove("/config.json"); // Remove the file
    WiFi.disconnect(true);           // Remove SSID creds
    DEBUG_Success("Deleted Data - deleteData");
   // ESP32 will commit sucide
    esp_task_wdt_init(1, true);
    esp_task_wdt_add(NULL);
    while (true);
   }
}

bool saveFACTORY() { // esp32
    DEBUG_Init("Saving FACTORY Settings");
    DynamicJsonDocument json(1024);
    json["host"]          = hostFACTORY;
    json["ssid"]          = ssidFACTORY;
    json["password"]      = passwordFACTORY;
    json["AP_SSID"]       = AP_SSIDFACTORY;
    json["AP_PASS"]       = AP_PASSFACTORY;
      char cstr1[1];
      itoa(AP_HIDDENFACTORY, cstr1, 10);
      json["AP_HIDDEN"] = cstr1;
    json["mqtt_broker"]   = mqtt_brokerFACTORY;
      char cstr2[8];
      itoa(mqtt_portFACTORY, cstr2, 10);
      json["mqtt_port"] = cstr2;
    json["mqtt_username"] = mqtt_usernameFACTORY;
    json["mqtt_password"] = mqtt_passwordFACTORY;
      char cstr3[1];
      itoa(darkStateFACTORY, cstr3, 10);
      json["darkState"] = cstr3;
    json["htmltitle"]     = htmltitleFACTORY;
    json["htmltype"]      = htmltypeFACTORY;
    json["htmlcolor"]     = htmlcolorFACTORY;
    json["htmlhover"]     = htmlhoverFACTORY;

    File configFile = LITTLEFS.open("/config.json", "w");
    if (!configFile) {
      DEBUG_Trouble("failed to open config file for writing - saveFACTORY");
      return false;
    }

//    serializeJson(json, Serial);
    serializeJson(json, configFile);
   
    configFile.close();
    //end save
    DEBUG_Success("Saved FACTORY Settings - saveFACTORY");
    return true;
  }

  bool saveConfignew() { // esp32
    DEBUG_Init("saving NEW config");
    DynamicJsonDocument json(1024);
    json["host"]          = host;
    json["ssid"]          = ssid;
    json["password"]      = password;
    json["AP_SSID"]       = AP_SSID;
    json["AP_PASS"]       = AP_PASS;
      char cstr1[1];
      itoa(AP_HIDDEN, cstr1, 10);
      json["AP_HIDDEN"] = cstr1;
    json["mqtt_broker"]   = mqtt_broker;
      char cstr2[5];
      itoa(mqtt_port, cstr2, 10);
      json["mqtt_port"] = cstr2;
    json["mqtt_username"] = mqtt_username;
    json["mqtt_password"] = mqtt_password;
      char cstr3[1];
      itoa(darkState, cstr3, 10);
      json["darkState"] = cstr3;
    json["htmltitle"]     = htmltitle;
    json["htmltype"]      = htmltype;
    json["htmlcolor"]     = htmlcolor;
    json["htmlhover"]     = htmlhover;

    File configFile = LITTLEFS.open("/config.json", "w");
    if (!configFile) {
      DEBUG_Trouble("failed to open config file for writing - saveConfignew");
      return false;
    }

//    serializeJson(json, Serial);
    serializeJson(json, configFile);
   
    configFile.close();
    //end save
    DEBUG_Success("Saved NEW Settings - saveConfignew");
    return true;
  }

bool loadConfig(){ // LITTLEFS used for esp32
    DEBUG_Init("Config");
    if (LITTLEFS.exists("/config.json")) {
      //file exists, reading and loading
      DEBUG_Success("reading config file - loadConfig");
      File configFile = LITTLEFS.open("/config.json", "r");
      
      if (configFile) {
        DEBUG_Success("opened config file - loadConfig");
        size_t size = configFile.size();
        // Allocate a buffer to store contents of the file.
        std::unique_ptr<char[]> buf(new char[size]);

        configFile.readBytes(buf.get(), size);
        
        DynamicJsonDocument json(1024);
        auto deserializeError = deserializeJson(json, buf.get());
//        serializeJson(json, Serial);
        if ( ! deserializeError ) {
       
//          Serial.println("\nparsed json");

          strcpy(host, json["host"]);
          strcpy(ssid, json["ssid"]);
          strcpy(password, json["password"]);
          strcpy(AP_SSID, json["AP_SSID"]);
          strcpy(AP_PASS, json["AP_PASS"]);
            String convert1 = json["AP_HIDDEN"];
            AP_HIDDEN = convert1.toInt();
          strcpy(mqtt_broker, json["mqtt_broker"]);
            String convert2 = json["mqtt_port"];
            mqtt_port = convert2.toInt();
          strcpy(mqtt_username, json["mqtt_username"]);
          strcpy(mqtt_password, json["mqtt_password"]);
            String convert3 = json["darkState"];
            darkState = convert3.toInt();
          strcpy(htmltitle, json["htmltitle"]);
          strcpy(htmltype, json["htmltype"]);
          strcpy(htmlcolor, json["htmlcolor"]);
          strcpy(htmlhover, json["htmlhover"]);

        } else {
          DEBUG_Trouble("failed to load json config - loadConfig");
          return false;
        }
        configFile.close();
        DEBUG_Success("file closed - loadConfig");
        return true;
      }
    }
    DEBUG_Trouble("config file doesn't exist - loadConfig");
    return false;
  }
#endif

void parameterSETUP(){
  #if defined(ESP8266)
  if (!LittleFS.begin()) {
    DEBUG_Trouble("Failed to mount file system - parameterSETUP");
    return;
  }
#elif defined(ESP32)
  if (!LITTLEFS.begin()) {
    DEBUG_Trouble("Failed to mount file system - parameterSETUP");
    return;
  }
#endif
  else
  {
   if (!loadConfig()) 
    {
      DEBUG_Trouble("Failed to load Saved Config - parameterSETUP");
      DEBUG_Init("Saving Factory Information");
      saveFACTORY();
      delay(500);
      DEBUG_Success("Trying to read Factory Config - parameterSETUP");
      if(!loadConfig())
      {
        DEBUG_Trouble("Couldn't read Factory Config - parameterSETUP");
      }
      else
      {
        DEBUG_Success("Trying to read Factory Config - parameterSETUP");
      }
    }
    else 
    {
      DEBUG_Success("Saved Config loaded - parameterSETUP");
      DEBUG_Title(host, htmltype);                                           // debug title screen
    }
  }
}


void wifisaving(AsyncWebServerRequest *request)
{
  DEBUG_Init("Website Config Save");
       String host_ = request->arg("host");
        if (host_ != NULL) // we have a value to do something with
        {
          if (host_ != host) // new color requested
          {
            strcpy(host, host_.c_str());
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: Host Name");
//        Serial.print(" Value: ");
//        Serial.println(host_);
        }

        String ssid_ = request->arg("ssid");
        if (ssid_ != NULL) // we have a value to do something with
        {
          if (ssid_ != ssid) // new color requested
          {
            strcpy(ssid, ssid_.c_str());
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: ssid");
//        Serial.print(" Value: ");
//        Serial.println(ssid_);
        }

        String password_ = request->arg("password");
        if (password_ != NULL) // we have a value to do something with
        {
          if (password_ != password) // new color requested
          {
            strcpy(password, password_.c_str());
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: password");
//        Serial.print(" Value: ");
//        Serial.println(password_);
        }

        String apssid_ = request->arg("apssid");
        if (apssid_ != NULL) // we have a value to do something with
        {
          if (apssid_ != AP_SSID) // new color requested
          {
            strcpy(AP_SSID, apssid_.c_str());
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: apssid");
//        Serial.print(" Value: ");
//        Serial.println(apssid_);
        }

        String appass_ = request->arg("appass");
        if (appass_ != NULL) // we have a value to do something with
        {
          if (appass_ != AP_PASS) // new color requested
          {
            strcpy(AP_PASS, appass_.c_str());
//              AP_PASS = appass_.c_str();
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: appass");
//        Serial.print(" Value: ");
//        Serial.println(appass_);
        }

        String hidden_ = request->arg("hidden");
        if (hidden_ != NULL) // we have a value to do something with
        {
          if (hidden_.toInt() != AP_HIDDEN) // new color requested
          {
            AP_HIDDEN = hidden_.toInt();
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: hidden");
//        Serial.print(" Value: ");
//        Serial.println(hidden_);
        }
        
        String mqtt_ = request->arg("mqtt");
        if (mqtt_ != NULL) // we have a value to do something with
        {
          if (mqtt_ != mqtt_broker) // new color requested
          {
            strcpy(mqtt_broker, mqtt_.c_str());
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: mqtt");
//        Serial.print(" Value: ");
//        Serial.println(mqtt_);
        }

        String port_ = request->arg("port");
        if (port_ != NULL) // we have a value to do something with
        {
          if (port_.toInt() != mqtt_port) // new color requested
          {
            mqtt_port = port_.toInt();
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: port");
//        Serial.print(" Value: ");
//        Serial.println(port);
        }
 
        String mqttuser_ = request->arg("mqttuser");
        if (mqttuser_ != NULL) // we have a value to do something with
        {
          if (mqttuser_ != mqtt_username) // new color requested
          {
            strcpy(mqtt_username, mqttuser_.c_str());
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: mqttuser");
//        Serial.print(" Value: ");
//        Serial.println(mqttuser_);
        }

        String mqttpass_ = request->arg("mqttpass");
        if (mqttpass_ != NULL) // we have a value to do something with
        {
          if (mqttpass_ != mqtt_password) // new color requested
          {
            strcpy(mqtt_password, mqttpass_.c_str());
            new_update = true;
            restartRequired = true;
          }
//        Serial.print("Parameter: mqttpass");
//        Serial.print(" Value: ");
//        Serial.println(mqttpass_);
        }
        
        String htmltitle_ = request->arg("htmltitle");
        if (htmltitle_ != NULL) // we have a value to do something with
        {
          if (htmltitle_ != htmltitle) // new color requested
          {
            strcpy(htmltitle, htmltitle_.c_str());
            new_update = true;
          }
//        Serial.print("Parameter: htmltitle");
//        Serial.print(" Value: ");
//        Serial.println(htmltitle_);
        }
        
        String htmltype_ = request->arg("htmltype");
        if (htmltype_ != NULL) // we have a value to do something with
        {
          if (htmltype_ != htmltype) // new color requested
          {
            strcpy(htmltype, htmltype_.c_str());
            new_update = true;
          }
//        Serial.print("Parameter: htmltype");
//        Serial.print(" Value: ");
//        Serial.println(htmltype_);
        }
        
        String dark_ = request->arg("dark");
        if (dark_ != NULL) // we have a value to do something with
        {
          if (dark_.toInt() != darkState) // new color requested
          {
            darkState = dark_.toInt();
            new_update = true;
          }
//        Serial.print("Parameter: dark");
//        Serial.print(" Value: ");
//        Serial.println(dark_);
        }
        
        String htmlcolor_ = request->arg("htmlcolor");
        if (htmlcolor_ != NULL) // we have a value to do something with
        {
          if (htmlcolor_ != htmlcolor) // new color requested
          {
//            htmlcolor = htmlcolor_.c_str();
            strcpy(htmlcolor, htmlcolor_.c_str());
            new_update = true;
          }
//        Serial.print("Parameter: htmlcolor");
//        Serial.print(" Value: ");
//        Serial.println(htmlcolor_);
        }
        
        String htmlhover_ = request->arg("htmlhover");
        if (htmlhover_ != NULL) // we have a value to do something with
        {
          if (htmlhover_ != htmlhover) // new color requested
          {
//            htmlhover = htmlhover_.c_str();
              strcpy(htmlhover, htmlhover_.c_str());
            new_update = true;
          }
//        Serial.print("Parameter: htmlhover");
//        Serial.print(" Value: ");
//        Serial.println(htmlhover_);
        }

        
       
        if (new_update == true){ // we have new information to update
          DEBUG_Separator();
          saveConfignew();
        }
        else
        {
          DEBUG_Trouble("Nothing to save - wifisaving");
          DEBUG_Separator();
        }
}

#endif // end of wifi save
