/*
 * ADC.h
 *
 *  Created on: 27/5/2016
 *      Author: diego
 */

#ifndef ADC_H_
#define ADC_H_

/*==================[inclusions]=============================================*/
#include "stdint.h"


/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2










/*==================[typedef]================================================*/
//typedef enum {ERROR = 0, SUCCESS = !ERROR} Status;
//typedef enum {RESET = 0, SET = !RESET} FlagStatus;
/*==================[external data declaration]==============================*/


/*==================[external functions declaration]=========================*/

/*void ADC_Config();*/
void ADC_Init();

uint16_t ADC_Leer();
/*uint8_t ADC_Leer_Estado();*/






#endif /* ADC_H_ */
