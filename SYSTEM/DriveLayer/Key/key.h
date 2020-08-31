#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f10x.h"

#define KEY_PIN					GPIO_Pin_2
#define KEY_GPIO				GPIOC

void KeyInit(void);

uint8_t ReadKey(void);

#endif
