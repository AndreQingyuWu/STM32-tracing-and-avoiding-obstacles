#include "motion.h"

signed short sPWMR,sPWML,dPWM;

void MotionInit(unsigned short arr,unsigned short psc) {
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB , ENABLE);  
	
  GPIO_InitStructure.GPIO_Pin = LEFT_MOTION_GO;         //PB7
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
	GPIO_Init(LEFT_MOTION_GO_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = LEFT_MOTION_PWM;         //PB8
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	   //¸´ÓÃÍÆÍìÊä³ö
	GPIO_Init(LEFT_MOTION_PWM_GPIO, &GPIO_InitStructure);  
		
	
  GPIO_InitStructure.GPIO_Pin = RIGHT_MOTION_GO;       //PA4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
	GPIO_Init(RIGHT_MOTION_GPIO, &GPIO_InitStructure); 
	
	
	GPIO_InitStructure.GPIO_Pin = RIGHT_MOTION_PWM;   //PB9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
	GPIO_Init(RIGHT_MOTION_PWM_GPIO, &GPIO_InitStructure);  
	
	TIM_TimeBaseStructure.TIM_Period = arr;
	TIM_TimeBaseStructure.TIM_Prescaler =psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);  
	TIM_OC4Init(TIM4, &TIM_OCInitStructure); 
	
	TIM_CtrlPWMOutputs(TIM4,ENABLE);
  
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  //enable CH1	 
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);  //enable CH1
	
  TIM_ARRPreloadConfig(TIM4, ENABLE); //enable TIM ARR
 	TIM_Cmd(TIM4, ENABLE);  //ENABLE TIM
}

void SetMotionSpeed(unsigned char ucChannel,signed char cSpeed) {
	short sPWM;
	if (cSpeed>=100) cSpeed = 100;
	if (cSpeed<=-100) cSpeed = -100;
	
	sPWM = 7201 - fabs(cSpeed)*72;
	switch(ucChannel)
	{
		case 0://right
			TIM_SetCompare3(TIM4,sPWM);
			if (cSpeed>0) 
				RIGHT_MOTION_GO_RESET;
			else if(cSpeed<0) 
				RIGHT_MOTION_GO_SET;		
			break;
		case 1://left
		  TIM_SetCompare4(TIM4,sPWM); 
			if (cSpeed>0) 
				LEFT_MOTION_GO_SET;
			else if (cSpeed<0)
				LEFT_MOTION_GO_RESET;
			break;			
	}
}


void MotionRun(signed char speed,int time)  {
		  signed char f_speed = - speed;
	    SetMotionSpeed(1,f_speed);
			SetMotionSpeed(0,speed);
			DelayMs(time); 

}

void MotionStop(int time) {
	  SetMotionSpeed(1,0);
	  SetMotionSpeed(0,0);
	  RIGHT_MOTION_GO_RESET;
	  LEFT_MOTION_GO_RESET;
		DelayMs(time); 
}

void MotionLeft(signed char speed,int time) {
	  SetMotionSpeed(1,0);
	  SetMotionSpeed(0,speed); 
		DelayMs(time);
}
void MotionSpinLeft(signed char speed,int time) {
	  SetMotionSpeed(1,speed);
	  SetMotionSpeed(0,speed);    
		DelayMs(time);    

}
void MotionRight(signed char speed,int time) {
	  signed char f_speed = - speed;
	  SetMotionSpeed(1,f_speed);
	  SetMotionSpeed(0,0);           
		DelayMs(time);           

}
void MotionSpinRight(signed char speed,int time) {
	  signed char f_speed = - speed;
	  SetMotionSpeed(1,f_speed);
	  SetMotionSpeed(0,f_speed);         
		DelayMs(time);            
}
void MotionBack(signed char speed,int time) {
	  signed char u_speed = 100- speed;
	  signed char f_speed = - u_speed;
	  SetMotionSpeed(1,u_speed);//left
	  SetMotionSpeed(0,f_speed);//right
		DelayMs(time); 
}
