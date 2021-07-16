#ifndef config_h
#define config_h


// Device name / hostname - Hostname may not work on all DCHP setups
const char* host          = "ESP-AP";

//const char*   ssid        = "test";         // unconfigured ssid
const char*   ssid        = "0";            // unconfigured ssid
const char*   password    = "0";            // unconfigured wifi password

/*
 * Set up an access point
 * @param ssid              Pointer to the SSID (max 32 char).
 * @param pass               For WPA2 min 8 char max 64 char
 * @param channel           WiFi channel number, 1 - 13.
 * @param ssid_hidden       Network cloaking (0 = broadcast SSID, 1 = hide SSID)
 * @param max_connection    Max simultaneous connected clients, 0 - 8. 
 */
const char*   AP_SSID     = "autoconnect";
const char*   AP_PASS     = "0";
uint8_t       AP_CHANNEL  = 1;
uint8_t       AP_HIDDEN   = false;
uint8_t       AP_MAX_CON  = 1;


/* HTML */
int darkState           = true;       // prefered darkmode state

#define htmltitle   "AP / WIFI TEST"; // main title on the top of webpage --- if not defined will default to device name then host
#define htmltype    "AP / WIFI DEMO"; // Device type on the bottom of webpage --- if not defined will default to device name then host

// purple
 const char* htmlcolor   = "#5900b8"; // main HTML webpage color
 const char* htmlhover   = "#b370fa"; // html color for hovering over a menu button

//pink
// const char* htmlcolor   = "#ff0059"; // main HTML webpage color
// const char* htmlhover   = "#fa6197"; // html color for hovering over a menu button

//green
//const char* htmlcolor      = "#005500"; // main HTML webpage color
//const char* htmlhover      = "#00aa00"; // html color for hovering over a menu button

#endif
