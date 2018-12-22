/*
 * test__ADC_LCD_.c
 *
 * Created: 8/2/2018 9:41:13 AM
 *  Author: Mina Louis
 */ 


#include "Types.h"
#include "ADC.h"
#include "LCD.h"
#include "DIO_int.h"
#include <stdlib.h>
#include <avr/interrupt.h>
int main(void)
{
	LCD_init();
	ADC_init();
	LCD_Print_String("Voltage =");
	f32 result[5];
	pinDir('A',1,'i');
    while(1)
    {
		LCD_gotoXY(0,11);
		u8 x=analogRead(0);
		f32 y=x/51.0;
		dtostrf(y,10,10,result);
		LCD_Print_String(result);
    }
}