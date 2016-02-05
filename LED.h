#include <stdlib.h>
/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
/* serial interface include file. */
#include "usartserial.h"

#ifndef LED_H_
#define LED_H_


void TaskTurnOnLED(int temperature);


#endif /* LED_H_ */
