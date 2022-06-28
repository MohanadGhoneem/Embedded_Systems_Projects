 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: common_macros.h
 *
 * Description: Commonly Used Macros in AVR
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

/*******************************************************************************
 *
 * Description:
 *
 * This .h file contains Macros that do the following:
 * 1.	Set a Bit in a Register
 * 2.	Clear a Bit in a Register
 * 3.	Toggle a Bit in a Register
 * 4.	Rotate Right a Register with specific number of rotations
 * 5.	Rotate Left a Register with specific number of rotations
 * 6.	Check if a Bit is Set
 * 7.	Check if a Bit is Cleared
 *
 *******************************************************************************/

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )


#endif /* COMMON_MACROS_H_ */
