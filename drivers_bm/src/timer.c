/*
 * timer.c
 *
 *  Created on: 29/4/2016
 *      Author: diego
 */


#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

#include "timer.h"

void IniciarTimer(){
	Chip_RIT_Init(LPC_RITIMER);
	NVIC_EnableIRQ(RITIMER_IRQn);
};
void SetTimer(uint32_t time){
	Chip_RIT_SetTimerInterval(LPC_RITIMER,time);
};
void BorrarTimer(){


	Chip_RIT_ClearInt(LPC_RITIMER);

};


