////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////    main.c
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <avr/io.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
/* serial interface include file. */
#include "ReadTmp.h"
#include "LCD.h"
/*-----------------------------------------------------------*/
/* Create a handle for the serial port. */
//extern xComPortHandle xSerialPort;

// Main Arduino Mega 2560, Freetronics EtherMega (Red) LED Blink

/*-----------------------------------------------------------*/

/* Main program loop */
//int main(void) __attribute__((OS_main));
int usartfd;
char lcdString[32];
uint8_t result[18];
uint8_t avgTemperature;

void scheduler(void *para)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	while(1)
	{
	TaskReadTemperature(0);
	vTaskDelayUntil( &xLastWakeTime, ( 100 / portTICK_PERIOD_MS ) );
	lcdPrint(0);
	}
}

int main(void)
{
	uint8_t result[18];
    // turn on the serial port for debugging or for other USART reasons.
	usartfd = usartOpen( USART0_ID, 9600, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX); //  serial port: WantedBaud, TxQueueLength, RxQueueLength (8n1)

	xTaskCreate(
			scheduler,
			(0)
			,  256				// Tested 9 free @ 208
			,  NULL
			,  3
			,  NULL );

	I2C_Master_Initialise(0xC0);
	vTaskStartScheduler();

}

void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                    portCHAR *pcTaskName )
{
//DDRB  |= _BV(DDB7);
//PORTB |= _BV(PORTB7);       // main (red PB7) LED on. Mega main LED on and die.
while(1);
}
/*-----------------------------------------------------------*/
