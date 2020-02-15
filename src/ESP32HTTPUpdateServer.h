#ifndef ESP32_HTTP_UPDATE_SERVER_H
#define ESP32_HTTP_UPDATE_SERVER_H

/*
  Based on the HTTP update exemple of ESP32 core
*/



#ifdef ESP8266

  #include <ESP8266WebServer.h>
  #include <ESP8266HTTPUpdateServer.h>
  #include <ESP8266HTTPUpdateServer.h>
  #define WebServer ESP8266WebServer 
  #define ESPmDNS ESP8266mDNS
  #define ESPHTTPUpdateServer ESP8266HTTPUpdateServer
   #define UPDATE_SIZE_UNKNOWN 0xFFFFFFFF

#else // for ESP32

#include <WebServer.h>
#include <Update.h>
#define ESPHTTPUpdateServer ESP32HTTPUpdateServer

#endif



#define ESP32_WEB_UPDATE_HTML "<html><body><form method='POST' action='' enctype='multipart/form-data'><input type='file' name='update'><input type='submit' value='Update'></form></body></html>"
#define ESP32_WEB_UPDATE_SUCCESS_RESPONSE "<META http-equiv=\"refresh\" content=\"10;URL=/\">Update Success! Rebooting...\n"

class ESP32HTTPUpdateServer
{
private:
  WebServer* _server;

  String _username;
  String _password;
  bool _serialDebugging;

public:
  ESP32HTTPUpdateServer(bool serialDebugging = false);
  

  void setup(WebServer* server, const char* path = "/", const char* username = "", const char* password = "");

  
};

#endif