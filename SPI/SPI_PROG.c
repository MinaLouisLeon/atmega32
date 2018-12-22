/*
 * SPI_PROG.c
 *
 * Created: 12/20/2018 6:18:34 PM
 *  Author: Mina Louis
 */ 

#include "Types.h"
#include "DIO_priv.h"
#include "SPI_PRIV.h"
#include "SPI_CONFIG.h"

void SPI_MasterInit(void){
	//Set MOSI , SCK & SS (output)
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
	//set MISO (input)
	DDRB &=~(1<<MISO);
	//Enable SPI in master mode with clock (clk/16)
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
u8 SPI_MasterTransmit(u8 Data){
	SPDR=Data;
	while(!(SPSR&(1<<SPIF))){}
	return SPDR;
}
void SPI_SlaveInit(void){
	//set MISO (output)
	DDRB |= (1<<MISO);
	//set MOSI , SCK & SS (input)
	DDRB &=~(1<<MOSI) &~(1<<SCK) &~(1<<SS);
	//enable SPI in slave mode
	SPCR =(1<<SPE);
}
u8 SPI_SlaveReceive(u8 Data){
	SPRD = Data;
	while(!(SPSR&(1<<SPIF))){}
	return SPDR;
}