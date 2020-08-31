#ifndef __LED_H__
#define __LED_H__
#include "stm32f10x.h"

//LED D3
#define LED_D3_PIN       GPIO_Pin_6
#define LED_D3_PIN_GPIO  GPIOB

//LED D4
#define LED_D4_PIN       GPIO_Pin_6
#define LED_D4_PIN_GPIO  GPIOA

void LedInit(void);

void D3Set(void);

void D3Reset(void);

void D4Set(void);

void D4Reset(void);

#endif
