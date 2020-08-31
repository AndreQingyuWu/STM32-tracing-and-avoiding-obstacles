#include "key.h"

void KeyInit() {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = KEY_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//up
 	GPIO_Init(KEY_GPIO, &GPIO_InitStructure);
}

uint8_t ReadKey() {
	return GPIO_ReadInputDataBit(KEY_GPIO,KEY_PIN);
}
