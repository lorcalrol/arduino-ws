#include <Wire.h>

void setup() {
  // join i2c bus (address optional for master)
  Wire.begin(0, 2);// GND

  // start serial for output
  Serial.begin(115200);
}

void loop() {
  // request 6 bytes from slave device #8
  Wire.requestFrom(0x76, 1); // EE ó EC

  // slave may send less than requested
  while (Wire.available())
  {
    // receive a byte as character
    char c = Wire.read();
    char d = ESP.getChipId();
      
    // print the character
    Serial.printf("Received: %02X\n", c);
    Serial.printf("Received: %02X\n", d);
    Serial.printf("Hello world!\n");
    Serial.print(d);

  }

  Serial.printf("Hello world2!\n");
  delay(500);
}
