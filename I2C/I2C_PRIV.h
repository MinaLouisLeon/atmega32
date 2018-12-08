/*
 * I2C_PRIV.h
 *
 * Created: 12/6/2018 12:56:33 PM
 *  Author: Mina Louis
 */ 


#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_

#define TWSR *((volatile u8 *)0x01)
#define TWBR *((volatile u8 *)0x00)
#define TWCR *((volatile u8 *)0x38)
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
#define TWIE	0
#define TWDR *((volatile u8 *)0x03)
#define TWAR *((volatile u8 *)0x02)


#endif /* I2C_PRIV_H_ */