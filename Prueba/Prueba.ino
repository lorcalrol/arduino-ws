/* Include required headers and/or libraries */
#include <FS.h>

#define TESTFILE "/test_file.txt"

/*Define a space in memory as a new type of datablock*/
/*Without upper neither * SIN PUNTEROS*/
/*Inside C it is allowed to write in C++, BUT NOT IN THE OTHER CASE C in C++ */
/*With a unique structure, there is the possibility to obtain all in one structure in this way: */
struct nombre
{
  uint16_t a;
  uint16_t b;
  uint16_t c;
  unsigned long time;
};



/*
   Single-pass function to configure the app
*/
void setup()
{
  /* Start serial for output */
  Serial.begin(115200);

  /* Initialize the file system */
  Serial.printf("Initializing SPIFFS\n");
  if (SPIFFS.begin() == false)
  {
    Serial.printf("SPIFFS cannot be initialized\n");

    /* Stop here (WDT will reset at some point) */
    while (1) {};
  }
}
/*
   Recurrent task, called forever
*/
void loop()
{
  struct nombre nVAR;
  nVAR.a = 5;
  nVAR.b = 7;
  nVAR.c = 8;
  nVAR.time = millis();

  /*SAVE*/ 
  /*It is much more easy to save data in a struct form and to read it then*/


  /* READ */

  /* REPRESENT */


  Serial.printf("%u %u %u\n", nVAR.a, nVAR.b, nVAR.c);
  /*In operations, it is better to use unsigned variables instead of float ones*/
  /* Ensure not to flood with a huge amount of fast data */
  delay(500);
}
