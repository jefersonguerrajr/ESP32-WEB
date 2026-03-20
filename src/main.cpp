#include <Arduino.h>
#include "WiFiManager.h"
#include "api/LedController.h"

WiFiManager wifiManager;
LedController ledController(LED_PIN);

void setup() {
  Serial.begin(115200);
  wifiManager.begin();
  ledController.registerRoutes(wifiManager.getServer());
}

void loop() {
  wifiManager.handleClient();
  wifiManager.checkResetButton();
}
