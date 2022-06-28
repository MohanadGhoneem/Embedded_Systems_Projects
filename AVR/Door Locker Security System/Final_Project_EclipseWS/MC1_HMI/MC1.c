/******************************************************************************
 *
 * Project:			Final Project - MC1
 * File Name:		MC1.c
 * Description:		Source file for Final Project - First Microcontroller
 * Author:			Mohanad Adel
 *
 *******************************************************************************/


#include "MC1.h"

/******************************************************************************************
 *                                      Global Variables
 *****************************************************************************************/

uint8 g_password1[PASSWORD_WIDTH];
uint8 g_password2[PASSWORD_WIDTH];
uint8 g_tickFlag=0;
uint8 g_holdSystem = HOLD_SYSTEM;

int main(void)
{
	uint8 systemStarting;
	uint8 pass_match;
	uint8 counter;
	uint8 check_EEPROM;
	uint8 decision;
	uint8 danger_error = NO_DANGER;
	uint8 restart_mainProgram = FALSE;

	Timer_ConfigType timer={START_VALUE, COMPARE_VALUE, Timer1, F_CPU_1024, Compare};

	UART_config uart = {BIT_8, DISABLE, STOP_BIT_1};
	UART_init(&uart);
	SREG |= (1<<7);

	LCD_init();

	UART_sendByte(ECU_READY);
	systemStarting= UART_recieveByte();

	/* For the First Login Only: */
	if (systemStarting == FIRST_TIME_TO_LOG_IN)
	{
		do
		{
			start_System();
			pass_match = checkPass(g_password1, g_password2);
			if(pass_match == MISMATCH)
			{
				LCD_clearScreen();
				LCD_displayStringRowColumn(0,0,"Mismatch passwords");
				_delay_ms(1000);
			}
		}while(pass_match == MISMATCH);

		if(pass_match == MATCH)
		{
			for(counter = INITIAL_VALUE; counter< PASSWORD_WIDTH; counter++)
			{
				while(UART_recieveByte() != ECU_READY){}
				UART_sendByte(g_password1[counter]);
				_delay_ms(80);
			}
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"Password saved");
			_delay_ms(1000);
			LCD_clearScreen();
		}
	}

	/* For every other logins */
	while(1)
	{
		decision = mainOptions();

		if(decision == CHOICE_1)
		{
			while(UART_recieveByte() != ECU_READY){}
			UART_sendByte(decision);
			do
			{
				storePass(g_password2);
				for(counter = INITIAL_VALUE; counter < PASSWORD_WIDTH; counter++)
				{
					while(UART_recieveByte() != ECU_READY){}
					UART_sendByte(g_password2[counter]);
					_delay_ms(80);
				}

				UART_sendByte(ECU_READY);

				check_EEPROM = UART_recieveByte();

				if(check_EEPROM == MISMATCH)
				{
					LCD_clearScreen();
					LCD_displayStringRowColumn(0,0,"Incorrect ");
					_delay_ms(1000);
					danger_error++;

					if(danger_error == ALLOWED_TRIES_TO_ENTER_PASSWORD)
					{
						Timer_setCallBack(Timer_Buzz, Timer1);
						LCD_clearScreen();
						Timer_init(&timer);
						while(g_holdSystem != RESUME_SYSTEM){}
						g_holdSystem = HOLD_SYSTEM;
						restart_mainProgram = TRUE;
					}
				}
			}while( (check_EEPROM ==  MISMATCH) && (restart_mainProgram == FALSE) );

			if (check_EEPROM == MATCH)
			{
				do
				{
					start_System();
					pass_match = checkPass(g_password1, g_password2);
					if(pass_match == MISMATCH)
					{
						LCD_clearScreen();
						LCD_displayStringRowColumn(0,0,"Mismatch passwords");
						_delay_ms(1000);
					}
				}while(pass_match == MISMATCH);

				if(pass_match == MATCH)
				{
					for(counter = INITIAL_VALUE; counter< PASSWORD_WIDTH; counter++)
					{
						while(UART_recieveByte() != ECU_READY){}
						UART_sendByte(g_password1[counter]);
						_delay_ms(80);
					}
					LCD_clearScreen();
					LCD_displayStringRowColumn(0,0,"Password changed");
					_delay_ms(2000);
					LCD_clearScreen();
				}
			}
			danger_error = NO_DANGER;
		}

		else if(decision == CHOICE_2)
		{
			while(UART_recieveByte() != ECU_READY){}
			UART_sendByte(decision);
			do
			{
				storePass(g_password2);
				for(counter = INITIAL_VALUE; counter < PASSWORD_WIDTH; counter++)
				{
					while(UART_recieveByte() != ECU_READY){}
					UART_sendByte(g_password2[counter]);
					_delay_ms(80);
				}

				UART_sendByte(ECU_READY);
				check_EEPROM = UART_recieveByte();

				if(check_EEPROM == MISMATCH)
				{
					LCD_clearScreen();
					LCD_displayStringRowColumn(0,0,"Invalid Pass");
					_delay_ms(1000);
					danger_error++;
					if(danger_error == ALLOWED_TRIES_TO_ENTER_PASSWORD)
					{
						Timer_setCallBack(Timer_Buzz, Timer1);
						LCD_clearScreen();
						Timer_init(&timer);
						while(g_holdSystem != RESUME_SYSTEM){}
						g_holdSystem = HOLD_SYSTEM;
						restart_mainProgram = TRUE;
					}
				}
			}while( (check_EEPROM ==  MISMATCH) && (restart_mainProgram == FALSE) );

			if (check_EEPROM == MATCH)
			{
				Timer_setCallBack(Timer_CW, Timer1);
				Timer_init(&timer);
				while(g_holdSystem != RESUME_SYSTEM){}
				g_holdSystem = HOLD_SYSTEM;
			}
			danger_error = NO_DANGER;
		}
		restart_mainProgram = FALSE;
	}
}
