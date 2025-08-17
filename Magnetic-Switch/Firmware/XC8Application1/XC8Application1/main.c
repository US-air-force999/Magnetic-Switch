/*
 * main.c
 *
 * Created: 2/25/2025 8:52:54 PM
 *  Author: Michal
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB &= ~(1 << PB0);
	DDRB |= (1 << PB2);

	uint8_t state = 0;
	uint8_t inState = 0;

	while (1) {
		if (!(PINB & (1 << PB0)) && inState == 0) {
			if (state == 0) {
				_delay_ms(1000);
				state = 1;
				} else {
				_delay_ms(4000);
				state = 0;
			}
			inState = 1;
		}
		if (PINB & (1 << PB0)) {
			inState = 0;
		}
		if (state)
		PORTB |= (1 << PB2);
		else
		PORTB &= ~(1 << PB2);
	}
}

