/*
 * movement.c
 *
 *  Created on: Feb 24, 2016
 *      Author: jayhe
 */
#include "Scan.h"
#include "ReadTmp.h"
#include "custom_timer.h"
#include "usartserial.h"
#include "Movement.h"

void move()
{
	motion_init();
	extern bool rest;
	extern avgTemperature;
	bool panic = false;
	bool target = false;
	uint16_t center = 2785;
	uint16_t saveCenter = 0;
	uint16_t count = 2;
	int usartfd;
	int spikeDirection = 0; //center is 0, left is -1, right is 1
	int spikeThreshold = 5;//somevalue for which the target temp needs to be above the room temp measured to be considered a spike in readings
	long scanTime = time_in_milliseconds()/1000;
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	usartfd = usartOpen(USART1_ID, 115200, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX);
	motion_servo_start(MOTION_SERVO_CENTER);

	while(1) {
//		usart_printf_P(PSTR("\r\n\nTime: %u\r\n"), time_in_milliseconds() - scanTime);

		if ((time_in_milliseconds()/1000 - scanTime < 30 && panic == false) || target) {
			if(rest) {
				motion_servo_set_pulse_width(MOTION_SERVO_CENTER,2785);
				vTaskDelayUntil( &xLastWakeTime, ( 25 / portTICK_PERIOD_MS ) );
			} else if(target) {
				motion_servo_set_pulse_width(MOTION_SERVO_CENTER,saveCenter);
				vTaskDelayUntil( &xLastWakeTime, ( 2 / portTICK_PERIOD_MS ) );
				if (getTempSpike()<spikeThreshold) {
					scanTime = time_in_milliseconds()/1000;
					target = false;
					usart_printf_P(PSTR("\r\n\nTarget gone.\r\n"));
				}
				usart_printf_P(PSTR("\r\n\nTarget found. \r\n"));
			} else {
				motion_servo_set_pulse_width(MOTION_SERVO_CENTER,center);

				if(center == 2785){
					if(getTempSpike()>=spikeThreshold){
						spikeDirection = 0;//set the direction to be side which the thermosensor currently points at if a spike is detected at this time (some latency between turning and reading is expected and acceptable)
						if (getCurrentTemp() > 20) {
							target = true;
						}
					}
					vTaskDelayUntil( &xLastWakeTime, ( 25 / portTICK_PERIOD_MS ) );

				}
				center += count;

				if(center > 4800){
					count = -2;
					if(getTempSpike()>=spikeThreshold){
						spikeDirection = 1;//set the direction to be side which the thermosensor currently points at if a spike is detected at this time (some latency between turning and reading is expected and acceptable)
						if (getCurrentTemp() > 20) {
							target= true;
						}
					}
				} else if(center < 1100){
					count = 2;
					if(getTempSpike()>=spikeThreshold){
						spikeDirection = 2;//set the direction to be side which the thermosensor currently points at if a spike is detected at this time (some latency between turning and reading is expected and acceptable)
						if (getCurrentTemp() > 20) {
							target = true;
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
				scanTime = time_in_milliseconds();
				robotRight();
				vTaskDelayUntil( &xLastWakeTime, ( 2 / portTICK_PERIOD_MS ) );
			} else if (time_in_milliseconds() - scanTime >= 60000) {
				panic = false;
				scanTime = time_in_milliseconds();
				robotStop();
				vTaskDelayUntil( &xLastWakeTime, ( 2 / portTICK_PERIOD_MS ) );
			}
		}
	}
}

