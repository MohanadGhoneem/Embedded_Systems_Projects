/******************************************************************************
 *
 * Project:			Mini Project 4 - Distance Measurement
 * File Name:		Distance_Measurement.c
 * Description:		Source file for the Project
 * Author:			Mohanad Adel
 *
 *******************************************************************************/

#include "Distance_Measurement.h"


int main(void){

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Create configuration structure for ICU driver */
	ICU_ConfigType ICU_Config = {F_CPU_8, RISING};

	LCD_init();
	ICU_init(&ICU_Config);
	Ultrasonic_init();

	uint16 distance;		/* Required Distance Variable */


	while(1){

		distance = Ultrasonic_readDistance();

		LCD_displayString("Distance = ");
		LCD_intgerToString(distance);
		LCD_displayString(" cm");
		_delay_ms(500);
		LCD_clearScreen();
	}
}
