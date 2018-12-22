/*
 * SPI.h
 *
 * Created: 12/20/2018 6:18:10 PM
 *  Author: Mina Louis
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
u8 SPI_MasterTransmit(u8 Data);
u8 SPI_SlaveReceive(u8 Data);


#endif /* SPI_H_ */