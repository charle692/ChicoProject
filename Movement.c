/*
 * movement.c
 *
 *  Created on: Feb 24, 2016
 *      Author: jayhe
 */
#include "Movement.h"

void move()
{
	motion_init();
	while(1)
	{
		motion_servo_start(MOTION_WHEEL_LEFT);
		//motion_servo_strat(MOTION_WHEEL_RIGHT);
		//motion_servo_start(MOTION_SERVO_CENTER);
	}
}


