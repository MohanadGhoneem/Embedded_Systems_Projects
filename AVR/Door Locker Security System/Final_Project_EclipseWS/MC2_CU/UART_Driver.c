/*******************************************************************************
 *
 * Module: USART
 *
 * File Name: UART_Driver.c
 *
 * Description: Source file for the AVR's UART driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#include "UART_Driver.h"


void UART_init(const UART_config * cofig_Ptr)
{

	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	UCSRB |= (1 << RXEN) | (1 << TXEN);

	UCSRB = (UCSRB & 0xFB) | (cofig_Ptr->data_bits & 0x04);

	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/
	UCSRC |= (1 << URSEL) ;

	UCSRC = (UCSRC & 0xF9) | ((cofig_Ptr->data_bits & 0x03)<<1);

	/*parity*/
	UCSRC = (UCSRC & 0xCF) | (cofig_Ptr->parity << 4);

	/* stop_bit*/
	UCSRC = (UCSRC & 0xF7) | (cofig_Ptr->stop_bit << 3);

	/*mode*/
	UCSRC = (UCSRC & 0xBF) | (mode_bit << 6);

	/* U2X = 1 for double transmission speed */
	UCSRA = (UCSRA & 0xFD) | (double_speed << 1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRL = BAUD_PRESCALE;

	UBRRH = BAUD_PRESCALE >> 8;
}/*end of Uart_init function*/


void UART_sendByte(uint8 data)
{
	/* UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one */
	while (BIT_IS_CLEAR(UCSRA ,UDRE)){};
	/* put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now */
	UDR = data;
}

uint8 UART_recieveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this
	 * flag is set to one */
	while (BIT_IS_CLEAR(UCSRA ,RXC)){};
	/* Read the received data from the Rx buffer (UDR) and the RXC flag
	   will be cleared after read this data */
	return UDR;
}

void UART_sendString(const uint8 *str)
{
	uint8 i = 0;
	while (str[i] != '\0')
	{
		UART_sendByte(str[i]);
		i++;
	}
}

void UART_recieveString(uint8 *str)
{
	uint8 i = 0;
	str[i] = UART_recieveByte();
	while (str[i] != '#')
	{
		i++;
		str[i] = UART_recieveByte();
	}
	str[i] = '\0';
}
