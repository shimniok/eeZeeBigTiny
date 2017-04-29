/** Pin test for ATtiny2313
 *
 * Author: Michael Shimniok (www.bot-thoughts.com)
 * Description: Sequentially turns on each pin on PA0-1, PB0-7 and PD0-6
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DELAY 10
#define PINS 17

enum ports { PA, PB, PD };
uint8_t pin[PINS]  = { PD0, PD1, PA1, PA0, PD2, PD3, PD4, PD5, PD6, PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7 };
uint8_t port[PINS] = { PD,  PD,  PA,  PA,  PD,  PD,  PD,  PD,  PD,  PB,  PB,  PB,  PB,  PB,  PB,  PB,  PB };


int main()
{
  uint8_t i;

  PORTA=0;
  PORTB=0;
  PORTD=0;
  DDRA=0x03;  // PA0-1 (PA2 == ~reset)
  DDRB=0xff;  // PB0-7
  DDRD=0x7f;  // PD0-6

  while (1) {
    for (i = 0; i < PINS; i++) {
      PORTA = 0;
      PORTB = 0;
      PORTD = 0;
      switch (port[i]) {
        case PA:
          PORTA = (1<<pin[i]);
          break;
        case PB:
          PORTB = (1<<pin[i]);
          break;
        case PD:
          PORTD = (1<<pin[i]);
          break;
      }
      _delay_ms(DELAY);
    }
  }
}
