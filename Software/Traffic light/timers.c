/*
 * timers.c
 *
 * Created: 12/30/2022 4:42:39 PM
 *  Author: User
 */ 
#include "timers.h"
void timer_CTC_init_interrupt(void)
{
	/*select CTC Mode*/
	SET_BIT(TCCR0,WGM01);
	/*load value on OCR0*/
	OCR0=80;
	/*select timer clock*/
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/*enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
}
