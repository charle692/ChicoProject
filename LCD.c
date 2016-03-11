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
	usartWrite(USART1_ID,1); //clears LCD
	extern uint8_t result[18];
	extern uint8_t distanceDisplay;
	//usart_printf_P(PSTR("Distance: %d"), distance);
	extern uint8_t speedDisplay;

	for(int i=3;i<18;i=i+2) {
		if(i<=9) {
			rightAverage += result[i];
		} else {
			leftAverage += result[i];
		}
	}

	sprintf(str, "T:");
	sprintf(str + strlen(str), "%" PRIu8, speedDisplay);
	sprintf(str + strlen(str), " ");
	usart_fprint(USART1_ID,str);

	sprintf(str, "D:");
	sprintf(str + strlen(str), "%" PRIu16, distanceDisplay);
	sprintf(str + strlen(str), " ");
	usart_fprint(USART1_ID,str);

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
	sprintf(str + strlen(str), " ");
	usart_fprint(USART1_ID,str);
}

