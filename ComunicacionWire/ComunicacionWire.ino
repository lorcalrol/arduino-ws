#include <Wire.h>

void setup() {
  // join i2c bus (address optional for master)
  Wire.begin(0, 2);// GND

  // start serial for output
  Serial.begin(115200);
}

void loop() {
  
  Wire.beginTransmission(0x76); // start a connection with slave device
  Wire.write(0xFD);             // select the register address
  Wire.endTransmission();
  
  Wire.requestFrom(0x76, 2);    // request 2 bytes from slave device #0x76

  // slave may send less than requested
  while (Wire.available())
  {
    // receive a byte as character
    uint8_t hum1 = Wire.read();   // read
    uint8_t hum2 = Wire.read();   // read the following register address

    // print the character
    Serial.printf("Received: %u %u \n", hum1, hum2);
  } 
  delay(500);
  
}
