#ifndef __ULTRASONIC_AVOID_H__
#define __ULTRASONIC_AVOID_H__

#include "..\SYSTEM\Common\usart.h"
#include "..\SYSTEM\Common\timer.h"
#include "..\SYSTEM\Common\delay.h"

#define	TRIG_GPIO      GPIOC       
#define	ECHO_GPIO      GPIOC 
#define	TRIG_PIN       GPIO_Pin_0       
#define	ECHO_PIN       GPIO_Pin_1   

void UltrasonicInit(void);
int UltrasonicDetect(void);

#endif
