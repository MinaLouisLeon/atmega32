/*
 * PWM_PRIV.h
 *
 * Created: 11/26/2018 6:56:57 PM
 *  Author: Mina Louis
 */ 


#ifndef PWM_PRIV_H_
#define PWM_PRIV_H_

#define TCCR0 *((volatile u8 *)0x33)
#define WGM00 6
#define WGM01 3
#define COM00 4
#define COM01 5
#define CS00 0
#define CS01 1
#define CS02 2
#define OCR0 *((volatile u8 *)0x3C)

#define TCCR2 *((volatile u8 *)0x25)
#define WGM20 6
#define WGM21 3
#define COM21 5
#define COM20 4
#define CS22 2
#define CS21 1
#define CS20 0
#define OCR2 *((volatile u8 *)0x23)

#endif /* PWM_PRIV_H_ */