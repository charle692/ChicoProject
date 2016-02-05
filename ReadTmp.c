/*
 * ReadTmp.c
 *
 *  Created on: Feb 3, 2016
 *      Author: jayhe
 */
#include "ReadTmp.h"
#include "LCD.h"

void TaskReadTemperature(uint8_t i)
{
	uint8_t avgTemperature = 0;
	uint8_t writeData[] = {0xD0, 0x01, 0xD0, 0x02, 0xD0, 0x03, 0xD0, 0x04, 0xD0, 0x05, 0xD0, 0x06, 0xD0, 0x07, 0xD0, 0x08, 0xD0, 0x09};
	uint8_t readData[] = {0xD1, 0x01};
	extern uint8_t result[18];

		for (int i=0; i<9; i++)
		{
			I2C_Master_Start_Transceiver_With_Data((writeData+(i*2)), 2);
			I2C_Master_Start_Transceiver_With_Data(readData, sizeof(readData));
			I2C_Master_Get_Data_From_Transceiver(result+(i*2), 2);

			avgTemperature = (result[1]+result[3]+result[5]+result[7]+result[9]+result[11]+result[13]+result[15]+result[17])/9;

		}
}
