/******************************************************************************
 *
 * Project:			Mini Project 3 - Fan Controller
 * File Name:		Fan_Controller.c
 * Description:		Source file for the Project
 * Author:			Mohanad Adel
 *
 *******************************************************************************/

#include "Fan_Controller.h"

int main(void)
{
	LCD_init();											/* Initialize the LCD */

	ADC_ConfigType ADC_config = {INTERNAL2_56, PRE_8};	/* Configuration of the ADC */
	ADC_init(&ADC_config);								/* Initialize the ADC with previous configuration */

	DCMotor_init();										/* Initialize the DC Motor */

	LCD_moveCursor(0, 3);						/* Moves the Cursor */
	LCD_displayString("Fan is ");

	LCD_moveCursor(1, 2);						/* Moves the Cursor */
	LCD_displayString("Temp. = ");
	LCD_intgerToString(LM35_getTemperature());
	LCD_moveCursor(1, 12);						/* Moves the Cursor */
	LCD_displayString(" C");

	while (1)
	{
		if(LM35_getTemperature() < 30)									/* Turn off the fan */
		{
			LCD_moveCursor(0, 10);						/* Moves the Cursor */
			LCD_displayString("OFF");

			LCD_moveCursor(1, 10);						/* Moves the Cursor */
			LCD_intgerToString(LM35_getTemperature());

			DCMotor_Rotate(stop, 0);

		}

		else if(LM35_getTemperature() >= 30 && LM35_getTemperature() < 60)				/* Run fan with 25% of its max. speed */
		{
			LCD_moveCursor(0, 10);						/* Moves the Cursor */
			LCD_displayString("ON");
			LCD_displayString(" ");


			LCD_moveCursor(1, 10);						/* Moves the Cursor */
			LCD_intgerToString(LM35_getTemperature());

			DCMotor_Rotate(CW, 25);

		}

		else if(LM35_getTemperature() >= 60 && LM35_getTemperature() < 90)				/* Run fan with 50% of its max. speed */
		{
			LCD_moveCursor(0, 10);						/* Moves the Cursor */
			LCD_displayString("ON");

			LCD_moveCursor(1, 10);						/* Moves the Cursor */
			LCD_intgerToString(LM35_getTemperature());

			DCMotor_Rotate(CW, 50);

		}

		else if(LM35_getTemperature() >= 90 && LM35_getTemperature() < 120)				/* Run fan with 75% of its max. speed */
		{
			LCD_moveCursor(0, 10);						/* Moves the Cursor */
			LCD_displayString("ON");

			LCD_moveCursor(1, 10);						/* Moves the Cursor */
			LCD_intgerToString(LM35_getTemperature());

			DCMotor_Rotate(CW, 75);

		}

		else if(LM35_getTemperature() >= 120)							/* Run fan with 100% of its max. speed */
		{
			LCD_moveCursor(0, 10);						/* Moves the Cursor */
			LCD_displayString(" ON");

			LCD_moveCursor(1, 10);						/* Moves the Cursor */
			LCD_intgerToString(LM35_getTemperature());

			DCMotor_Rotate(CW, 100);

		}

	}
}



