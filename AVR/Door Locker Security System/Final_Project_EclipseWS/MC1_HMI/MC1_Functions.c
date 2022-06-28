/******************************************************************************
 *
 * Project:			Final Project - MC1
 * File Name:		MC1_Functions.c
 * Description:		Source file for Functions Used by the First MC in the Final Project
 * Author:			Mohanad Adel
 *
 *******************************************************************************/

#include "MC1.h"

/************************************************************************************************
 *                                    Functions Definitions                                     *
 ************************************************************************************************/

/*
 * Takes void and returns the option chosen
 * Description: Main Options Function
 */
uint8 mainOptions (void)
{
	uint8 option;

	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"1: Change pass");
	LCD_displayStringRowColumn(1,0,"2: Open door");

	do
	{
	option = KeyPad_getPressedKey();
	}while ( (option != CHOICE_1) && (option != CHOICE_2) );

	 _delay_ms(500);

	if (option == CHOICE_1)
	{
		option = CHOICE_1;
	}
	else if (option == CHOICE_2)
	{
		option = CHOICE_2;
	}
	return option;
}

/*
 * Takes the Addresses of Two Passwords to Compare and return the status of mismatching
 * Description: Function to check the Password
 */
uint8 checkPass(uint8* pass1, uint8* pass2)
{
	uint8 count;
	uint8 mismatch=0;
	for(count=INITIAL_VALUE; count<PASSWORD_WIDTH; count++)
	{
		if( pass1[count] != pass2[count] )
		{
			mismatch = MISMATCH_OCCUR;
			count= PASSWORD_WIDTH;
		}
	}
	return mismatch;
}

/*
 * Takes the Address of the password
 * Description: Function to store the Password
 */
void storePass(uint8 *pass)
{
	uint8 count;
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"Enter Password:");

	for(count= INITIAL_VALUE ; count< PASSWORD_WIDTH; count++)
	{
		LCD_moveCursor(1,count);
		pass[count] = KeyPad_getPressedKey();
		_delay_ms(500);
		LCD_moveCursor(1,count);
		LCD_displayCharacter('*');
	}
	while( ( KeyPad_getPressedKey() )!= '='){}
	LCD_clearScreen();
}

/*
 * Takes void returns void
 * Description: Start Function and Entering 2 Passwords
 */
void start_System(void)
{

	LCD_displayStringRowColumn(0,0,"Good Morning :)");
	_delay_ms(800);

	storePass(g_password1);

	LCD_displayStringRowColumn(0,0,"Re-Enter pass");

	_delay_ms(800);
	LCD_clearScreen();

	storePass(g_password2);
}

/************************************************************************************************
 *                                 Timer CallBack Functions                                     *
 ************************************************************************************************/
/*
 * Takes void returns void
 * Description: Function to send to CU that door is opening in CCW Direction
 */
void Timer_CCW(void)
{
	g_tickFlag++;
	if( g_tickFlag < MAXIMUM_SECONDS_ANTI_CLOCKWISE)
	{
		LCD_displayStringRowColumn(0,0,"Door is Closing");
	}

	else if(g_tickFlag == MAXIMUM_SECONDS_ANTI_CLOCKWISE)
	{
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"Door is Closed");
		_delay_ms(1000);
		LCD_clearScreen();
		Timer_DeInit(Timer1);
		g_tickFlag= 0;
		g_holdSystem = RESUME_SYSTEM;
		LCD_clearScreen();
	}
}

/*
 * Takes void returns void
 * Description: Function to send to CU that door is to stop
 */
void Timer_Stop(void)
{
	g_tickFlag++;
	if( g_tickFlag < MAXIMUM_SECONDS_STOPPING)
	{
		LCD_displayStringRowColumn(0,0,"Door is Open");
	}
	else if(g_tickFlag == MAXIMUM_SECONDS_STOPPING)
	{
		g_tickFlag=0;
		Timer_setCallBack(Timer_CCW, Timer1);
		LCD_clearScreen();
	}
}

/*
 * Takes void returns void
 * Description: Function to send to CU that door is opening in CW Direction
 */
void Timer_CW(void)
{
	g_tickFlag++;
	if( g_tickFlag < MAXIMUM_SECONDS_CLOCKWISE)
	{
		LCD_displayStringRowColumn(0,0,"Door is Opening");
	}
	else if(g_tickFlag == MAXIMUM_SECONDS_CLOCKWISE)
	{
		g_tickFlag=0;
		Timer_setCallBack(Timer_Stop, Timer1);
		LCD_clearScreen();
	}
}

/*
 * Takes void returns void
 * Description: Function to send to CU that buzzer should be activated
 */
void Timer_Buzz(void)
{
	g_tickFlag++;
	if( g_tickFlag < MAXIMUM_SECONDS_BUZZER)
	{
		LCD_displayStringRowColumn(0,0,"3 WRONG TRIES!");
	}
	else if(g_tickFlag == MAXIMUM_SECONDS_BUZZER )
	{
		Timer_DeInit(Timer1);
		g_tickFlag=0;
		g_holdSystem= RESUME_SYSTEM;
		LCD_clearScreen();
	}
}
