#ifndef BASE_HTTP_SERVER_H
#define BASE_HTTP_SERVER_H

#ifdef ESP8266

#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266HTTPUpdateServer.h>
#define WebServer ESP8266WebServer
#define ESPmDNS ESP8266mDNS
#define UPDATE_SIZE_UNKNOWN 0xFFFFFFFF

#else // for ESP32

#include <WebServer.h>
#include <Update.h>
#define ESPHTTPUpdateServer ESP32HTTPUpdateServer

#endif

#define ESP32_WEB_UPDATE_SUCCESS_RESPONSE "<META http-equiv=\"refresh\" content=\"10;URL=/\">Update Success! Rebooting...\n"
#define ESP32_WEB_UPDATE_HTML "<html><body><form method='POST' action='' enctype='multipart/form-data'><input type='file' name='update'><input type='submit' value='Update'></form></body></html>"

class BaseHTTPServer
{
private:
  WebServer *_server;

  String _username;
  String _password;
  bool _serialDebugging;

public:
  BaseHTTPServer(bool serialDebugging = false);

  void setup(WebServer *server, const char *path = "/", const char *username = "", const char *password = "");
};

#endif