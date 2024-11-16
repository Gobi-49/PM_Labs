#include <util/delay.h>
#include <usart.c>
#include <string.h>
#include <avr/interrupt.h>

#define CLOCK_SPEED 12000000
#define BAUD 9600
#define MYUBRR CLOCK_SPEED/16/BAUD-1

volatile int mil;

char s[50] = "timp\n";

ISR(TIMER0_COMPA_vect)
{
  USART0_print(s);
}


int main() {
	DDRB &= ~(1 << PB2); // input
  PORTB |= (1 << PB2);
  USART0_init(MYUBRR);


  TCCR0A |= (1 << WGM01);
  TCCR0B |= (1 << CS01) | (1 << CS00);
  OCR0A = 2;


  while (1){}
  
	return 0;
}
