/* Include required headers and/or libraries */
#include <Wire.h>

/* Single-pass function to configure the app */
void setup()
{
  /* Join i2c bus (address optional for master) */
  Wire.begin(0, 2);

  /* start serial for output */
  Serial.begin(115200);
}

/* Recurrent task, called forever */
void loop()
{
  /* Welcome message! Useful to know where  */
  Serial.printf("Ahoy! ESP8266 here!\n---\n");

  /* Begin transmission */
  Wire.beginTransmission(0x76);

  /* ctr_hum: Set humidity oversampling */
  Wire.write(0xF2);
  Wire.write(B001);

  /* ctrl_meas: Set pressure and temperature oversampling and mode */
  Wire.write(0xF4);
  Wire.write(B00100111);

  /* First register to read from */
  Wire.write(0xF7);

  /* End transmission */
  Wire.endTransmission();

  /* Request data from slave with address 0x76 */
  Wire.requestFrom(0x76, 8);

  /* DUDAS: PÁGINA 18 DEL DATASHEET BME280: NOSOTROS 3.5.3, CON TODO LO QUE VIENE? */
  /*        MEJOR FORMA DE PONER EL WHILE?? TRANSMISSION, WRITE Y REQUEST DENTRO O FUERA? ALGUNAS MEDICIONES ME DAN 0 */
  /*        LOS 20 BITS ESTÁN BIEN EN 32 BITS O HAY QUE APLICAR TRIMMING 4.2.2 U OTRA COSA? */

  /* Wait for data to be available */
  while (Wire.available())
  {
    /* Receive the bytes */
    uint8_t pre1 = Wire.read();
    uint8_t pre2 = Wire.read();
    uint8_t pre3 = Wire.read();
    uint32_t pre = pre1 << 12 + pre2 << 4 + pre3 >> 4;

    uint8_t tem1 = Wire.read();
    uint8_t tem2 = Wire.read();
    uint8_t tem3 = Wire.read();
    uint32_t tem = tem1 << 12 + tem2 << 4 + tem3 >> 4;

    uint8_t hum1 = Wire.read();
    uint8_t hum2 = Wire.read();
    uint16_t hum = hum1 << 8 + hum2;

    /* Send it to console/monitor */
    Serial.printf("Presure: %u %u %u\n", pre1, pre2, pre3);
    Serial.printf("Pressure: %u\n", pre);

    Serial.printf("Temperature: %u %u %u\n", tem1, tem2, tem3);
    Serial.printf("Temperature: %u\n", tem);

    Serial.printf("Humidity: %u %u\n", hum1, hum2);
    Serial.printf("Humidity: %u\n", hum);

  }

  /* Ensure not to flood with a huge amount of fast data */
  delay(500);
}
