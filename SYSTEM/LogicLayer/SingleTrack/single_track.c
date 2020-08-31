#include "single_track.h"
#define SPEED 50
#define TIME 5
#define DELAY 0
void SingleTrack(void) {
	uint8_t track_stat;
	uint8_t pre_track_stat;
	track_stat = STOP;
	pre_track_stat = track_stat;
	while(1) {
		if(TRACK_L_IO == WHITE_AREA && TRACK_R_IO == WHITE_AREA)
			track_stat = RUN;
		else if (TRACK_L_IO == BLACK_AREA && TRACK_R_IO == WHITE_AREA)
			track_stat = LEFT;
		else if (TRACK_R_IO == BLACK_AREA & TRACK_L_IO == WHITE_AREA)
			track_stat = RIGHT;
		else track_stat = pre_track_stat;
		switch(track_stat) {
			case RUN:
				MotionRun(SPEED,TIME);
				break;
			case BACK:
				MotionBack(SPEED,TIME);
				break;
			case LEFT:
				MotionSpinLeft(SPEED,TIME);
				break;
			case RIGHT:
				MotionSpinRight(SPEED,TIME);
				break;
			case STOP:
				MotionStop(TIME);
				break;
			default:
				break;
		}
		pre_track_stat = track_stat;
		//DelayMs(DELAY);
	}
}
