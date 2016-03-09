/*
 * Movement.c
 *
 *  Created on: Mar 9, 2016
 *      Author: jayhe
 */
#include "Movement.h"

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
	changeLED(0);
	motion_servo_stop(MOTION_WHEEL_RIGHT);
	motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, 2785);
	motion_servo_stop(MOTION_WHEEL_LEFT);
	motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, 2785);
}


