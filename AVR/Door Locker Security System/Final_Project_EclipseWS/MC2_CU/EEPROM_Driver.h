 /******************************************************************************
 *
 * Module: External EEPROM
 *
 * File Name: EEPROM_Driver.h
 *
 * Description: Header file for the External EEPROM Memory
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_

#include "std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void EEPROM_init(void);
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);
 
#endif /* EEPROM_DRIVER_H_ */
