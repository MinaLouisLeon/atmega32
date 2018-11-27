/*
 * PWM_PROG.c
 *
 * Created: 11/26/2018 6:55:59 PM
 *  Author: Mina Louis
 */ 

#include "Types.h"
#include "DIO_priv.h"
#include "PWM_PRIV.h"

void PWM(u8 TimerX,u8 value){
	switch (TimerX){
		case 0:
		TCCR0|=((1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS02)|(1<<CS01)|(1<<CS00));
		OCR0 = value;
		DDRB|=(1<<3);
		break;
		case 1:
		TCCR2|=((1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS22)|(1<<CS21)|(1<<CS20));
		OCR2 =value;
		DDRD|=(1<<7);
		break;
	}
}