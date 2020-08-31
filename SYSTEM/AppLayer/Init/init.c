#include "init.h"

void Init() {
	DelayInit();
	BuzzerInit();
	LedInit();
	KeyInit();
	TrackInit();
	MotionInit(7199, 0);
	MotionStop(500);
	TimerInit(5000,7199);
	UsartInit(115200);
	SteerInit(9999, 143);
	UltrasonicInit();
}
