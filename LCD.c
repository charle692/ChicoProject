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

char *convert(uint8_t *a)
{
  char* buffer2;
  int i;

  buffer2 = malloc(9);
  if (!buffer2)
    return NULL;

  buffer2[8] = 0;
  for (i = 0; i <= 7; i++)
    buffer2[7 - i] = (((*a) >> i) & (0x01)) + '0';

  puts(buffer2);

  return buffer2;
}

