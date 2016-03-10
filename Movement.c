/*
 * Movement.c
 *
 *  Created on: Mar 9, 2016
 *      Author: jayhe
 */
#include "Movement.h"

#include "usartserial.h"

void robotForward()
{
	int right = 3000;
	int left = 2000;

	changeLED(2);
	motion_servo_start (MOTION_WHEEL_RIGHT);
	motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, right);
	motion_servo_start (MOTION_WHEEL_LEFT);
	motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, left);
}

void robotBackwards()
{
	int right = 2000;
	int left = 3000;

	changeLED(3);
	motion_servo_start (MOTION_WHEEL_RIGHT);
	motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, right);
	motion_servo_start (MOTION_WHEEL_LEFT);
	motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, left);
}

void robotLeft()
{
	int right = 2000;
	int left = 2000;

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
	changeLED(1);
	motion_servo_start (MOTION_WHEEL_RIGHT);
	motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, right);
	motion_servo_start (MOTION_WHEEL_LEFT);
	motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, left);
}

void robotSteady()
{
	extern uint8_t speed;
	changeLED(0);
	motion_servo_stop(MOTION_WHEEL_RIGHT);
	//motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, 2785);
	motion_servo_stop(MOTION_WHEEL_LEFT);
	//motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, 2785);
	speed=0;
}

void distanceAndSpeed()
{
extern uint8_t* ticCount;
extern double distance;
extern uint8_t speed;
double modifier = (configCPU_CLOCK_HZ / (double) 10000) *1.25;
extern int counter;

if(motion_enc_read(MOTION_WHEEL_RIGHT, ticCount) == 1)
{
	counter++;
	distance = counter*0.54;
	speed = 0.54 / (*ticCount / modifier);
}

if(motion_enc_read(MOTION_WHEEL_LEFT, ticCount) == 1)
{
	counter++;
	distance = counter*0.54;
	speed = 0.54 / (*ticCount / modifier);
}
}


