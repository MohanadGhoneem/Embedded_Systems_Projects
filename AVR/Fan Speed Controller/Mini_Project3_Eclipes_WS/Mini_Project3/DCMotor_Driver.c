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

/*	Used Libraries	*/
#include "common_macros.h"
#include "GPIO.h"
#include "DCMotor_Driver.h"
#include "Timer0_PWM.h"

/* Description:
 * This Driver the following Function:
 * 1.	DCMotor_init:
 * 				Takes void. Returns void
 * 				Setup Direction for the two motor pins
 * 2.	DCMotor_Rotate:
 * 				Takes State and duty cycle. Returns void
 * 				Responsible for rotating the motor CW or CCW or Stop the motor
 * 				Send the required duty cycle to the PWM driver
 */


/*******************************************************************************
 *                                 Functions                                   *
 *******************************************************************************/

/* Description:
 * 		Takes void. Returns void
 * 		Setup Direction for the two motor pins
 */
void DCMotor_init(void){

	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN1, PIN_OUTPUT);	/* Setup the first pin the motor as output pin */

	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN2, PIN_OUTPUT);	/* Setup the second pin the motor as output pin */

	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);

}

/* Description:
 * 		Takes State and duty cycle. Returns void
 * 		Responsible for rotating the motor CW or CCW or Stop the motor
 * 		Send the required duty cycle to the PWM driver
 */
void DCMotor_Rotate(DCMotor_State state, uint8 speed){

	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);

	/* Motor's Direction */
	if (state == stop){
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN2, LOGIC_LOW);
	}
	else if(state == CW){
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN2, LOGIC_LOW);
	}
	else if(state == CCW){
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN2, LOGIC_HIGH);
	}

	/* Motor's Speed */
	if (speed==25)
	{
		PWM_Timer0_Init(64);
	}
	else if (speed==50)
	{
		PWM_Timer0_Init(128);
	}
	else if (speed==75)
	{
		PWM_Timer0_Init(192);
	}
	else if (speed==100)
	{
		PWM_Timer0_Init(255);
	}

}


