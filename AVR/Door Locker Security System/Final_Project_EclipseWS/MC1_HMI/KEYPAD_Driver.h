 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD_Driver.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define N_col 4
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN  PINA
#define KEYPAD_PORT_DIR DDRA

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function responsible for getting the pressed keypad key
 */
uint8 KeyPad_getPressedKey(void);

#endif /* KEYPAD_DRIVER_H_ */
