#ifndef __TRACK_H__
#define __TRACK_H__

#include "stm32f10x.h"
#include "..\SYSTEM\Common\delay.h"
#include "..\SYSTEM\DriveLayer\Motion\motion.h"

void TrackInit(void);


#define TRACK_R_PIN         GPIO_Pin_7
#define TRACK_R_GPIO        GPIOA
#define TRACK_R_IO          GPIO_ReadInputDataBit(TRACK_R_GPIO, TRACK_R_PIN)

#define TRACK_L_PIN         GPIO_Pin_0
#define TRACK_L_GPIO        GPIOB
#define TRACK_L_IO          GPIO_ReadInputDataBit(TRACK_L_GPIO, TRACK_L_PIN)
#define BLACK_AREA 1
#define WHITE_AREA 0


#define STOP  0
#define RUN   1
#define BACK  2
#define LEFT  3
#define RIGHT 4
#endif
