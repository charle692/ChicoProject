/*
 * LCD.c
 *
 *  Created on: Feb 3, 2016
 *      Author: jayhe
 */
#include "LCD.h";

void lcdPrint(uint8_t i)
{
	int usartfd = usartOpen(USART1_ID, 9600, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX);
	char str[2];
	uint8_t rightAverage;
	uint8_t leftAverage;


	usartWrite(USART1_ID,254); //command mode
	usartWrite(USART1_ID,1);//clear lcd

	//first line
	usartWrite(USART1_ID,254);
	usartWrite(USART1_ID,128);
	extern uint8_t result[18];
	extern uint16_t distanceDisplay;
	extern uint16_t objectDistance;
	extern uint8_t speedDisplay;

	for(int i=3;i<18;i=i+2) {
		if(i<=9) {
			rightAverage += result[i];
		} else {
			leftAverage += result[i];
		}
	}

	sprintf(str, "S:");
	sprintf(str + strlen(str), "%" PRIu8, speedDisplay);
	sprintf(str + strlen(str), " ");
	usart_fprint(USART1_ID,str);

	sprintf(str, "D:");
	sprintf(str + strlen(str), "%" PRIu16, distanceDisplay);
	usart_fprint(USART1_ID,str);

	sprintf(str, " O:");
	sprintf(str + strlen(str), "%" PRIu16, objectDistance);
	usart_fprint(USART1_ID,str);

	//second line
	usartWrite(USART1_ID,254);
	usartWrite(USART1_ID,192); //command mode

	sprintf(str,"A:");
	sprintf(str + strlen(str), "%d", result[1]);
	sprintf(str + strlen(str), " ");
	usart_fprint(USART1_ID,str);

	sprintf(str, "AR:");
	sprintf(str + strlen(str), "%d", rightAverage/4);
	sprintf(str + strlen(str), " ");
	usart_fprint(USART1_ID,str);

	sprintf(str, "AL:");
	sprintf(str + strlen(str), "%d", leftAverage/4);
	usart_fprint(USART1_ID,str);
}

