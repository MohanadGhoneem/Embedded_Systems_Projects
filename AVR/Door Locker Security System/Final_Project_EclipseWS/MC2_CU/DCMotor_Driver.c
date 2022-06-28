/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DCMotor_Driver.c
 *
 * Description: Source file for the DC Motor driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/


#include "DCMotor_Driver.h"

/* Description:
 * 		Takes void. Returns void
 * 		Turns ON the Motor in CW Direction
 */
void DCMotor_CW(void)
{
	MOTOR_DATA_PORT = CLEAR_BIT(MOTOR_DATA_PORT , MOTOR_PIN_IN1);
	MOTOR_DATA_PORT = SET_BIT(MOTOR_DATA_PORT , MOTOR_PIN_IN2);
}

/* Description:
 * 		Takes void. Returns void
 * 		Turns ON the Motor in CCW Direction
 */
void DCMotor_CCW(void)
{
	MOTOR_DATA_PORT = CLEAR_BIT( MOTOR_DATA_PORT, MOTOR_PIN_IN2);
	MOTOR_DATA_PORT = SET_BIT (MOTOR_DATA_PORT, MOTOR_PIN_IN1);
}

/* Description:
 * 		Takes void. Returns void
 * 		Turns OFF the Motor
 */
void DCMotor_Stop(void)
{
	MOTOR_DATA_PORT = CLEAR_BIT(MOTOR_DATA_PORT , MOTOR_PIN_IN2);
	MOTOR_DATA_PORT = CLEAR_BIT( MOTOR_DATA_PORT, MOTOR_PIN_IN1);
}
