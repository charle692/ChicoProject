/*
 * ReadTmp.h
 *
 *  Created on: Feb 3, 2016
 *      Author: jayhe
 */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include <avr/io.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
/* serial interface include file. */
#include "usartserial.h"

#ifndef READTMP_H_
#define READTMP_H_

void TaskReadTemperature(uint8_t i);


#endif /* READTMP_H_ */
