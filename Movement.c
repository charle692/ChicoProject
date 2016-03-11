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
	//extern uint8_t speedDisplay;
	changeLED(0);
	motion_servo_stop(MOTION_WHEEL_RIGHT);
	//motion_servo_set_pulse_width(MOTION_WHEEL_RIGHT, 2785);
	motion_servo_stop(MOTION_WHEEL_LEFT);
	//motion_servo_set_pulse_width(MOTION_WHEEL_LEFT, 2785);
	//speedDisplay = 0;
}

//static uint16_t distance = 0;
//static uint8_t speed;

void distanceAndSpeed()
{
extern uint8_t* ticCount;
extern uint16_t distanceDisplay;
extern uint8_t speedDisplay;
double modifier = (configCPU_CLOCK_HZ / (double) 10000) *1.25;
extern int counter;

if(motion_enc_read(MOTION_WHEEL_RIGHT, ticCount) == 0)
{
	speedDisplay =0;
}

else if(motion_enc_read(MOTION_WHEEL_RIGHT, ticCount) == 1)
{
	counter++;
	distanceDisplay = counter*0.54;
	speedDisplay = 0.54 / (*ticCount/modifier);
	//distanceDisplay = distance;
	//speedDisplay = speed;
}

else if(motion_enc_read(MOTION_WHEEL_LEFT, ticCount) == 1)
{

	counter++;
	distanceDisplay = counter*0.54;
	speedDisplay = 0.54 / (*ticCount/modifier);
	//distanceDisplay = distance;
	//speedDisplay = speed;
}


}


