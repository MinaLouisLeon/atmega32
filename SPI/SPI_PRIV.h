/*
 * SPI_PRIV.h
 *
 * Created: 12/20/2018 6:17:26 PM
 *  Author: Mina Louis
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

#define SPCR *((volatile u8*)0x0D)
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0

#define SPSR *((volatile u8*)0x0E)
#define SPIF    7
#define WCOL    6

#define SPDR *((volatile u8*)0x0F)

#endif /* SPI_PRIV_H_ */