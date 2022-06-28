/******************************************************************************
 *
 * Project:			Final Project - MC2
 * File Name:		MC2_Functions.c
 * Description:		Source file for Functions Used by the Second MC in the Final Project
 * Author:			Mohanad Adel
 *
 *******************************************************************************/

#include "MC2.h"


/************************************************************************************************
 *                                    Functions Definitions                                     *
 ************************************************************************************************/

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


/************************************************************************************************
 *                                 Timer CallBack Functions                                     *
 ************************************************************************************************/

void Timer_CCW(void)
{
	g_tickFlag++;
	if( g_tickFlag < MAXIMUM_SECONDS_ANTI_CLOCKWISE)
	{
		DCMotor_CCW();
	}
	else if(g_tickFlag == MAXIMUM_SECONDS_ANTI_CLOCKWISE)
	{
		Timer_DeInit(Timer1);
		DCMotor_Stop();
		g_tickFlag= 0;
		g_holdSystem = RESUME_SYSTEM;
	}
}


void Timer_Stop(void)
{
	g_tickFlag++;
	if( g_tickFlag < MAXIMUM_SECONDS_STOPPING)
	{
		DCMotor_Stop();
	}
	else if(g_tickFlag == MAXIMUM_SECONDS_STOPPING)
	{
		g_tickFlag=0;
		Timer_setCallBack(Timer_CCW, Timer1);
	}
}


void Timer_CW(void)
{
	g_tickFlag++;
	if( g_tickFlag < MAXIMUM_SECONDS_CLOCKWISE)
	{
		DCMotor_CW();
	}
	else if(g_tickFlag == MAXIMUM_SECONDS_CLOCKWISE)
	{
		g_tickFlag=0;
		Timer_setCallBack(Timer_Stop, Timer1);
	}
}


void Timer_Buzz(void)
{
	g_tickFlag++;
	if( g_tickFlag < MAXIMUM_SECONDS_BUZZER)
	{
		Buzzer_On();
	}
	else if(g_tickFlag == MAXIMUM_SECONDS_BUZZER )
	{
		Buzzer_Off();
		Timer_DeInit(Timer1);
		g_tickFlag=0;
		g_holdSystem= RESUME_SYSTEM;
	}
}
