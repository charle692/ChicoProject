#include "FreeRTOS.h"
#include "task.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdbool.h>
#include "avr/io.h"
#include "avr/interrupt.h"

#include "sonar.h"

uint16_t getObjectDistance() {
	double objectDistance;

	DDRA |= _BV(DDA0);
	PORTA |= _BV(PA0);
	_delay_us(5);
	DDRA &= ~_BV(DDA0);
	PORTA &= ~_BV(PA0);
	TCCR1B |= (1 << CS10);
	loop_until_bit_is_set(PINA, PA0);
	TCNT1 = 0;
	loop_until_bit_is_clear(PINA, PA0);
	objectDistance = TCNT1 * 1.053;

	return (uint16_t) objectDistance;
}


