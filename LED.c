/*
 * LED.c
 *
 *  Created on: Feb 24, 2016
 *      Author: ryanoconnor
 */

/* Module header */
#include "lED.h"

void changeLED(uint8_t i) {

	//spin
	if (i == 1) {//blue
		DDRH &= ~_BV(DDH3); //close red LED data register
		DDRE |= _BV(DDE5); //open blue LED data register

		PORTE |= _BV(PORTE3); //turn off green LED
		PORTH |= _BV(PORTH3); //turn off red LED
		PORTE &= ~_BV(PORTE5); //turn on blue LED
		//forward
	} else if (i == 2) {//green
		DDRH &= ~_BV(DDH3); //close red LED data register
		DDRE |= _BV(DDE3); //open green LED data register

		PORTE |= _BV(PORTE5); //turn off blue LED
		PORTH |= _BV(PORTH3); //turn off red LED
		PORTE &= ~_BV(PORTE3); //turn on green LED
		//backwards
	} else if (i == 3) { //red
		DDRE &= ~_BV(DDE5); //close blue LED data register
		DDRE &= ~_BV(DDE3); //close green LED data register
		DDRH |= _BV(DDH3); //open red LED data register

		PORTE |= _BV(PORTE3); //turn off green LED
		PORTE |= _BV(PORTE5); //turn off blue LED
		PORTH &= ~_BV(PORTH3); //turn on red LED
	} else { //white
		DDRE |= _BV(DDE5); //open blue LED data register
		DDRE |= _BV(DDE3); //open green LED data register
		DDRH |= _BV(DDH3); //open white LED data register
		PORTH &= ~_BV(PORTH3); //turn on red LED
		PORTE &= ~_BV(PORTE5); //turn on blue LED
		PORTE &= ~_BV(PORTE3); //turn on green LED
	}
}
