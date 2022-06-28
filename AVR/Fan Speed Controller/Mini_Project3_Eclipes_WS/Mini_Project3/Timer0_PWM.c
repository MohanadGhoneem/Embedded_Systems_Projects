#include <avr/io.h>
#include "Timer0_PWM.h"

/* Description:
 * Control the DC Motor direction using L293D H-bridge.
 * Control The DC Motor Speed using PWM from MC. connect the
 * PWM PIN of Timer0 OC0(PB3) to the enable of the Motor.
 * duty cycle 100% --> Maximum Speed
 * duty cycle 50%  --> Half Maximum Speed
 * duty cycle 0%   --> Motor Stop
 */

void PWM_Timer0_Init(unsigned char set_duty_cycle)
{

	TCNT0 = 0; //Set Timer Initial value

	OCR0  = set_duty_cycle; // Set Compare Value

	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
