/*
 * movement.c
 *
 *  Created on: Feb 24, 2016
 *      Author: jayhe
 */
#include "Scan.h"
#include "ReadTmp.h"
#include "custom_timer.h"
//#include "usartserial.h"
#include "Movement.h"

void move() {
	motion_init();
	extern bool rest;
	extern avgTemperature;
	extern char mode;
	extern long scanTime;
	extern bool panic;
	extern bool target;
	uint16_t center = 2785;
	uint16_t saveCenter = 0;
	uint16_t count = 2;
	int spikeDirection = 0; //center is 0, left is -1, right is 1
	int spikeThreshold = 2;//somevalue for which the target temp needs to be above the room temp measured to be considered a spike in readings
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	motion_servo_start(MOTION_SERVO_CENTER);

	while(1) {
		if ((time_in_milliseconds()/1000 - scanTime < 30 && panic == false) || target || mode == 'c') {
			if(rest) {
				motion_servo_set_pulse_width(MOTION_SERVO_CENTER,2785);
				vTaskDelayUntil( &xLastWakeTime, ( 25 / portTICK_PERIOD_MS ) );
			} else if(target) {
				motion_servo_set_pulse_width(MOTION_SERVO_CENTER,saveCenter);
				vTaskDelayUntil( &xLastWakeTime, ( 2 / portTICK_PERIOD_MS ) );
				if (getTempSpike()<5) {
					scanTime = time_in_milliseconds()/1000;
					target = false;
				}
			} else {
				motion_servo_set_pulse_width(MOTION_SERVO_CENTER,center);

				if(center == 2785){
					if (mode == 'a') {
						if(getTempSpike()>=spikeThreshold){
							spikeDirection = 0;//set the direction to be side which the thermosensor currently points at if a spike is detected at this time (some latency between turning and reading is expected and acceptable)
							if (getCurrentTemp() > 20) {
								target = true;
							}
						}
					}
					vTaskDelayUntil( &xLastWakeTime, ( 25 / portTICK_PERIOD_MS ) );

				}
				center += count;

				if(center > 4800){
					count = -2;
					if (mode == 'a') {
						if(getTempSpike()>=spikeThreshold){
							spikeDirection = 1;//set the direction to be side which the thermosensor currently points at if a spike is detected at this time (some latency between turning and reading is expected and acceptable)
							if (getCurrentTemp() > 20) {
								target= true;
							}
						}
					}
				} else if(center < 1100){
					count = 2;
					if (mode == 'a') {
						if(getTempSpike()>=spikeThreshold){
							spikeDirection = 2;//set the direction to be side which the thermosensor currently points at if a spike is detected at this time (some latency between turning and reading is expected and acceptable)
							if (getCurrentTemp() > 20) {
								target = true;
							}
						}
					}
				}
				center+=count;
				saveCenter = center;

				motion_servo_set_pulse_width(MOTION_SERVO_CENTER,saveCenter);
				vTaskDelayUntil( &xLastWakeTime, ( 2 / portTICK_PERIOD_MS ) );
			}
		} else {
			if (panic == false) {
				panic = true;
				scanTime = time_in_milliseconds()/1000;
				robotRight();
				vTaskDelayUntil( &xLastWakeTime, ( 2 / portTICK_PERIOD_MS ) );
			} else if (time_in_milliseconds()/1000 - scanTime >= 60) {
				panic = false;
				scanTime = time_in_milliseconds()/1000;
				robotStop();
				rest = false;
				vTaskDelayUntil( &xLastWakeTime, ( 2 / portTICK_PERIOD_MS ) );
			}
		}
	}
}

