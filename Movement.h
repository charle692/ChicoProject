/*
 * Movement.h
 *
 *  Created on: Mar 9, 2016
 *      Author: jayhe
 */
#include "motion.h"

#include "LED.h"
// AVR includes
#include <avr/io.h>
#include <stdbool.h>
/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

void robotForward();
void robotBackwards();
void robotLeftRight();
void robotSteady();
void robotStop();
void distanceAndSpeed();

#endif /* MOVEMENT_H_ */
