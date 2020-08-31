#ifndef __RUN_MAZE_H__
#define __RUN_MAZE_H__
#include "stm32f10x.h"
#include "..\SYSTEM\Common\delay.h"
#include "..\SYSTEM\DriveLayer\Motion\motion.h"
#include "..\SYSTEM\DriveLayer\UltrasonicAvoid\ultrasonic_avoid.h"
#include "..\SYSTEM\DriveLayer\Steer\steer.h"

int FrontDetect(void);
int LeftDetect(void);
int RightDetect(void);

void RunMaze(void);

#endif
