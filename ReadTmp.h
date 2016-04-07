/*
 * ReadTmp.h
 *
 *  Created on: Feb 3, 2016
 *      Author: jayhe
 */

// AVR includes
#include <avr/io.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"


#ifndef READTMP_H_
#define READTMP_H_

void TaskReadTemperature(uint8_t i);
int getCurrentTemp(void);


#endif /* READTMP_H_ */
