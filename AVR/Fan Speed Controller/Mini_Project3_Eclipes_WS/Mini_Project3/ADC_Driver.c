 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_Driver.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "ADC_Driver.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType* Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * 1 Bit:  REFS1:0 --> Choose the required reference voltage according the Structure defined in Main
	 * 1 Bit:  ADLAR   = 0 right adjusted
	 * 5 Bits: MUX4:0  = 00000 to choose channel 0 as initialization
	 */

	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);

	/* ADCSRA Register Bits Description:
	 * 1 Bit:  ADEN    = 1 Enable ADC
	 * 1 Bit:  ADIE    = 0 Disable ADC Interrupt
	 * 1 Bit:  ADATE   = 0 Disable Auto Trigger
	 * 3 Bits: ADPS2:0 - to choose ADC_Clock --> ADC must operate in range 50-200Khz
	 *
	 * 2 Bits: ADIF "ADC Interrupt Flag" and ADSC "ADC Start Conversion" will be discussed in next function
	 */
	ADCSRA = (ADCSRA & 0x00) | (1<<ADEN); /* Enable the ADC */

	ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr->prescaler) & 0x07); /* Choose the Required prescaler according the Structure defined in Main */

}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
