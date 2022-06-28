/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_Driver.h
 *
 * Description: Header file for the ATmega16 ADC driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "std_types.h"


/*******************************************************************************
 *                          Types Declaration                                  *
 *******************************************************************************/

typedef enum
{
	AREF, AVCC, RESERVED, INTERNAL2_56
}ADC_ReferenceVolatge;

typedef enum
{
	PRE_1, PRE_2, PRE_4, PRE_8, PRE_16, PRE_32, PRE_64, PRE_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType* Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_DRIVER_H_ */
