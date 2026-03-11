#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

const char* ssid     = "Wifi";
const char* password = "Senha";

WebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>ESP32 Web</title>
    <style>body{font-family:Arial; text-align:center; margin:2rem;} button{padding:0.5rem 1rem;}</style>
  </head>
  <body>
    <h1>ESP32 Web Page</h1>
    <p>IP: <span id="ip">---</span></p>
    <p><a href="/toggle"><button>Toggle LED</button></a></p>
    <script>fetch('/ip').then(r=>r.text()).then(t=>document.getElementById('ip').innerText=t);</script>
  </body>
</html>

)rawliteral";

void handleRoot() {
  server.send_P(200, "text/html", index_html);
}

void handleIP() {
  server.send(200, "text/plain", WiFi.localIP().toString());
}

void handleToggle() {
  int state = digitalRead(2);
  digitalWrite(2, !state);
  server.sendHeader("Location", "/", true);
  server.send(302, "text/plain", "");
}

void handleApiAcender() {
  int state = digitalRead(2);
  int newState = !state;
  digitalWrite(2, newState);
  bool isOn = (newState == LOW);
  StaticJsonDocument<200> doc;
  doc["led"] = isOn ? "on" : "off";
  String output;
  serializeJson(doc, output);
  server.send(200, "application/json", output);
}

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(2, OUTPUT);

  Serial.print("Conectando a rede WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Aguarda até conectar, piscando o LED enquanto tenta
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    digitalWrite(2, LOW);
    delay(250);
    digitalWrite(2, HIGH);
    delay(250);
  }

  Serial.println();
  Serial.println("WiFi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Rotas do servidor web
  server.on("/", handleRoot);
  server.on("/ip", handleIP);
  server.on("/toggle", handleToggle);
  server.on("/api/acender", handleApiAcender);
  server.begin();
  Serial.println("HTTP server started on port 80");
}

void loop() {
  server.handleClient();
}
