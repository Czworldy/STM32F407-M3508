#ifndef _IO_H
#define _IO_H

#define ON 0
#define OFF 1

#define LED1 PIout(6)
#define LED2 PIout(7)
#define LED3 PEout(2)
#define LED4 PEout(4)
//#define LED5 PFout(9)
//#define LED6 PFout(10)

void IO_Init(void);
void EXTI_Config(void);
#endif
