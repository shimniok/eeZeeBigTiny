eeZeeBigTiny is a breakout & target board for the ATtiny4313 family of 20-pin MCUs.

# Writing Software
To write code for ATtiny, you can use:

* AVR Studio
* Atmel Studio
* Eclipse and the AVR Plugin
* Arduino IDE - here's how (Tiny85, 84, 4313 families)

# Programming (Flashing) Your Chip
You can use any AVR ISP programmer with 

* [Pololu AVR Programmer](https://www.pololu.com/product/1300)
* [AVR Dragon](http://www.newark.com/atmel/atavrdragon/in-circuit-debug-prog-jtag-spi/dp/68T2063?ost=avr+dragon)
* [AVRISP MkII](http://www.newark.com/atmel/atavrisp2/in-system-programmer-usb-8bit/dp/68T2065?ost=avrisp)
* Your Arduino ([here's how](http://arduino.cc/en/Tutorial/ArduinoISP))
* or other AVR ISP compatible hardware.

# ISP Header
When it's time to plug in your 6-pin programming cable, locate the white rectangle next to the ISP header pin 1. The cable should have a red stripe marking pin 1 and/or a bump adjacent to pin 3.

![Image of AVRISP Header](http://www.batsocks.co.uk/img/info_isp/ISP%206%20way%20pinout.png)

# Example Code
This example code sequentially turns on one of each of the Tiny's pins. Repository, main.c, text.hex
```
/** Pin test for ATtiny2313
 *
 * Author: Michael Shimniok (www.bot-thoughts.com)
 * Description: Sequentially turns on each pin on PA0-1, PB0-7 and PD0-6
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main()
{
  char i;

  PORTA=0;
  PORTB=0;
  PORTD=0;
  DDRA=0x03;  // PA0-1 (PA2 == ~reset)
  DDRB=0xff;  // PB0-7
  DDRD=0x7f;  // PD0-6

  while (1) {
    for (i = 0 ; i < 2; i++) {
      PORTA = (1 << i);
      _delay_ms(300);
    }
    PORTA = 0;

    for (i = 0; i < 8; i++) {
      PORTB = (1 << i);
      _delay_ms(300);
    }
    PORTB = 0;

    for (i = 0; i < 7; i++) {
      PORTD = (1 << i);
      _delay_ms(300);
    }
    PORTD = 0;

  }

}
```

# Operating Conditions
Please use your ATtiny breakout boards with regulated supplies of 5V or less, with minimal ripple, at temperatures around 25C (77F). Do not use the boards in higher temperature conditions or with higher sustained voltages.
