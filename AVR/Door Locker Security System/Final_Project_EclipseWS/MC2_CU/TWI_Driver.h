 /******************************************************************************
 *
 * Module: I2C
 *
 * File Name: TWI_Driver.h
 *
 * Description: Header file for the AVR's I2C Driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#ifndef TWI_DRIVER_H_
#define TWI_DRIVER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start 
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	TWPS_0, TWPS_1, TWPS_2, TWPS_3

}TWI_Prescaler;



typedef struct
{
	/*variable to use it to select the rate of i2c*/
	uint8 rateRegister;

	/*variable to select the address of the slave*/
	uint8 address;

	/*variable to select the prescaler of the baud rate */
	TWI_Prescaler prescaler;

}TWI_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void TWI_init(const TWI_ConfigType * Config_ptr);
void TWI_start(void);
void TWI_stop(void);
void TWI_write(uint8 data);
uint8 TWI_readWithACK(void); //read with send Ack
uint8 TWI_readWithNACK(void); //read without send Ack
uint8 TWI_getStatus(void);


#endif /* TWI_DRIVER_H_ */
