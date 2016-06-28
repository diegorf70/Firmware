/*
 * teclas.h
 *
 *  Created on: 29/4/2016
 *      Author: diego
 */

#ifndef TECLAS_H_
#define TECLAS_H_
/*==================[inclusions]=============================================*/
#include "stdint.h"

/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/


/*==================[external functions declaration]=========================*/
void Init_Ports_Tec();
uint8_t Leer_TEC1();
uint8_t Leer_TEC2();
uint8_t Leer_TEC3();
uint8_t Leer_TEC4();
#endif /* TECLAS_H_ */
