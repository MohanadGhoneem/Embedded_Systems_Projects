/*
 ============================================================================
 Name        : Mini_Project2.c
 Description : Stop Watch with ATmega16
 Author      : Mohand Adel
 Date	     : 17-09-2021
 ============================================================================
 */


//Used Libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


//Global Variables
unsigned char tick = 0;
unsigned char SEC = 0;
unsigned char MIN = 0;
unsigned char HOUR = 0;


//Functions Prototypes
void TIMER1_init(void);
void INT0_init(void);
void INT1_init(void);
void INT2_init(void);


//Main Function
int main(void){
	DDRA = 0x3F;
	PORTA = 0xFF;

	DDRC = 0x0F;
	PORTC = 0x00;

	INT0_init();
	INT1_init();
	INT2_init();
	TIMER1_init();

	while(1){
		PORTA = (1<<PA5);
		PORTC = SEC % 10;
		_delay_ms(5);

		PORTA = (1<<PA4);
		PORTC = SEC / 10;
		_delay_ms(5);

		PORTA = (1<<PA3);
		PORTC = MIN % 10;
		_delay_ms(5);

		PORTA = (1<<PA2);
		PORTC = MIN / 10;
		_delay_ms(5);

		PORTA = (1<<PA1);
		PORTC = HOUR % 10;
		_delay_ms(5);

		PORTA = (1<<0);
		PORTC = HOUR / 10;
		_delay_ms(5);
	}
	return 0;
}


//Functions Declaration and ISRs
void TIMER1_init(void){
	TCNT1 = 0;    //Timer Initial Value
	OCR1A = 1000; // Set Compare Value
	TIMSK |= (1<<OCIE1A); //Timer1 CTC
	TCCR1A = (1<<FOC1A);	//Non PWM Mode
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);	//CTC Mode & Pre-Scalar
	return;
}

ISR(TIMER1_COMPA_vect){
	SEC ++;
	if (SEC == 60){
		SEC = 0;
		MIN ++;
	}
	if (MIN == 60){
		SEC = 0;
		MIN = 0;
		HOUR ++;
	}
	if (HOUR == 24){
		SEC = 0;
		MIN = 0;
		HOUR = 0 ;
	}

}

ISR(INT0_vect){
	SEC = 0;
	MIN = 0;
	HOUR = 0 ;
}

void INT0_init(void){
	SREG |= (1<<7);
	DDRD &=~ (1<<PD2);
	PORTD |= (1<<PD2);
	MCUCR |= (1<<ISC01);
	GICR |= (1<<INT0);
	return;
}

ISR(INT1_vect){
	TCCR1B &= ~(1<<CS10);
	TCCR1B &= ~(1<<CS11);
	TCCR1B &= ~(1<<CS12);
}

void INT1_init(void){
	SREG |=(1<<7);
	DDRD &= ~(1<<PD3);
	MCUCR |=(1<<ISC10)|(1<<ISC11);
	GICR |=(1<<INT1);
	return;
}

ISR(INT2_vect){
	TCCR1B = (1<<WGM12)|(1<<CS10)|(1<<CS12);
}

void INT2_init(void){
	SREG |= (1<<7);
	DDRB &= ~(1<<PB2);
	MCUCR &= ~(1<<ISC2);
	GICR |= (1<<INT2);
	return;
}
