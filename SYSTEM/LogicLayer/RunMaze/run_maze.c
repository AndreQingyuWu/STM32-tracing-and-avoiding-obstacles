#include "run_maze.h"

#define AVOID_DISTANCE 60

int FrontDetect(void) {
	SetSteerAngle(90);
	DelayMs(100);
	return UltrasonicDetect();
}

int LeftDetect(void) {
	SetSteerAngle(175);
	DelayMs(600);
	return UltrasonicDetect();
}

int RightDetect(void){
	SetSteerAngle(5);
	DelayMs(600);
	return UltrasonicDetect();
}

void RunMaze(void) {
	int front_distance;
	int left_distance;
	int right_distance;
	while(1) {
		front_distance = FrontDetect();
		if(front_distance >= AVOID_DISTANCE) {
			MotionRun(60,10);
		} else {	
			MotionStop(2000);	
			left_distance=LeftDetect();
			DelayMs(500);
			right_distance=RightDetect();
			DelayMs(500);
			FrontDetect();
			MotionStop(500);		
			MotionBack(60,500);	
			MotionStop(1000);	
			if(left_distance > right_distance) {
				MotionLeft(60,700);
				MotionStop(500);
			}	else {
				MotionRight(60,700);
				MotionStop(500);					
			}
		}
	}
}
