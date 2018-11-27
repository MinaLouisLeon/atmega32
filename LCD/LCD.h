/*
 * LCD.h
 *
 * Created: 8/1/2018 10:55:38 AM
 *  Author: Mina Louis
 */ 


#ifndef LCD_H_
#define LCD_H_

u8 LCD_Command(u8 Command);
u8 LCD_Print_Char(u8 Char);
u8 LCD_4Wire_Out(u8 data);
void LCD_Print_String(u8* Str);
u8 LCD_init(void);
void LCD_gotoXY(u8 x,u8 y);

#endif /* LCD_H_ */