/*
 * I2C_PROG.c
 *
 * Created: 12/6/2018 12:57:15 PM
 *  Author: Mina Louis
 */ 

#include "Types.h"
#include "I2C_PRIV.h"
#include "I2C_CONFIG.h"

void I2C_Init_Master(u32 Clock){
	TWSR = 0x00; //No prescaler
	TWBR = Clock;
}

void I2C_Start(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while ((TWCR & 0x80) == 0){}
}

void I2C_Stop(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void I2C_Write(u8 data){
	TWDR = data;
	TWCR = (1<<TWCR)|(1<<TWEN);
	while ((TWCR & 0x80) == 0){}
}

void I2C_Slave(u8 address){
	TWAR = address;
}

u8 I2C_Read(u8 ack){
	TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
	while ((TWCR & 0x80)==0){}
	return TWDR;
}