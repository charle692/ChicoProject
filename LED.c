/*
 * LED.c
 *
 *  Created on: Feb 24, 2016
 *      Author: ryanoconnor
 */

/* --Includes-- */
#include <stdio.h>

/*AVR includes*/
#include "avr/io.h"

/* External includes */
#include "BitDefinitions.h"

/* Module header */
#include "lED.h"

void changeLED(uint8_t i) {
	extern _Bool movingForwards;
	extern _Bool movingBackwards;
	extern _Bool spinning;

	if (spinning) {//blue
		DDRH &= ~_BV(DDH3); //close red LED data register
		DDRE |= _BV(DDE5); //open blue LED data register

		PORTE |= _BV(PORTE3); //turn off green LED
		PORTH |= _BV(PORTH3); //turn off red LED
		PORTE &= ~_BV(PORTE5); //turn on blue LED
	} else if (movingForwards) {//green
		DDRH &= ~_BV(DDH3); //close red LED data register
		DDRE |= _BV(DDE3); //open green LED data register

		PORTE |= _BV(PORTE5); //turn off blue LED
		PORTH |= _BV(PORTH3); //turn off red LED
		PORTE &= ~_BV(PORTE3); //turn on green LED
	} else if (movingBackwards) { //red
		DDRE &= ~_BV(DDE5); //close blue LED data register
		DDRE &= ~_BV(DDE3); //close green LED data register
		DDRH |= _BV(DDH3); //open red LED data register

		PORTE |= _BV(PORTE3); //turn off green LED
		PORTE |= _BV(PORTE5); //turn off blue LED
		PORTH &= ~_BV(PORTH3); //turn on red LED
	} else { //white
		DDRE |= _BV(DDE5); //open blue LED data register
		DDRE |= _BV(DDE3); //open green LED data register
		DDRH |= _BH(DDH3); //open white LED data register
		PORTH &= ~_BV(PORTH3); //turn on red LED
		PORTE &= ~_BV(PORTE5); //turn on blue LED
		PORTE &= ~_BV(PORTE3); //turn on green LED
	}
}
