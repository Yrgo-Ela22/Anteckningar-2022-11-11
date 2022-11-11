/********************************************************************************
* main.c: Demonstration av dynamisk vektor för lagring och styrning av multipla
*         lysdioder.
********************************************************************************/
#include "led.h"
#include "button.h"
#include "led_vector.h"

/********************************************************************************
* main: Ansluter fem lysdioder till pin 6 - 10 och lagrar i en dynamisk vektor.
*       Ansluter en tryckknapp till pin 13. Vid nedtryckning av tryckknappen
*       blinkar lysdioderna i en slinga var 100:e millisekund, annars blinkar
*       de kollektivt var 500:e millisekund.
********************************************************************************/
int main(void)
{ 
   struct led l1, l2, l3, l4, l5;
   struct button b1;
   struct led_vector v1;

   led_init(&l1, 6);
   led_init(&l2, 7);
   led_init(&l3, 8);
   led_init(&l4, 9);
   led_init(&l5, 10);

   button_init(&b1, 13);
   led_vector_init(&v1);

   led_vector_push(&v1, &l1);
   led_vector_push(&v1, &l2);
   led_vector_push(&v1, &l3);
   led_vector_push(&v1, &l4);
   led_vector_push(&v1, &l5);

   while (1)
   {
      if (button_is_pressed(&b1))
      {
         led_vector_blink_sequentially(&v1, 100);
      }
      else
      {
         led_vector_blink_colletively(&v1, 500);
      }
   }

   return 0;
}

