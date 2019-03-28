/*
  ESP8266 CheckFlashConfig by Markus Sattler

  This sketch tests if the EEPROM settings of the IDE match to the Hardware

*/

uint32_t var1=2;
uint32_t var2=0;
uint32_t var3=0;

void setup(void) {
  Serial.begin(115200);
}

void loop() {
  var1=var1*2;
  var2=var2+2;
  var3=var3-2;
  Serial.printf("%u %u %u\n",var1,var2,var3);
  delay(1000);
}
