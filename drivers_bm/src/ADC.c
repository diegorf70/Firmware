/*
 * ADC.c
 *
 *  Created on: 27/5/2016
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


#include "ADC.h"





/*==================[macros and definitions]=================================*/
/*==================[internal data declaration]==============================*/
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
ADC_CLOCK_SETUP_T ADCsetup;


/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/


/*void ADC_Config(){

	//Chip_SCU_ADC_Channel_Config(LPC_ADC0,ADC_CH1);


};*/
void ADC_Init(){

	Chip_ADC_Init(LPC_ADC0, & ADCsetup);
	Chip_ADC_EnableChannel(LPC_ADC0,ADC_CH1, ENABLE);
	//Chip_ADC_SetSampleRate(LPC_ADC0, &ADCsetup,ADC_MAX_SAMPLE_RATE);

};

uint16_t ADC_Leer(){

	uint16_t data = 0 ;
	Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW, ADC_TRIGGERMODE_RISING);

	while (Chip_ADC_ReadStatus(LPC_ADC0, ADC_CH1, ADC_DR_DONE_STAT) != SET){}

	Chip_ADC_ReadValue(LPC_ADC0,ADC_CH1, &data);



	return data;
};
/*uint8_t ADC_Leer_Estado(){
	return Chip_ADC_ReadStatus(LPC_ADC0,ADC_CH1,ADC_DR_DONE_STAT);
};
*/
