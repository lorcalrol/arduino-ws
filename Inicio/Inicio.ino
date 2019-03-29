/*
  ESP8266 CheckFlashConfig by Markus Sattler

  This sketch tests if the EEPROM settings of the IDE match to the Hardware

*/

uint32_t temp=2;
uint32_t hum=0;
uint32_t pres=0;

void setup(void) {
  Serial.begin(115200);
}

void loop() {
  temp=temp*2;
  hum=hum+2;
  pres=pres-2;
  Serial.printf("%u %u %u\n",temp,hum,pres);
  delay(1000);
}
