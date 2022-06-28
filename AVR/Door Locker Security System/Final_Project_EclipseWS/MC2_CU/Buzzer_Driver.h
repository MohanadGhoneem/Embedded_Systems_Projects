/******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: Buzzer_Driver.h
 *
 * Description: Header file for the Buzzer driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#ifndef BUZZER_DRIVER_H_
#define BUZZER_DRIVER_H_


#include "std_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "common_macros.h"

/*******************************************************************************
 *                                  Macros                                     *
 *******************************************************************************/
#define BUZZER_DIRECTION_PORT                 DDRA
#define BUZZER_DATA_PORT                     PORTA
#define BUZZER_PIN                             PA0

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
/* Description:
 * 		Takes void. Returns void
 * 		Turns ON the Buzzer
 */
void Buzzer_On(void);

/* Description:
 * 		Takes void. Returns void
 * 		Turns OFF the Buzzer
 */
void Buzzer_Off(void);




#endif /* BUZZER_DRIVER_H_ */
