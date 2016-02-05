/*
 * ReadTmp.c
 *
 *  Created on: Feb 3, 2016
 *      Author: jayhe
 */
#include "ReadTmp.h"

void TaskReadTemperature(uint8_t i)
{
	extern avgTemperature;
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

		if (avgTemperature < 30) {
				usart_printf_P(PSTR("\r\n\nTemperature: %d\r\n"), avgTemperature);
				DDRH &= ~_BV(DDH3); //close red LED data register
				DDRE |= _BV(DDE5); //open blue LED data register

				PORTE |= _BV(PORTE3); //turn off green LED
				PORTH |= _BV(PORTH3); //turn off red LED
				PORTE &= ~_BV(PORTE5); //turn on blue LED
			} else if (avgTemperature >= 30 && avgTemperature < 40) {
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

}
