/******************************************************************************
 *
 * Module: Timer
 *
 * File Name: Timer_Driver.h
 *
 * Description: Header file for the AVR's Timer driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/


#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Timer_Clock;


typedef enum
{
	Timer0,Timer1
}Timer_Type;

typedef enum
{
	Overflow,Compare
}Timer_Mode;

typedef struct
{
	uint32 timer_InitialValue;
	uint32 timer_compare_MatchValue;
	Timer_Type  timer_ID;
	Timer_Clock timer_clock;
	Timer_Mode  timer_mode;

}Timer_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:  Function to Initialize Timer Driver
 */
void Timer_init(const Timer_ConfigType * Config_Ptr);

/*
 * Description: Function to set the Call Back function address.
 */
void Timer_setCallBack(void(*a_ptr)(void), Timer_Type timer_type );

/*
 * Description: Function to stop the clock of the timer to stop incrementing.
 */
void Timer_stop(Timer_Type timer_type);

/*
 * Description: Function to DeInit the timer to start again from beginning
 */
void Timer_DeInit(Timer_Type timer_type);

#endif /* TIMER_DRIVER_H_ */
