#ifndef __STEER_H__
#define __STEER_H__
#include "stm32f10x.h"                  // Device header

void SteerInit(u16 arr,u16 psc);
void SetSteerAngle(float angle);

#endif
