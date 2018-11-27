/*
 * PWM.h
 *
 * Created: 11/26/2018 6:56:16 PM
 *  Author: Mina Louis
 */ 


#ifndef PWM_H_
#define PWM_H_

void PWM(u8 TimerX,u8 value);
// TimerX ==> (Timer0 or Timer2)
void PWM_Timer1(u16 value);

#endif /* PWM_H_ */