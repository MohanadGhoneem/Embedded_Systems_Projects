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


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_PORT 			PORTB_ID
#define DC_MOTOR_PIN1			PIN0_ID
#define DC_MOTOR_PIN2			PIN1_ID


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	stop, CW, CCW
}DCMotor_State;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/* Description:
 * 		Takes void. Returns void
 * 		Setup Direction for the two motor pins
 */
void DCMotor_init(void);

/* Description:
 * 		Takes State and duty cycle. Returns void
 * 		Responsible for rotating the motor CW or CCW or Stop the motor
 * 		Send the required duty cycle to the PWM driver
 */
void DCMotor_Rotate(DCMotor_State state, uint8 speed);

#endif /* DCMOTOR_DRIVER_H_ */
