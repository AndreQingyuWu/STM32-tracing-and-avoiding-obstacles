#ifndef __MOTION_H__
#define __MOTION_H__

#include "stm32f10x.h"
#include "Math.h"
#include "..\SYSTEM\Common\delay.h"

void MotionInit(unsigned short arr,unsigned short psc);
void SetMotionSpeed(unsigned char ucChannel,signed char cSpeed);

void MotionRun(signed char speed,int time);       //前进函数
void MotionStop(int time);               //刹车函数
void MotionLeft(signed char speed,int time);      //左转函数
void MotionSpinLeft(signed char speed,int time); //左旋转函数
void MotionRight(signed char speed,int time);     //右转函数
void MotionSpinRight(signed char speed,int time);//右旋转函数
void MotionBack(signed char speed,int time);      //后退函数


 
#define LEFT_MOTION_GO             GPIO_Pin_7
#define LEFT_MOTION_GO_GPIO        GPIOB
#define LEFT_MOTION_GO_SET         GPIO_SetBits(LEFT_MOTION_GO_GPIO,LEFT_MOTION_GO)
#define LEFT_MOTION_GO_RESET       GPIO_ResetBits(LEFT_MOTION_GO_GPIO,LEFT_MOTION_GO)

#define LEFT_MOTION_PWM            GPIO_Pin_8
#define LEFT_MOTION_PWM_GPIO       GPIOB
#define LEFT_MOTION_PWM_SET        GPIO_SetBits(LEFT_MOTION_PWM_GPIO,LEFT_MOTION_PWM)
#define LEFT_MOTION_PWM_RESET      GPIO_ResetBits(LEFT_MOTION_PWM_GPIO,LEFT_MOTION_PWM)

#define RIGHT_MOTION_GO             GPIO_Pin_4
#define RIGHT_MOTION_GPIO           GPIOA
#define RIGHT_MOTION_GO_SET         GPIO_SetBits(RIGHT_MOTION_GPIO,RIGHT_MOTION_GO)
#define RIGHT_MOTION_GO_RESET       GPIO_ResetBits(RIGHT_MOTION_GPIO,RIGHT_MOTION_GO)

#define RIGHT_MOTION_PWM            GPIO_Pin_9
#define RIGHT_MOTION_PWM_GPIO       GPIOB
#define RIGHT_MOTION_PWM_SET        GPIO_SetBits(RIGHT_MOTION_PWM_GPIO,RIGHT_MOTION_PWM)
#define RIGHT_MOTION_PWM_RESET      GPIO_ResetBits(RIGHT_MOTION_PWM_GPIO,RIGHT_MOTION_PWM)

#endif
