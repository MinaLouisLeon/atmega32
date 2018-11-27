/*
 * keypad_CONFIG.h
 *
 * Created: 11/26/2018 5:55:42 PM
 *  Author: Mina Louis
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/**********************************

 Default connection of keypad ==>
	
	row 4 ==> PORTA pin 0
	row 3 ==> PORTA pin 1
	row 2 ==> PORTA pin 2
	row 1 ==> PORTA pin 3
	
	col 3 ==> PORTA pin 4
	col 2 ==> PORTA pin 5
	col 1 ==> PORTA pin 6
	
***********************************/	 

#define keypad_PORT PORTA
#define keypad_PIN PINA
#define keypad_DDR DDRA

#endif /* KEYPAD_CONFIG_H_ */