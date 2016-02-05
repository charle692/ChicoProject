/*
 * LCD.c
 *
 *  Created on: Feb 3, 2016
 *      Author: jayhe
 */
#include "LCD.h";

void lcdPrint(uint8_t i)
{
	int usartfd = usartOpen( USART1_ID, 9600, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX);
	char str[2];

	usartWrite(USART1_ID,254); //command mode
	usartWrite(USART1_ID,1); //clears LCD
	extern uint8_t result[18];

	sprintf(str,"A:");
	sprintf(str + strlen(str), "%d", result[1]);
	sprintf(str + strlen(str), " ");

	usart_fprint(USART1_ID,str);

	sprintf(str,"8:");
	for(int i=3;i<18;i=i+2)
	{
		if(i!=3)sprintf(str + strlen(str), ",%d", result[i]);
		else
			sprintf(str + strlen(str), "%d", result[i]);
	}
	usart_fprint(USART1_ID,str);
}

