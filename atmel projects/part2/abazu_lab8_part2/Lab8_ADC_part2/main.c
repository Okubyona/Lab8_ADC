/*
 * Lab8_ADC_part2.c
 *
 * Created: 11/5/2019 08:49:03 PM
 * Author : Andrew
 */ 

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#define MAX_LIGHT 0x3FC
#define MIN_LIGHT 0x07C

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion
	// ADATE: setting this bit enables auto-triggering. SInce we are
	//        in Free Running Mode, a new conversion will trigger whenever
	//        the previous conversion completes.
}


int main(void) {
	/* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00;

	ADC_init();

	unsigned short potential = 0x00;
	unsigned char tmpB = 0x00;



	/* Insert your solution below */
	while (1) {
		potential = ADC;
		if (potential >= MAX_LIGHT / 2) { tmpB = 0x01; }
		else { tmpB = 0x00; }

		PORTB = tmpB;

	}
	return 1;
}
