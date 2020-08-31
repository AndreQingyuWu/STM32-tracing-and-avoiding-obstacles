#include "ultrasonic_avoid.h"

float UltrasonicWave_Distance;      //¼ÆËã³öµÄ¾àÀë    

void UltrasonicInit(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;	
	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO, ENABLE);
    
  GPIO_InitStructure.GPIO_Pin = TRIG_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	         
  GPIO_Init(TRIG_GPIO, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = ECHO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(ECHO_GPIO,&GPIO_InitStructure);
	
 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource1);

 	EXTI_InitStructure.EXTI_Line = EXTI_Line1;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
			
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

int UltrasonicDetect(void) {
  int u_temp;
	GPIO_SetBits(TRIG_GPIO,TRIG_PIN);
  DelayUs(20);
  GPIO_ResetBits(TRIG_GPIO,TRIG_PIN);
	u_temp = UltrasonicWave_Distance*10;
	return u_temp;
}

void EXTI1_IRQHandler(void) {
	DelayUs(10);		         
  if(EXTI_GetITStatus(EXTI_Line1) != RESET) {
			TIM_SetCounter(TIM2,0);
			TIM_Cmd(TIM2, ENABLE);
		
			while(GPIO_ReadInputDataBit(ECHO_GPIO,ECHO_PIN));

			TIM_Cmd(TIM2, DISABLE);
			UltrasonicWave_Distance=TIM_GetCounter(TIM2)*5*34/200.0;

			EXTI_ClearITPendingBit(EXTI_Line1);
	}
}
