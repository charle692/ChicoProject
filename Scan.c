/*
 * movement.c
 *
 *  Created on: Feb 24, 2016
 *      Author: jayhe
 */
#include "Scan.h"
#include "ReadTmp.h"
void move()
{
	motion_init();
	extern bool rest;
	uint16_t center = 2785;
	uint16_t count = 2;
    static uint16_t spikeDirection = 0; //center is 0, left is -1, right is 1
    static uint8_t spikeThreshold = 3;//somevalue for which the target temp needs to be above the room temp measured to be considered a spike in readings
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	motion_servo_start(MOTION_SERVO_CENTER);
	while(1)
	{
		if(rest)
		{
			motion_servo_set_pulse_width(MOTION_SERVO_CENTER,2785);
			vTaskDelayUntil( &xLastWakeTime, ( 25 / portTICK_PERIOD_MS ) );
		}else
		{
		motion_servo_set_pulse_width(MOTION_SERVO_CENTER,center);

		if(center == 2785){
            if(getTempSpike()>spikeThreshold)
                spikeDirection = 0;//set the direction to be side which the thermosensor currently points at if a spike is detected at this time (some latency between turning and reading is expected and acceptable)
            vTaskDelayUntil( &xLastWakeTime, ( 25 / portTICK_PERIOD_MS ) );
            
        } 
		center += count;

		if(center > 4800){
            count = -2;
            if(getTempSpike()>spikeThreshold)
                spikeDirection = 1;//set the direction to be side which the thermosensor currently points at if a spike is detected at this time (some latency between turning and reading is expected and acceptable)
    
        }
			
		else if(center < 1100){
            count = 2;
            if(getTempSpike()>spikeThreshold)
                spikeDirection = -1;//set the direction to be side which the thermosensor currently points at if a spike is detected at this time (some latency between turning and reading is expected and acceptable)
        }
			

		motion_servo_set_pulse_width(MOTION_SERVO_CENTER,center+=count);
		vTaskDelayUntil( &xLastWakeTime, ( 2 / portTICK_PERIOD_MS ) );
		}
	}
}

