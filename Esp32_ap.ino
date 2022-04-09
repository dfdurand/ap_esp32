#include <WiFi.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include "webpage.h"

const char* ssid = "ALT_ESP32";
const char* password = "33331111";


WebServer server(80); //definir le server 


void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  server.begin(); //démarrer le serveur
 
  IPAddress ServerIP = WiFi.softAPIP(); // obtenir adresse IP
  Serial.print("\nServer IP is: "); 
  Serial.println(ServerIP);
  
  server.on("/", handleRoot); //associer la reponse à la requete
  
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  server.send(200, "text/html", webPage); //webpage défini dans webpage
}
