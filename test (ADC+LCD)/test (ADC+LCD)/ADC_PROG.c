/*
 * ADC_PROG.c
 *
 * Created: 8/2/2018 8:48:54 AM
 *  Author: Mina Louis
 */ 
#include "Types.h"
#include "ADC_CONFIG.h"
#include "ADC_PRIV.h"
void ADC_init(){
	ADCSRA|=(1<<ADEN);
	#if Convertion_Speed == ADC_CK2
	ADCSRA&=~(1<<ADPS2);
	ADCSRA&=~(1<<ADPS1);
	ADCSRA|=(1<<ADPS0);
	#elif Convertion_Speed == ADC_CK4
	ADCSRA&=~(1<<ADPS2);
	ADCSRA|=(1<<ADPS1);
	ADCSRA&=~(1<<ADPS0);
	#elif Convertion_Speed == ADC_CK8
	ADCSRA&=~(1<<ADPS2);
	ADCSRA|=((1<<ADPS1)|(1<<ADPS0));
	#elif Convertion_Speed == ADC_CK16
	ADCSRA|=(1<<ADPS2);
	ADCSRA&=~(1<<ADPS1);
	ADCSRA&=~(1<<ADPS0);
	#elif Convertion_Speed == ADC_CK32
	ADCSRA|=((1<<ADPS2)|(1<<ADPS0));
	ADCSRA&=~(1<<ADPS1);
	#elif Convertion_Speed == ADC_CK64
	ADCSRA|=((1<<ADPS2)|(1<<ADPS1));
	ADCSRA&=~(1<<ADPS0);
	#elif Convertion_Speed == ADC_CK128
	ADCSRA|=((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
	#endif
	#if Reference_Voltage == ADC_AREF
	ADMUX&=~(1<<REFS1);
	ADMUX&=~(1<<REFS0);
	#elif Reference_Voltage == ADC_AVCC
	ADMUX&=~(1<<REFS1);
	ADMUX|=(1<<REFS0);
	#elif Reference_Voltage == ADC_Internal
	ADMUX|=((1<<REFS1)|(1<<REFS0));
	#endif
	ADMUX|=(1<<ADLAR);
}

u8 analogRead(u8 pinNumber){
	ADC_DDR&=~(1<<pinNumber);
	ADCSRA|=(1<<ADSC);
	while(!(ADCSRA&(1<<ADIF))>>ADIF){}
	return ADCH;
}