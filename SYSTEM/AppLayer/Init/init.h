#ifndef __INIT_H__
#define __INIT_H__

#include "..\SYSTEM\DriveLayer\Led\led.h"
#include "..\SYSTEM\DriveLayer\Key\key.h"
#include "..\SYSTEM\DriveLayer\Buzzer\buzzer.h"
#include "..\SYSTEM\DriveLayer\Motion\motion.h"
#include "..\SYSTEM\DriveLayer\Track\track.h"
#include "..\SYSTEM\DriveLayer\UltrasonicAvoid\ultrasonic_avoid.h"
#include "..\SYSTEM\DriveLayer\Steer\steer.h"
#include "..\SYSTEM\Common\delay.h"
#include "..\SYSTEM\Common\timer.h"
#include "..\SYSTEM\Common\usart.h"

void Init(void);

#endif
