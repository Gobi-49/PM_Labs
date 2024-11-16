#include <avr/io.h>
#include <util/delay.h>
 
int main() {
	/* Setăm pinul 7 al portului D ca pin de ieșire. */
	DDRD |= (1 << PD7) | (1 << PD5);//leduri
  
  DDRB &= ~(1 << PB2); // buton
  PORTB |= (1 << PB2);
  
	while(1) {
    PORTD |= (1 << PD7);
    if(!(PINB & (1 << PB2))) {
      PORTD |= (1 << PD5);
    }
	}
 
	return 0;
}