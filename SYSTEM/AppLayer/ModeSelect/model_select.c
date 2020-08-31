#include "model_select.h"

void ModelEntry() {
	int model_stat = -1;  //0 single 1 double 2 map
	int change_flag = 0;
	int time_count = 0;
	int i;
	while(1) {
		// read keyboard
		int key_val;
		key_val = ReadKey();
		while(!ReadKey()) { //wait for button
			key_val = ReadKey();
		}
		while(ReadKey()) {
			DelayMs(10);
			key_val = ReadKey();
			if(key_val==1) {
				BuzzerSet();
				time_count += 10;  // + 10ms
				while(!ReadKey())
					BuzzerReset();
			} else {
				BuzzerReset();
			}
		}
		
		if(time_count > 0) {
			if(time_count > 500) {
				change_flag = 1;
			} else {
				model_stat++;
				// model stat loop
				if(model_stat >= 3) {
					model_stat = 0;
				}
			}
			time_count = 0;
		}
		
		// model entry
		switch(model_stat) {
			case 0:  //single tracking
				D3Reset();
				D4Reset();
				D4Set();
				if (change_flag){
					change_flag = 0;
					for(i = 0; i <= model_stat; i++) {
						DelayMs(200);
						BuzzerSet();
						DelayMs(200);
						BuzzerReset();
					}
					SingleTrack();
				}
				break;
			case 1:	//double tracking
				D3Reset();
				D4Reset();
				D3Set();
				D4Set();
				if (change_flag){
					change_flag = 0;
					for(i = 0; i <= model_stat; i++) {
						DelayMs(200);
						BuzzerSet();
						DelayMs(200);
						BuzzerReset();
					}
					DoubleTrack();
				}
				break;
			case 2: //map
				D3Reset();
				D4Reset();
				if (change_flag){
					change_flag = 0;
					for(i = 0; i <= model_stat; i++) {
						DelayMs(200);
						BuzzerSet();
						DelayMs(200);
						BuzzerReset();
					}
					RunMaze();
				}
				break;
		}
	}
}
