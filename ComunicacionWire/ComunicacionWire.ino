#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

#include <Wire.h>

void setup() {
  // join i2c bus (address optional for master)
  Wire.begin(0, 2);// GND

  // start serial for output
  Serial.begin(115200);
}

void loop() {
  // request 6 bytes from slave device #8
  Wire.requestFrom(0xEC, 1); // EE ó EC

  // slave may send less than requested
  while (Wire.available())
  {
    // receive a byte as character
    char c = Wire.read();
    int32_t d =ESP.getChipId();

    // print the character
    Serial.printf("Received: %02X\n", c);
    Serial.println(d);
    Serial.printf("Hello world!");
  }

   Serial.printf("Hello world2!");
  delay(500);
}
