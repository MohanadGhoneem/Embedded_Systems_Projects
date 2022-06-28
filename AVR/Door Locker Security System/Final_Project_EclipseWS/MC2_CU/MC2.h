/******************************************************************************
 *
 * Project:			Final Project - MC2
 * File Name:		MC2.c
 * Description:		Header file for Final Project - Second Microcontroller
 * Author:			Mohanad Adel
 *
 *******************************************************************************/

#ifndef MC2_H_
#define MC2_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Buzzer_Driver.h"
#include "std_types.h"
#include "common_macros.h"
#include "DCMotor_Driver.h"
#include "EEPROM_Driver.h"
#include "Timer_Driver.h"
#include "UART_Driver.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/


#define MISMATCH                             0x01
#define MATCH                                0x00
#define NO_DANGER                            0x00
#define FIRST_ADDRESS_TO_STORE_PASSWORD     0X0312
#define FIRST_TIME_TO_LOG_IN                 0x01
#define ANY_TIME_TO_LOG_IN                   0x00
#define CHOICE_1                             0x01
#define CHOICE_2                             0x02
#define ALLOWED_TRIES_TO_ENTER_PASSWORD      0x03
#define INITIAL_VALUE                        0x00
#define PASSWORD_WIDTH                       0x04
#define MISMATCH_OCCUR                       0x01
#define MAXIMUM_SECONDS_ANTI_CLOCKWISE         15
#define MAXIMUM_SECONDS_STOPPING                3
#define MAXIMUM_SECONDS_CLOCKWISE              15
#define MAXIMUM_SECONDS_BUZZER                 60
#define RESUME_SYSTEM                        0x00
#define HOLD_SYSTEM                          0x01
#define START_VALUE                          0x00
#define COMPARE_VALUE                        8000
#define ECU_READY                            0x10


/*******************************************************************************
 *                        External variables                                   *
 *******************************************************************************/
extern uint8 g_tickFlag;
extern uint8 g_holdSystem;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
uint8 checkPass(uint8* pass1, uint8* pass2);
void Timer_CCW(void);
void Timer_Stop(void);
void Timer_CW(void);
void Timer_Buzz(void);


#endif /* MC2_H_ */
