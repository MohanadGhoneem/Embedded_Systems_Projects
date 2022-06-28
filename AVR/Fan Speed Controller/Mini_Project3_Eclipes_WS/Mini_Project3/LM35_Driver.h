 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: LM35_Driver.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#ifndef LM35_DRIVER_H_
#define LM35_DRIVER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_DRIVER_H_ */
