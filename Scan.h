/*
 * Movement.h
 *
 *  Created on: Feb 24, 2016
 *      Author: jayhe
 */

#include "motion.h"
#include <stdbool.h>
// AVR includes
#include <avr/io.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"


#ifndef MOVEMENT_H_
#define MOVEMENT_H_

void move();
#endif /* MOVEMENT_H_ */
