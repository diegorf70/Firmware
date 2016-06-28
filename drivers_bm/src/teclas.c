/*
 * teclas.h
 *
 *  Created on: 29/4/2016
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

#include "teclas.h"
/*==================[macros and definitions]=================================*/
#define PUERTO_1			1

#define PIN_0				0
#define PIN_1				1
#define PIN_2				2
#define PIN_6				6


#define BIT_4				1<<4
#define BIT_8					1<<8
#define BIT_9					1<<9





#define GPIO0				0
#define GPIO1 				1



#define INPUT_PORT 				0
#define OUTPUT_PORT 				1

typedef struct{
	uint8_t puerto;
	uint32_t pin;
	uint32_t bit;
	uint8_t gpio;
}SW;

/*==================[internal data declaration]==============================*/

SW SW1={PUERTO_1,PIN_0,BIT_4,GPIO0};
SW SW2={PUERTO_1,PIN_1,BIT_8,GPIO0};
SW SW3={PUERTO_1,PIN_2,BIT_9,GPIO0};
SW SW4={PUERTO_1,PIN_6,BIT_9,GPIO1};


/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void Init_Ports_Tec(){
	/* Switches */
	   Chip_SCU_PinMux(SW1.puerto, SW1.pin, MD_PUP|MD_EZI|MD_ZI, FUNC0); /* GPIO0[4], SW1 */
	   Chip_SCU_PinMux(SW2.puerto, SW2.pin, MD_PUP|MD_EZI|MD_ZI, FUNC0); /* GPIO0[8], SW2 */
	   Chip_SCU_PinMux(SW3.puerto, SW3.pin, MD_PUP|MD_EZI|MD_ZI, FUNC0); /* GPIO0[9], SW3 */
	   Chip_SCU_PinMux(SW4.puerto, SW4.pin, MD_PUP|MD_EZI|MD_ZI, FUNC0); /* GPIO1[9], SW4 */

	   /*Chip_GPIO_SetDir(LPC_GPIO_PORT, 0,(1<<4)|(1<<8)|(1<<9),0);*/
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, SW1.gpio, SW1.bit, INPUT_PORT);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, SW2.gpio, SW2.bit, INPUT_PORT);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, SW3.gpio, SW3.bit, INPUT_PORT);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, SW4.gpio, SW4.bit, INPUT_PORT);
};

uint8_t Leer_TEC1(){

	if( Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, SW1.gpio, 4)) return 0;
	else return 1;
};
uint8_t Leer_TEC2(){

	if( Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, SW2.gpio, 8)) return 0;
	else return 1;
};
uint8_t Leer_TEC3(){

	if( Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, SW3.gpio, 9)) return 0;
	else return 1;
};
uint8_t Leer_TEC4(){
	if( Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, SW4.gpio, 9)) return 0;
	else return 1;
};

//STATIC INLINE uint32_t Chip_GPIO_ReadValue(LPC_GPIO_T *pGPIO, uint8_t portNum)

//STATIC INLINE bool Chip_GPIO_ReadPortBit(LPC_GPIO_T *pGPIO, uint32_t port, uint8_t pin)
