#include <Wire.h>

void setup() {
  // join i2c bus (address optional for master)
  Wire.begin(0, 2);// GND

  // start serial for output
  Serial.begin(115200);
}

void loop() {
  // request 6 bytes from slave device #8
  
  Wire.beginTransmission(0x76);
  Wire.write(0xD0);
  Wire.requestFrom(0x76, 1); // EE ó EC
  char c = Wire.read();
      
  // print the character
  Serial.printf("Received: %02X\n", c);
  
  delay(500);
  
  Wire.endTransmission();
//  // slave may send less than requested
//  while (Wire.available())
//  {
//    // receive a byte as character
//    char c = Wire.read();
//      
//    // print the character
//    Serial.printf("Received: %02X\n", c);
//    Serial.printf("Hello world!\n");

//  }

}
