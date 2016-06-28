/*
 * DAC.c
 *
 *  Created on: 20/5/2016
 *      Author: diego
 */

/*==================[inclusions]=============================================*/





#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

#include "led.h"
#include "DAC.h"





/*==================[macros and definitions]=================================*/
/*==================[internal data declaration]==============================*/
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void Config_dac(){

	Chip_SCU_DAC_Analog_Config();
};
void Init_conv_dac(){
	Chip_DAC_Init(LPC_DAC);
	//Chip_DAC_SetBias(LPC_DAC,DAC_MAX_UPDATE_RATE_400kHz);
	//Chip_DAC_SetDMATimeOut(LPC_DAC,0xffff);
	Chip_DAC_ConfigDAConverterControl(LPC_DAC,DAC_CNT_ENA|DAC_DMA_ENA);


};
void Push_value(uint32_t value){
	Chip_DAC_UpdateValue(LPC_DAC,value);
};


