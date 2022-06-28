/******************************************************************************
 *
 * Project:			Final Project - MC1
 * File Name:		MC1.h
 * Description:		Header file for Final Project - First Microcontroller
 * Author:			Mohanad Adel
 *
 *******************************************************************************/

#ifndef MC1_H_
#define MC1_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "std_types.h"
#include "common_macros.h"
#include "KEYPAD_Driver.h"
#include "LCD_Driver.h"
#include "Timer_Driver.h"
#include "UART_Driver.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define ECU_READY                              0x10
#define FIRST_TIME_TO_LOG_IN                   0x01
#define ALLOWED_TRIES_TO_ENTER_PASSWORD        0x03
#define NO_DANGER                              0x00
#define MISMATCH                               0x01
#define MATCH                                  0x00
#define START_VALUE                            0x00
#define COMPARE_VALUE                          8000
#define CHOICE_1                               0x01
#define CHOICE_2                               0x02
#define INITIAL_VALUE                          0x00
#define PASSWORD_WIDTH                         0x04
#define MISMATCH_OCCUR                         0x01
#define MAXIMUM_SECONDS_ANTI_CLOCKWISE           15
#define MAXIMUM_SECONDS_STOPPING                  3
#define MAXIMUM_SECONDS_CLOCKWISE                15
#define MAXIMUM_SECONDS_BUZZER                   60
#define RESUME_SYSTEM                          0x00
#define HOLD_SYSTEM                            0x01


/*******************************************************************************
 *                        External variables                                   *
 *******************************************************************************/
extern uint8 g_password1[PASSWORD_WIDTH];
extern uint8 g_password2[PASSWORD_WIDTH];
extern uint8 g_tickFlag;
extern uint8 g_holdSystem;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
uint8 mainOptions (void);
uint8 checkPass(uint8* pass1, uint8* pass2);
void storePass(uint8 *pass);
void Timer_CCW(void);
void Timer_Stop(void);
void Timer_CW(void);
void Timer_Buzz(void);


#endif /* MC1_H_ */
