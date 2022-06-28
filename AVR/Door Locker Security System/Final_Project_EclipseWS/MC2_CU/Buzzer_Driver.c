/******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: Buzzer_Driver.c
 *
 * Description: Source file for the Buzzer driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#include "Buzzer_Driver.h"

/* Description:
 * 		Takes void. Returns void
 * 		Turns ON the Buzzer
 */
void Buzzer_On(void)
{
	SET_BIT(BUZZER_DATA_PORT , BUZZER_PIN );
}

/* Description:
 * 		Takes void. Returns void
 * 		Turns OFF the Buzzer
 */
void Buzzer_Off(void)
{
	CLEAR_BIT(BUZZER_DATA_PORT , BUZZER_PIN);
}
