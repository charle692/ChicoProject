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
//#include "LED.h"
#include "Scan.h"
#include "Movement.h"
#include "wireless_interface.h"

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
uint8_t speedDisplay;
uint8_t* ticCount;
uint16_t distanceDisplay;
bool rest;
int counter;

void scheduler(void *para)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	while(1) {
		TaskReadTemperature(0);
		vTaskDelayUntil( &xLastWakeTime, ( 100 / portTICK_PERIOD_MS ) );
		lcdPrint(0);
		vTaskDelayUntil( &xLastWakeTime, ( 400 / portTICK_PERIOD_MS ) );
	}
}



void moveRobot(void *para)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	char client_request;
	while(1)
	{
//		robotForward();
		distanceAndSpeed();
		vTaskDelayUntil( &xLastWakeTime, ( 1000 / portTICK_PERIOD_MS ) );
//		robotLeft();
		distanceAndSpeed();
		vTaskDelayUntil( &xLastWakeTime, ( 1000 / portTICK_PERIOD_MS ) );
//		robotBackwards();
		distanceAndSpeed();
		vTaskDelayUntil( &xLastWakeTime, ( 1000 / portTICK_PERIOD_MS ) );
//		robotRight();
		distanceAndSpeed();
		vTaskDelayUntil( &xLastWakeTime, ( 1000 / portTICK_PERIOD_MS ) );
//		robotSteady();
		distanceAndSpeed();
		vTaskDelayUntil( &xLastWakeTime, ( 2000 / portTICK_PERIOD_MS ) );
	}
}

void processRequests(void *para) {
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	char client_request;
	while(1) {
		process_client_request();
		client_request = get_next_client_response();
		vTaskDelayUntil( &xLastWakeTime, (5500 / portTICK_PERIOD_MS ));
	}
}

int main(void)
{
	portENABLE_INTERRUPTS();
	// turn on the serial port for debugging or for other USART reasons.
	usartfd = usartOpen(USART1_ID, 115200, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX); //  serial port: WantedBaud, TxQueueLength, RxQueueLength (8n1)
	usartOpen( USART2_ID, 9600, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX);
	usartOpen( USART0_ID, 115200, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX);
	gs_initialize_module(USART2_ID, 9600, USART0_ID, 115200);
	gs_set_wireless_ssid("🤖");
	gs_activate_wireless_connection();

	configure_web_page("Chico: The Robot", "! Control Interface !", HTML_DROPDOWN_LIST);
	add_element_choice('F', "Forward");
	start_web_server();

	xTaskCreate(processRequests,
					(0),
					1024,
					NULL,
					3,
					NULL);
//	xTaskCreate(
//			scheduler,
//			(0)
//			,  256				// Tested 9 free @ 208
//			,  NULL
//			,  3
//			,  NULL );
//
//	xTaskCreate(move,
//			(0),
//			256,
//			NULL,
//			3,
//			NULL);
//
//	xTaskCreate(moveRobot,
//			(0),
//			256,
//			NULL,
//			3,
//			NULL);


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
