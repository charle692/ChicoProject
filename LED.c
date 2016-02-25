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
	extern avgTemperature;

	if (avgTemperature < 30) {
		usart_printf_P(PSTR("\r\n\nTemperature: %d\r\n"), avgTemperature);
		DDRH &= ~_BV(DDH3); //close red LED data register
		DDRE |= _BV(DDE5); //open blue LED data register

		PORTE |= _BV(PORTE3); //turn off green LED
		PORTH |= _BV(PORTH3); //turn off red LED
		PORTE &= ~_BV(PORTE5); //turn on blue LED
	} else if (avgTemperature >= 30 && avgTemperature < 40) {
		DDRH &= ~_BV(DDH3); //close red LED data register
		DDRE |= _BV(DDE3); //open green LED data register

		PORTE |= _BV(PORTE5); //turn off blue LED
		PORTH |= _BV(PORTH3); //turn off red LED
		PORTE &= ~_BV(PORTE3); //turn on green LED
	} else {
		DDRE &= ~_BV(DDE5); //close blue LED data register
		DDRE &= ~_BV(DDE3); //close blue LED data register
		DDRH |= _BV(DDH3); //open red LED data register

		PORTE |= _BV(PORTE3); //turn off green LED
		PORTE |= _BV(PORTE5); //turn off blue LED
		PORTH &= ~_BV(PORTH3); //turn on red LED
	}
}
