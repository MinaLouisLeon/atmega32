/* 
 *  Author: Mina Louis
 */
#include "Types.h"
#include  "DIO_priv.h"


void pinDir(u8 port,u8 pinNumber,u8 direction){
	switch(direction){
		case 'I':
		case 'i':
		switch(port){
			case 'A':
			case 'a':
			DDRA&=~(1<<pinNumber);
			break;
			case 'B':
			case 'b':
			DDRB&=~(1<<pinNumber);
			break;
			case 'C':
			case 'c':
			DDRC&=~(1<<pinNumber);
			break;
			case 'D':
			case 'd':
			DDRD&=~(1<<pinNumber);
			break;
		}	
		break;
		case 'O':
		case 'o':
		switch(port){
			case 'A':
			case 'a':
			DDRA|=(1<<pinNumber);
			break;
			case 'B':
			case 'b':
			DDRB|=(1<<pinNumber);
			break;
			case 'C':
			case 'c':
			DDRC|=(1<<pinNumber);
			break;
			case 'D':
			case 'd':
			DDRD|=(1<<pinNumber);
			break;
		}
		break;
	}
}

void pinWrite(u8 port ,u8 pinNumber,u8 value){
	switch(value){
		case 'L':
		case 'l':
		switch(port){
			case 'A':
			case 'a':
			PORTA&=~(1<<pinNumber);
			break;
			case 'B':
			case 'b':
			PORTB&=~(1<<pinNumber);
			break;
			case 'C':
			case 'c':
			PORTC&=~(1<<pinNumber);
			break;
			case 'D':
			case 'd':
			PORTD&=~(1<<pinNumber);
			break;
		}	
		break;
		case 'H':
		case 'h':
		switch(port){
			case 'A':
			case 'a':
			PORTA|=(1<<pinNumber);
			break;
			case 'B':
			case 'b':
			PORTB|=(1<<pinNumber);
			break;
			case 'C':
			case 'c':
			PORTC|=(1<<pinNumber);
			break;
			case 'D':
			case 'd':
			PORTD|=(1<<pinNumber);
			break;
		}
		break;
	}	
}

u8 GetPin(u8 port,u8 pinNumber){
	switch(port){
		case 'A':
		case 'a':
			return (PINA&=(1<<pinNumber))>>pinNumber;
		break;
		case 'B':
		case 'b':
			return (PINB&=(1<<pinNumber))>>pinNumber;
		break;
		case 'C':
		case 'c':
			return (PINC&=(1<<pinNumber))>>pinNumber;
		break;
		case 'D':
		case 'd':
			return (PIND&=(1<<pinNumber))>>pinNumber;
		break;
	}
}