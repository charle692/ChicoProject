/*
 * movement.c
 *
 *  Created on: Feb 24, 2016
 *      Author: jayhe
 */
#include "Scan.h"

void move()
{
	motion_init();
	uint16_t center = 2785;
	uint16_t count = 2;

	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	motion_servo_start(MOTION_SERVO_CENTER);
	while(1)
	{
		motion_servo_start(MOTION_SERVO_CENTER);
		motion_servo_set_pulse_width(MOTION_SERVO_CENTER,center);

		if(center == 2785) vTaskDelayUntil( &xLastWakeTime, ( 25 / portTICK_PERIOD_MS ) );
		center += count;

		if(center > 4800)
			count = -2;
		else if(center < 1100)
			count = 2;

		motion_servo_set_pulse_width(MOTION_SERVO_CENTER,center+=count);
		vTaskDelayUntil( &xLastWakeTime, ( 2 / portTICK_PERIOD_MS ) );

	}
}

