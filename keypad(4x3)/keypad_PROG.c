/*
 * keypad_PROG.c
 *
 * Created: 11/26/2018 5:54:53 PM
 *  Author: Mina Louis
 */ 

#include "Types.h"
#include "DIO_priv.h"
#include "keypad_CONFIG.h"

u8 GetKeyPressed(void){
	u8 r=0;
	u8 c=0;
	keypad_PORT|= 0x0F;
	for(c=0;c<3;c++){
		keypad_DDR&=~(0x7f);
		keypad_DDR|=(0x40>>c);
		for(r=0;r<4;r++){
			if(!(keypad_PIN&(0x08>>r)))  {return (r*3+c);}
			}
		}
	}
}