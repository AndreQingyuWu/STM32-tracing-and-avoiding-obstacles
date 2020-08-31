#include "led.h"


void LedInit() {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin = LED_D3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(LED_D3_PIN_GPIO, &GPIO_InitStructure);	
	GPIO_InitStructure.GPIO_Pin = LED_D4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(LED_D4_PIN_GPIO, &GPIO_InitStructure);	
}

void D3Set() {
	GPIO_SetBits(LED_D3_PIN_GPIO,LED_D3_PIN);
}

void D3Reset() {
	GPIO_ResetBits(LED_D3_PIN_GPIO,LED_D3_PIN);
}

void D4Set() {
	GPIO_SetBits(LED_D4_PIN_GPIO,LED_D4_PIN);
}

void D4Reset() {
	GPIO_ResetBits(LED_D4_PIN_GPIO,LED_D4_PIN);
}
