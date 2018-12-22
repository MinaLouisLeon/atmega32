/*
 * USART_PROG.c
 *
 * Created: 12/20/2018 7:30:37 PM
 *  Author: Mina Louis
 */ 

#include "Types.h"
#include "USART_PRIV.h"
#include "USART_CONFIG.h"

#define BAUTERATE ((F_CPU)/(BaudRate*16UL)-1)

void USART_Init(void){
	//Set the bautrate
	UBRRH = (BAUTERATE>>8);
	UBRRL = BAUTERATE;
	//enable receiver & transmitter
	UCSRB |= (1<<TXEN)|(1<<RXEN);
	//Set data size
	#if DataSize == 5
	#elif DataSize == 6
	#elif DataSize == 7
	#elif DataSize == 8
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	#elif DataSize ==9
	#endif
}
void USRAT_Transmit(u8 Data){
	while(!(UCSRA&(1<<UDRE))){}
	UDR =Data;
}
u8 USART_Receive(void){
	while(!(UCSRA&(1<<RXC))){}
	return UDR;
}