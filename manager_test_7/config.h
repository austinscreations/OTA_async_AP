/* Varibles here are filled in by the config system */

#ifndef config_h
#define config_h

char        host[32];
char        ssid[32];
char        password[64];

char        AP_SSID[32];
char        AP_PASS[64];
uint8_t     AP_CHANNEL  = 1; // not written over
uint8_t     AP_HIDDEN;
uint8_t     AP_MAX_CON  = 1; // not written over

char        mqtt_broker[40];
char        mqtt_port[8];                              // <<<< need to change declaration original = uint16_t ??????????? won't know until actully connecting to mqtt
//int         mqtt_port;
char        mqtt_username[40];
char        mqtt_password[40];

uint8_t     darkState;
char        htmltitle[40];
char        htmltype[40];
char        htmlcolor[10];
char        htmlhover[10];


#endif
