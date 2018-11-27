/* 
 *  Author: Mina Louis
 */
#ifndef _DIO_INT_H_
#define _DIO_INT_H_

void pinDir(u8 port,u8 pinNumber,u8 direction);
u8 GetPin(u8 port,u8 pinNumber);
void pinWrite(u8 port ,u8 pinNumber,u8 value);


#endif