////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////    main.c
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include <avr/io.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/* serial interface include file. */
#include "usartserial.h"

/*-----------------------------------------------------------*/
/* Create a handle for the serial port. */
//extern xComPortHandle xSerialPort;

static void TaskTurnOnLED(int temperature); // Main Arduino Mega 2560, Freetronics EtherMega (Red) LED Blink

/*-----------------------------------------------------------*/

/* Main program loop */
//int main(void) __attribute__((OS_main));
int usartfd;

int main(void)
{
    // turn on the serial port for debugging or for other USART reasons.
	usartfd = usartOpen(USART1_ID, 9600, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX); //  serial port: WantedBaud, TxQueueLength, RxQueueLength (8n1)
	usart_fprint(USART1_ID, "HELLO");

	//PUT IN COMMAND MODE FIRST THEN SEND 0X01 THEN CONTINUE PRINTING
	usart_xflushRx(USART1_ID);

    xTaskCreate(
		TaskTurnOnLED
		,  (0) // Main Arduino Mega 2560, Freetronics EtherMega (Red) LED Blink
		,  256		// Tested 9 free @ 208
		,  NULL
		,  3
		,  NULL ); // */


	usart_printf_P(PSTR("\r\n\nFree Heap Size: %u\r\n"),xPortGetFreeHeapSize() ); // needs heap_1 or heap_2 for this function to succeed.

	vTaskStartScheduler();

	usart_print_P(PSTR("\r\n\n\nGoodbye... no space for idle task!\r\n")); // Doh, so we're dead...

}

/*-----------------------------------------------------------*/


static void TaskTurnOnLED(int temperature) // Main Red LED Flash
{
	temperature = 90;
	if (temperature < 30) {
		usart_printf_P(PSTR("\r\n\nTemperature: %d\r\n"), temperature);
		DDRH &= ~_BV(DDH3); //close red LED data register
		DDRE |= _BV(DDE5); //open blue LED data register

		PORTE |= _BV(PORTE3); //turn off green LED
		PORTH |= _BV(PORTH3); //turn off red LED
		PORTE &= ~_BV(PORTE5); //turn on blue LED
	} else if (temperature >= 30 && temperature < 40) {
		DDRH &= ~_BV(DDH3); //close red LED data register
		DDRE |= _BV(DDE3); //open green LED data register

		PORTE |= _BV(PORTE5); //turn off blue LED
		PORTH |= _BV(PORTH3); //turn off red LED
		PORTE &= ~_BV(PORTE3); //turn on green LED
	} else {
		DDRE &= ~_BV(DDE5); //close blue LED data register
		DDRE &= ~_BV(DDE3); //close blue LED data register
		DDRH |= _BV(DDH3); //open red LED data register

		PORTE |= _BV(PORTE3); //turn off green LED
		PORTE |= _BV(PORTE5); //turn off blue LED
		PORTH &= ~_BV(PORTH3); //turn on red LED
	}

	usart_fprintf(USART1_ID, "Hello World!");
}

/*-----------------------------------------------------------*/


void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                    portCHAR *pcTaskName )
{

//	DDRH  |= _BV(DDH3); // red LED data register
//	PORTH |= _BV(PORTH3); //turn off red led
//
//	DDRE |= _BV(DDE3); //green LED data register
//	PORTE |= _BV(PORTE3); //turn off green LED

//	DDRE |= _BV(DDE5); //blue LED data register
//	PORTE |= _BV(PORTE5); //turn off blue LED
//	while(1);
}

/*-----------------------------------------------------------*/

