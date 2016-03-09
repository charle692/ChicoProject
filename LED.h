/*
 * LED.h
 *
 *  Created on: Feb 24, 2016
 *      Author: ryanoconnor
 */

#ifndef LED_H_
#define LED_H_

/* --Includes-- */
// AVR includes
#include <avr/io.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
/* External functions */
void changeLED(uint8_t i);

#endif /* LED_H_ */
