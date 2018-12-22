/*
 * LCD_PROG.c
 *
 * Created: 8/1/2018 10:56:22 AM
 *  Author: Mina Louis
 */ 
#include "Types.h"
#include "DIO_priv.h"
#include "LCD_PRIV.h"
#include "LCD_CONFG.h"
#define F_CPU 8000000
#include <util/delay.h>

u8 LCD_4Wire_Out(u8 data){
	if((data&(1<<7))>>7){LCD_DB7_PORT|=(1<<LCD_DB7_pinNumber);}
	else{LCD_DB7_PORT&=~(1<<LCD_DB7_pinNumber);}
	if((data&(1<<6))>>6){LCD_DB6_PORT|=(1<<LCD_DB6_pinNumber);}
	else{LCD_DB6_PORT&=~(1<<LCD_DB6_pinNumber);}
	if((data&(1<<5))>>5){LCD_DB5_PORT|=(1<<LCD_DB5_pinNumber);}
	else{LCD_DB5_PORT&=~(1<<LCD_DB5_pinNumber);}
	if((data&(1<<4))>>4){LCD_DB4_PORT|=(1<<LCD_DB4_pinNumber);}
	else{LCD_DB4_PORT&=~(1<<LCD_DB4_pinNumber);}
	return 1;
}

void LCD_Command(u8 Command){
	LCD_RS_PORT&=~(1<<LCD_RS_pinNumber);
	LCD_RW_PORT&=~(1<<LCD_RW_pinNumber);
	#if LCD_WIRE == LCD_8_Wire
	LCD_PORT=Command;
	LCD_E_PORT|=(1<<LCD_E_pinNumber);
	_delay_us(5);
	LCD_E_PORT&=~(1<<LCD_E_pinNumber);
	if(Command==0x01 || Command==0x02){_delay_ms(2);}
	else{_delay_us(100);}
	#elif LCD_WIRE == LCD_4_Wire
	LCD_4Wire_Out(Command);
	//LCD_PORT=Command;
	LCD_E_PORT|=(1<<LCD_E_pinNumber);
	_delay_us(5);
	LCD_E_PORT&=~(1<<LCD_E_pinNumber);
	if(Command==0x01 || Command==0x02){_delay_ms(2);}
	else{_delay_us(100);}
	Command=(Command<<4);
	LCD_4Wire_Out(Command);
	//LCD_PORT=Command;
	LCD_E_PORT|=(1<<LCD_E_pinNumber);
	_delay_us(5);
	LCD_E_PORT&=~(1<<LCD_E_pinNumber);
	if(Command==0x01 || Command==0x02){_delay_ms(2);}
	else{_delay_us(100);}
	_delay_ms(100);
	#endif
}
u8 LCD_Print_Char(u8 Char){
	LCD_RS_PORT|=(1<<LCD_RS_pinNumber);
	LCD_RW_PORT&=~(1<<LCD_RW_pinNumber);
	#if LCD_WIRE == LCD_8_Wire
	LCD_PORT=Char;
	LCD_E_PORT|=(1<<LCD_E_pinNumber);
	_delay_us(5);
	LCD_E_PORT&=~(1<<LCD_E_pinNumber);
	_delay_us(100);
	#elif LCD_WIRE == LCD_4_Wire
	LCD_4Wire_Out(Char);
	//LCD_PORT=Char;
	LCD_E_PORT|=(1<<LCD_E_pinNumber);
	_delay_us(5);
	LCD_E_PORT&=~(1<<LCD_E_pinNumber);
	_delay_us(100);
	Char=(Char<<4);
	LCD_4Wire_Out(Char);
	//LCD_PORT=Char;
	LCD_E_PORT|=(1<<LCD_E_pinNumber);
	_delay_us(5);
	LCD_E_PORT&=~(1<<LCD_E_pinNumber);
	_delay_us(100);
	#endif
	return 1;
}
void LCD_gotoXY(u8 x,u8 y){
	const u8 charRow[]={0x80,0xC0};
		LCD_Command(charRow[x]+y);
}
void LCD_Print_String(u8* Str){
	u8 i=0;
	while (Str[i]!=0){
		LCD_Print_Char(Str[i]);
		i++;
	}
}
u8 LCD_init(void){
	LCD_E_DDR|=(1<<LCD_E_pinNumber);
	LCD_RS_DDR|=(1<<LCD_RS_pinNumber);
	LCD_RW_DDR|=(1<<LCD_RW_pinNumber);
	#if (LCD_WIRE == LCD_8_Wire)
	LCD_DDR=0xff;
	_delay_ms(15);
	LCD_Command(Wire8);
	LCD_Command(DisplayOnCursorOff);
	LCD_Command(ClearDisplay);
	LCD_Command(Wire8);
	#elif (LCD_WIRE == LCD_4_Wire)
	LCD_DB7_DDR|=(1<<LCD_DB7_pinNumber);
	LCD_DB6_DDR|=(1<<LCD_DB6_pinNumber);
	LCD_DB5_DDR|=(1<<LCD_DB5_pinNumber);
	LCD_DB4_DDR|=(1<<LCD_DB4_pinNumber);
	_delay_ms(15);
	LCD_Command(0X33);
	LCD_Command(0X32);
	LCD_Command(Wire4);
	LCD_Command(DisplayOnCursorOff);
	LCD_Command(ClearDisplay);
	#endif
	return 1;
}
