/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DCMotor_Driver.h
 *
 * Description: Header file for the DC Motor driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/


#ifndef DCMOTOR_DRIVER_H_
#define DCMOTOR_DRIVER_H_

#include "std_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "common_macros.h"


/*******************************************************************************
 *                                  Macros                                     *
 *******************************************************************************/

#define MOTOR_DIRECTION_PORT                  DDRA
#define MOTOR_DATA_PORT                      PORTA
#define MOTOR_PIN_IN1                          PA3
#define MOTOR_PIN_IN2                          PA4
#define MOTOR_PIN_EN1
#define MOTOR_PIN_IN3
#define MOTOR_PIN_IN4
#define MOTOR_PIN_EN2


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/* Description:
 * 		Takes void. Returns void
 * 		Turns ON the Motor in CW Direction
 */
void DCMotor_CW(void);

/* Description:
 * 		Takes void. Returns void
 * 		Turns ON the Motor in CCW Direction
 */
void DCMotor_CCW(void);

/* Description:
 * 		Takes void. Returns void
 * 		Turns OFF the Motor
 */
void DCMotor_Stop(void);


#endif /* DCMOTOR_DRIVER_H_ */
