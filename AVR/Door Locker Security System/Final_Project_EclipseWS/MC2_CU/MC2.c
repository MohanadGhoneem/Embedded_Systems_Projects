/******************************************************************************
 *
 * Project:			Final Project - MC2
 * File Name:		MC2.c
 * Description:		Source file for Final Project - Second Microcontroller
 * Author:			Mohanad Adel
 *
 *******************************************************************************/

#include "MC2.h"


/******************************************************************************************
 *                                      Global Variables                                  *
 ******************************************************************************************/

uint8 g_tickFlag=0;
uint8 g_holdSystem = HOLD_SYSTEM;

int main(void)
{
	uint8 systemStarting = 0;
	uint8 counter;
	uint8 pass_match;

	uint8 password_Stored[PASSWORD_WIDTH];
	uint8 password_compare[PASSWORD_WIDTH];

	uint8 compare=0;
	uint8 decision;
	uint8 danger_error = NO_DANGER;
	uint8 restart_mainProgram = FALSE;

	Timer_ConfigType timer={START_VALUE, COMPARE_VALUE, Timer1, F_CPU_1024, Compare};

	UART_config uart = {BIT_8, DISABLE, STOP_BIT_1};
	UART_init(&uart);
	SREG |= (1<<7);

	EEPROM_init();

	BUZZER_DIRECTION_PORT = SET_BIT(BUZZER_DIRECTION_PORT, BUZZER_PIN);
	BUZZER_DATA_PORT = CLEAR_BIT(BUZZER_DATA_PORT, BUZZER_PIN);

	MOTOR_DIRECTION_PORT = SET_BIT(MOTOR_DIRECTION_PORT,MOTOR_PIN_IN1 );
	MOTOR_DIRECTION_PORT = SET_BIT(MOTOR_DIRECTION_PORT,MOTOR_PIN_IN2 );

	MOTOR_DATA_PORT = CLEAR_BIT( MOTOR_DATA_PORT, MOTOR_PIN_IN2);
	MOTOR_DATA_PORT = CLEAR_BIT( MOTOR_DATA_PORT, MOTOR_PIN_IN1);

	EEPROM_readByte(FIRST_ADDRESS_TO_STORE_PASSWORD, &systemStarting);

	/* For the first Login */
	if(systemStarting == 0XFF)
	{
		while(UART_recieveByte() != ECU_READY){}
		UART_sendByte(FIRST_TIME_TO_LOG_IN);
		for(counter = INITIAL_VALUE; counter< PASSWORD_WIDTH; counter++)
		{
			UART_sendByte(ECU_READY);
			password_Stored[counter]= UART_recieveByte();
			EEPROM_writeByte( (FIRST_ADDRESS_TO_STORE_PASSWORD | counter) , password_Stored[counter]);
			_delay_ms(80);
		}
	}
	else
	{
		while(UART_recieveByte() != ECU_READY){}
		UART_sendByte(ANY_TIME_TO_LOG_IN);
	}

	/* For All Other Logins */
	while(1)
	{
		UART_sendByte(ECU_READY);
		decision = UART_recieveByte();

		if(decision == CHOICE_1)
		{
			do
			{
				for(counter = INITIAL_VALUE; counter< PASSWORD_WIDTH; counter++)
				{
					UART_sendByte(ECU_READY);
					password_compare[counter]= UART_recieveByte();
					_delay_ms(80);
				}
				for (counter = INITIAL_VALUE; counter < PASSWORD_WIDTH; counter++)
				{

					EEPROM_readByte( (FIRST_ADDRESS_TO_STORE_PASSWORD | counter) , &compare );
					password_Stored[counter]= compare;
					_delay_ms(80);
				}
				pass_match= checkPass(password_Stored, password_compare);
				if(pass_match == MISMATCH)
				{
					while(UART_recieveByte() != ECU_READY){}
					UART_sendByte(pass_match);
					danger_error++;
					if(danger_error == ALLOWED_TRIES_TO_ENTER_PASSWORD)
					{
						Timer_setCallBack(Timer_Buzz, Timer1);
						Timer_init(&timer);
						while(g_holdSystem != RESUME_SYSTEM){}
						g_holdSystem = HOLD_SYSTEM;
						restart_mainProgram = TRUE;
					}
				}
			}while( (pass_match== MISMATCH) && restart_mainProgram == FALSE);

			if(pass_match == MATCH)
			{
				while(UART_recieveByte() != ECU_READY){}
				UART_sendByte(pass_match);
				for(counter = INITIAL_VALUE; counter< PASSWORD_WIDTH; counter++)
				{
					UART_sendByte(ECU_READY);
					password_Stored[counter]= UART_recieveByte();
					EEPROM_writeByte( (FIRST_ADDRESS_TO_STORE_PASSWORD | counter) , password_Stored[counter]);
					_delay_ms(80);
				}
			}
			danger_error = NO_DANGER;
		}

		else if(decision == CHOICE_2)
		{
			do
			{
				for(counter = INITIAL_VALUE; counter< PASSWORD_WIDTH; counter++)
				{
					UART_sendByte(ECU_READY);
					password_compare[counter]= UART_recieveByte();
					_delay_ms(80);
				}

				for (counter = INITIAL_VALUE; counter < PASSWORD_WIDTH; counter++)
				{
					EEPROM_readByte( (FIRST_ADDRESS_TO_STORE_PASSWORD | counter) , &compare );
					password_Stored[counter]= compare;
					_delay_ms(80);
				}

				pass_match= checkPass(password_Stored, password_compare);

				if(pass_match == MISMATCH)
				{
					while(UART_recieveByte() != ECU_READY){}
					UART_sendByte(pass_match);
					danger_error++;
					if(danger_error == ALLOWED_TRIES_TO_ENTER_PASSWORD)
					{
						Timer_setCallBack(Timer_Buzz, Timer1);
						Timer_init(&timer);
						while(g_holdSystem != RESUME_SYSTEM){}
						g_holdSystem = HOLD_SYSTEM;
						restart_mainProgram = TRUE;
					}
				}
			}while( (pass_match== MISMATCH) && restart_mainProgram == FALSE);

			if(pass_match == MATCH)
			{
				while(UART_recieveByte() != ECU_READY){}
				UART_sendByte(pass_match);
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
