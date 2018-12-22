/*
 * LCD_PRIV.h
 *
 * Created: 8/1/2018 10:32:51 AM
 *  Author: Mina Louis
 */ 


#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define Wire8				 0x38
#define Wire4				 0x28
#define ClearDisplay		 0x01
#define ReturnHome			 0x02
#define ShiftCursorLeft		 0x04
#define ShiftCursorRight	 0x06
#define ShiftDisplayLeft	 0x07
#define ShiftDisplayRight	 0x05
#define DisplayOffCursorOff  0x08
#define DisplayOnCursorOff	 0x0C
#define DisplayOnCursorOn	 0x0F
#define CursorToLine1		 0x80	
#define CursorToLine2		 0xC0
#define LCD_4_Wire 4
#define LCD_8_Wire 8

#endif /* LCD_PRIV_H_ */