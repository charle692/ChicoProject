/*
 * Movement.c
 *
 *  Created on: Mar 9, 2016
 *      Author: jayhe
 */
#include "Movement.h"

#include "usartserial.h"

void robotBackward()
{
	int right = 3000;
	int left = 2000;
	extern bool rest;
	rest = false;
	changeLED(3);
	motion_servo_start (MOTION_WHEEL_RIGHT);
	motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, right);
	motion_servo_start (MOTION_WHEEL_LEFT);
	motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, left);
}

void robotForward()
{
	int right = 2000;
	int left = 3000;
	extern bool rest;
	rest = false;
	changeLED(2);
	motion_servo_start (MOTION_WHEEL_RIGHT);
	motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, right);
	motion_servo_start (MOTION_WHEEL_LEFT);
	motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, left);
}

void robotLeft()
{
	int right = 2000;
	int left = 2000;
	extern bool rest;
	rest = false;
	changeLED(1);
	motion_servo_start (MOTION_WHEEL_RIGHT);
	motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, right);
	motion_servo_start (MOTION_WHEEL_LEFT);
	motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, left);
}

void robotRight()
{
	int right = 3000;
	int left = 3000;
	extern bool rest;
	rest = false;
	changeLED(1);
	motion_servo_start (MOTION_WHEEL_RIGHT);
	motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, right);
	motion_servo_start (MOTION_WHEEL_LEFT);
	motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, left);
}

void robotSteady()
{
	extern bool rest;
	changeLED(0);
	motion_servo_stop(MOTION_WHEEL_RIGHT);
	motion_servo_stop(MOTION_WHEEL_LEFT);
	rest = true;
}

void distanceAndSpeed()
{
extern uint8_t* ticCount;
extern uint16_t distanceDisplay;
extern uint8_t speedDisplay;
double modifier = (configCPU_CLOCK_HZ / (double) 10000) *1.25;
extern int counter;

if(motion_enc_read(MOTION_WHEEL_RIGHT, ticCount) == 1)
{
	counter++;
	distanceDisplay = counter*0.54;
	speedDisplay = 0.54 / (*ticCount/modifier);
}

if(motion_enc_read(MOTION_WHEEL_LEFT, ticCount) == 1)
{
	counter++;
	distanceDisplay = counter*0.54;
	speedDisplay = 0.54 / (*ticCount/modifier);
}


}


