/* Include required headers and/or libraries */
#include <Wire.h>

/* Single-pass function to configure the app */
void setup()
{
  /* Join i2c bus (address optional for master) */
  Wire.begin(0, 2);

  /* start serial for output */
  Serial.begin(115200);

  /* Begin transmission */
  Wire.beginTransmission(0x76);

  /* ctr_hum: Set humidity oversampling */
  Wire.write(0xF2);
  Wire.write(0x1);

  /* ctrl_meas: Set pressure and temperature oversampling and mode */
  Wire.write(0xF4);
  Wire.write(0x27);

  /* First register to read from */
  Wire.write(0x88);

  /* End transmission */
  Wire.endTransmission();

}

uint32_t extract(uint16_t pos)
{
  static uint32_t data;
  data = arr[pos] << 12 + arr[pos + 1] << 4 + arr[pos + 2]>>4;
  return data
}

/* Recurrent task, called forever */
void loop()
{
  /* Request data from slave with address 0x76, in this case 128 bytes, but if the memory only uses 118 bytes */
  Wire.requestFrom(0x76, 128);

  static uint8_t arr[128];

  /* Welcome message! Useful to know where  */
  Serial.printf("Ahoy! ESP8266 here!\n---\n");

  /* DUDAS: PÁGINA 18 DEL DATASHEET BME280: NOSOTROS 3.5.3, CON TODO LO QUE VIENE? */

  /* Wait for data to be available */
  uint16_t arr_i = 0;

  /* While Wire.available is not 0 */
  while (Wire.available() && arr_i <= 128)
  {
    /* Receive the bytes */
    arr[arr_i++] = Wire.read();
  }

  uint16_t arr_p = 0;
  while (Wire.available() && arr_i <= 3)
  {
    /* Receive the bytes */
    Serial.printf("todo: %02x\n", arr[arr_i]);

  }


  /* Ensure not to flood with a huge amount of fast data */
  delay(500);
}
