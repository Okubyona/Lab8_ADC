/*	Author: abazu001
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #4
 *	Exercise Description: [ Design a system, using a bank of eight LEDs, where
            the number of LEDs illuminated is a representation of how much light
            is detected. For example, when more light is detected, more LEDs are
            illuminated. ]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *  Demo Link:
 *  https://drive.google.com/file/d/1CyGrCGEDCnzz_Zjo9EtKRk7L-WNxu4VI/view?usp=sharing
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

const short MAX_LIGHT = 0x190;
//const short MIN_LIGHT = 0x07C;    // Never actually used


void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
    // ADEN: setting this bit eneables analog-to-digital conversion.
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

    unsigned char eighthMax = MAX_LIGHT / 0x08;

    /* Insert your solution below */
    while (1) {
        potential = ADC;
        if (potential <= eighthMax / 2) { tmpB = 0; }
        else if (potential <= eighthMax) {tmpB = 0x01; }
        else if (potential <= eighthMax * 2) {tmpB = 0x03; }
        else if (potential <= eighthMax * 3) {tmpB = 0x07; }
        else if (potential <= eighthMax * 4) {tmpB = 0x0F; }
        else if (potential <= eighthMax * 5) {tmpB = 0x1F; }
        else if (potential <= eighthMax * 6) {tmpB = 0x3F; }
        else if (potential <= eighthMax * 7) {tmpB = 0x7F; }
        else if (potential <= eighthMax * 8) {tmpB = 0xFF; }

        PORTB = tmpB;

    }
    return 1;
}
