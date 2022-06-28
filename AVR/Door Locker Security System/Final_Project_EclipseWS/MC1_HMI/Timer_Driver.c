/******************************************************************************
 *
 * Module: Timer
 *
 * File Name: Timer_Driver.c
 *
 * Description: Source file for the AVR's Timer driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#include "Timer_Driver.h"

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_Timer0_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_Timer1_callBackPtr)(void) = NULL_PTR;
/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
ISR(TIMER0_OVF_vect)
{
	if(g_Timer0_callBackPtr != NULL_PTR)
	{
		(*g_Timer0_callBackPtr)();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(g_Timer0_callBackPtr != NULL_PTR)
	{
		(*g_Timer0_callBackPtr)();
	}
}

ISR(TIMER1_OVF_vect)
{
	if(g_Timer1_callBackPtr != NULL_PTR)
	{
		(*g_Timer1_callBackPtr)();
	}
}

ISR(TIMER1_COMPA_vect)
{
	if(g_Timer1_callBackPtr != NULL_PTR)
	{
		(*g_Timer1_callBackPtr)();
	}
}

/*******************************************************************************
 *                            Function Definitions                             *
 *******************************************************************************/
/*
 * Description:  Function to Initialize Timer Driver
 */
void Timer_init(const Timer_ConfigType * Config_Ptr)
{

	switch(Config_Ptr->timer_ID)
	{

	case Timer0:
		TCCR0 &= 0X00;
		TCNT0 &= 0X00;
		OCR0 &= 0X00;
		TIMSK &= 0X00;
		TCCR0 = ( (Config_Ptr->timer_InitialValue) ) & 0XFF;
		TCCR0 = (TCCR0  & 0XF8) | (Config_Ptr->timer_clock);
		TCCR0  = CLEAR_BIT(TCCR0 , COM00);
		TCCR0  = CLEAR_BIT(TCCR0 , COM01);

		switch(Config_Ptr->timer_mode)
		{
		case Overflow:

			TCCR0  = CLEAR_BIT(TCCR0 , WGM00);
			TCCR0  = CLEAR_BIT(TCCR0 , WGM01);
			TCCR0 = SET_BIT(TCCR0,FOC0);
			TIMSK = SET_BIT(TIMSK, TOIE0);
			break;

		case Compare:
			TCCR0 = CLEAR_BIT(TCCR0, WGM00);
			TCCR0 = SET_BIT(TCCR0, WGM01);
			TCCR0 = SET_BIT(TCCR0, FOC0);
			OCR0 = ((Config_Ptr->timer_compare_MatchValue)) & 0XFF;
			TIMSK = SET_BIT(TIMSK, OCIE0);
			break;
		}
		break;
		case Timer1:
			TCNT1 = ( (Config_Ptr->timer_InitialValue) ) & 0XFFFF;
			TCCR1B =  (TCCR1B & 0XF8) | (Config_Ptr->timer_clock);
			TCCR1A = TCCR1A & 0X0F;
			switch(Config_Ptr->timer_mode)
			{
			case Overflow:
				TCCR1A = TCCR1A & 0XFC ;
				TCCR1B = TCCR1B & 0XE7 ;
				TCCR1A =  SET_BIT(TCCR1A,FOC1A);
				TCCR1A =  SET_BIT(TCCR1A,FOC1B);
				TIMSK = SET_BIT(TIMSK,TOIE1);
				break;
			case Compare:
				TCCR1A = TCCR1A & 0XFC ;
				TCCR1B = SET_BIT(TCCR1B, WGM12);
				TCCR1B = CLEAR_BIT(TCCR1B, WGM13);
				TCCR1A =  SET_BIT(TCCR1A,FOC1A);
				TCCR1A =  SET_BIT(TCCR1A,FOC1B);
				OCR1A = ((Config_Ptr->timer_compare_MatchValue)) & 0XFFFF;
				TIMSK = SET_BIT(TIMSK,OCIE1A);
				break;
			}
			break;
	}
}

/*
 * Description: Function to set the Call Back function address.
 */
void Timer_setCallBack(void(*a_ptr)(void), Timer_Type timer_type )
{
	switch(timer_type)
	{
	case Timer0:
		g_Timer0_callBackPtr = a_ptr;
		break;

	case Timer1:
		g_Timer1_callBackPtr = a_ptr;
		break;
	}
}

/*
 * Description: Function to stop the clock of the timer to stop incrementing.
 */
void Timer_stop(Timer_Type timer_type)
{
	switch(timer_type)
	{
	case Timer0:
		TCCR0 = (TCCR0  & 0XF8) ;
		break;

	case Timer1:
		TCCR1B  =  (TCCR1B  & 0XF8) ;
		break;
	}
}

/*
 * Description: Function to DeInit the timer to start again from beginning
 */
void Timer_DeInit(Timer_Type timer_type)
{
	switch(timer_type)
	{
	case Timer0:
		TCCR0        	&= 0X00;
		TCNT0   		&= 0X00;
		OCR0  			&= 0X00;
		TIMSK  			&= 0X00;
		break;

	case Timer1:
		TCCR1A         	&= 0X00;
		TCCR1B         	&= 0X00;
		TCNT1      		&= 0X00;
		OCR1A   		&= 0X00;
		TIMSK     		&= 0X00;
		break;
	}
}
