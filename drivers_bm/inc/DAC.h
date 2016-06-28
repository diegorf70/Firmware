/*
 * DAC.h
 *
 *  Created on: 20/5/2016
 *      Author: diego
 */

#ifndef DAC_H_
#define DAC_H_

/*==================[inclusions]=============================================*/
#include "stdint.h"


/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2










/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/


/*==================[external functions declaration]=========================*/
void Config_dac();
void Init_conv_dac();
void Push_value(uint32_t value);



#endif /* DAC_H_ */
