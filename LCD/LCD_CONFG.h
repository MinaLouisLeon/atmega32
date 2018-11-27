/*
 * LCD_CONFG.h
 *
 * Created: 8/1/2018 10:42:18 AM
 *  Author: Mina Louis
 */ 


#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_

#define LCD_WIRE LCD_4_Wire //LCD_8_Wire or LCD_4_Wire
//For 8 Wire connection 
//	(DB7 > PIN 7 , DB6 > PIN 6 .......... DB0 > PIN 0)
#define LCD_PORT PORTD
#define LCD_DDR	 DDRD

#define LCD_E_PORT PORTC
#define LCD_E_DDR DDRC
#define LCD_E_pinNumber 2

#define LCD_RS_PORT PORTC
#define LCD_RS_DDR DDRC
#define LCD_RS_pinNumber 0

#define LCD_RW_PORT PORTC
#define LCD_RW_DDR DDRC
#define LCD_RW_pinNumber 1

//For 4 Wire connection 

#define LCD_DB7_PORT PORTD
#define LCD_DB7_DDR DDRD
#define LCD_DB7_pinNumber 7

#define LCD_DB6_PORT PORTD
#define LCD_DB6_DDR DDRD
#define LCD_DB6_pinNumber 6

#define LCD_DB5_PORT PORTD
#define LCD_DB5_DDR DDRD
#define LCD_DB5_pinNumber 5

#define LCD_DB4_PORT PORTD
#define LCD_DB4_DDR DDRD
#define LCD_DB4_pinNumber 4

#endif /* LCD_CONFG_H_ */