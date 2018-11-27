/*
 * ADC_PRIV.h
 *
 * Created: 8/2/2018 8:48:14 AM
 *  Author: Mina Louis
 */ 


#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

#define ADC_DDR *((volatile u8 *)0x3A)
#define ADCH *((volatile u8 *)0x25)
#define ADCL *((volatile u8 *)0x24)
#define ADCSRA *((volatile u8 *)0x26)
#define ADEN	7
#define ADSC	6
#define	ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0
#define ADMUX *((volatile u8 *)0x27)
#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

#define ADC_AVCC 1
#define ADC_AREF 0
#define ADC_Internal 2

#define ADC_CK2 0
#define ADC_CK4 1
#define ADC_CK8 2
#define ADC_CK16 3
#define ADC_CK32 4
#define ADC_CK64 5
#define ADC_CK128 6

#endif /* ADC_PRIV_H_ */