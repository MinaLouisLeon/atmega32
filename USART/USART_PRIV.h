/*
 * USART_PRIV.h
 *
 * Created: 12/20/2018 7:31:06 PM
 *  Author: Mina Louis
 */ 


#ifndef USART_PRIV_H_
#define USART_PRIV_H_

#define UBRRH *((volatile u8*)0x20)
#define UBRRL *((volatile u8*)0x09)
#define UDR *((volatile u8*)0x0C)

#define UCSRA *((volatile u8*)0x0B)
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

#define UCSRB *((volatile u8*)0x0A)
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

#define UCSRC *((volatile u8*)0x20)
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0


#endif /* USART_PRIV_H_ */