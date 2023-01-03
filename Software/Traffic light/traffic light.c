#include <avr/io.h>
#include "timers.h"
#include "LCD.h"
#include "LED.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
volatile char counter1=0;
unsigned char counter_green=10;
unsigned char counter_yellow=5;
unsigned char counter_red=7;
int main(void)
{
	LCD_intial();
	LED_vInit('C',1);//green
	LED_vInit('C',2); //yellow
	LED_vInit('C',0);//red
	timer_CTC_init_interrupt();
	
	while(1)
	{
		 counter_green=10;
		 counter_yellow=5;
		 counter_red=7;
		 LCD_clear_screen();
		 LCD_send_string("Remaining 10 sec");
		 LED_vTurnOn('C',1);
		 LED_vTurnOff('C',0);
		while(counter_green>0)
		{
			if (counter1>100)
			{
				counter1=0;
				counter_green--;
				LCD_move_cursor(1,11);
				LCD_send_char(' ');
				LCD_send_char(counter_green+48);
			}
		}
		_delay_ms(500);
		LCD_clear_screen();
		LCD_send_string("Remaining 5 sec");
		LED_vTurnOff('C',1);
		LED_vTurnOn('C',2);
		
		
			while(counter_yellow>0)
			{
				if (counter1>100)
				{
					counter1=0;
					counter_yellow--;
					LCD_move_cursor(1,11);
					//LCD_send_char(' ');
					LCD_send_char(counter_yellow+48);
				}
			}
			_delay_ms(500);
			LCD_clear_screen();
			LCD_send_string("Remaining 7 sec");
			LED_vTurnOff('C',2);
			LED_vTurnOn('C',0);
			
			
			while(counter_red>0)
			{
				if (counter1>100)
				{
					counter1=0;
					counter_red--;
					LCD_move_cursor(1,11);
					//LCD_send_char(' ');
					LCD_send_char(counter_red+48);
				}
			}
	}
}
ISR(TIMER0_COMP_vect)
{
	counter1++;
}
