#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "..\SYSTEM\Common\sys.h" 

#define USART_REC_LEN  			200 
#define EN_USART1_RX 			1	
	  	
extern u8  USART_RX_BUF[USART_REC_LEN];
extern u16 USART_RX_STA;

void UsartInit(u32 bound);
#endif


