/*
 * I2C.h
 *
 * Created: 12/6/2018 1:12:05 PM
 *  Author: Mina Louis
 */ 


#ifndef I2C_H_
#define I2C_H_

void I2C_Init_Master(u8 Mode,u32 Clock);
void I2C_Slave(u8 address);
u8 I2C_Read(u8 ack);
void I2C_Start(void);
void I2C_Write(u8 data);
void I2C_Stop(void);


#endif /* I2C_H_ */