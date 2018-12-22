/*
 * USART.h
 *
 * Created: 12/20/2018 7:30:51 PM
 *  Author: Mina Louis
 */ 


#ifndef USART_H_
#define USART_H_

void USART_Init(void);
void USRAT_Transmit(u8 Data);
u8 USART_Receive(void);


#endif /* USART_H_ */