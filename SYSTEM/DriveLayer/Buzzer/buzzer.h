#ifndef __BUZZER_H__
#define __BUZZER_H__
#include "stm32f10x.h"

#define BUZZER_PIN         GPIO_Pin_3
#define BUZZER_GPIO        GPIOC


void BuzzerInit(void);

void BuzzerSet(void);

void BuzzerReset(void);

#endif
