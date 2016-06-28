/* Copyright 2016, Diego Ferreyra
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal driver led
 **
 **
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal LED Driver
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
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





/*==================[macros and definitions]=================================*/
#define PUERTO_2			2

#define PIN_10				10
#define PIN_11				11
#define PIN_12				12

#define PIN_00				0
#define PIN_01				1
#define PIN_02				2

#define BIT_14				1<<14
#define BIT_11					1<<11
#define BIT_12					1<<12

#define BIT_0					1<<0
#define BIT_1					1<<1
#define BIT_2					1<<2


#define GPIO0				0
#define GPIO1 				1
#define GPIO5 				5


#define INPUT_PORT 				0
#define OUTPUT_PORT 				1

typedef struct{
	uint8_t puerto;
	uint32_t pin;
	uint32_t bit;
	uint8_t gpio;
}LED;


/*==================[internal data declaration]==============================*/


LED led1={PUERTO_2,PIN_10,BIT_14,GPIO0};

LED led2={PUERTO_2,PIN_11,BIT_11,GPIO1};

LED led3={PUERTO_2,PIN_12,BIT_12,GPIO1};

LED led0R={PUERTO_2,PIN_00,BIT_0,GPIO5};

LED led0G={PUERTO_2,PIN_01,BIT_1,GPIO5};

LED led0B={PUERTO_2,PIN_02,BIT_2,GPIO5};


/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void Init_Ports_Leds(){

	 Chip_GPIO_Init(LPC_GPIO_PORT);

	 /* LEDs */
	 Chip_SCU_PinMux(led0R.puerto,led0R.pin,MD_PUP,FUNC4);  /* GPIO5[0], LED0R */
	 Chip_SCU_PinMux(led0G.puerto,led0G.pin,MD_PUP,FUNC4);  /* GPIO5[1], LED0G */
	 Chip_SCU_PinMux(led0B.puerto,led0B.pin,MD_PUP,FUNC4);  /* GPIO5[2], LED0B */
	 Chip_SCU_PinMux(led1.puerto,led1.pin,MD_PUP,FUNC0); /* GPIO0[14], LED1 */
	 Chip_SCU_PinMux(led2.puerto,led2.pin,MD_PUP,FUNC0); /* GPIO1[11], LED2 */
	 Chip_SCU_PinMux(led3.puerto,led3.pin,MD_PUP,FUNC0); /* GPIO1[12], LED3 */

	 /*Chip_GPIO_SetDir(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2),1);*/
	 Chip_GPIO_SetDir(LPC_GPIO_PORT, led0R.gpio,led0R.bit,OUTPUT_PORT);
	 Chip_GPIO_SetDir(LPC_GPIO_PORT, led0G.gpio,led0G.bit,OUTPUT_PORT);
	 Chip_GPIO_SetDir(LPC_GPIO_PORT, led0B.gpio,led0B.bit,OUTPUT_PORT);
	 Chip_GPIO_SetDir(LPC_GPIO_PORT, led1.gpio,led1.bit,OUTPUT_PORT);
	 Chip_GPIO_SetDir(LPC_GPIO_PORT, led2.gpio,led2.bit,OUTPUT_PORT);
	 Chip_GPIO_SetDir(LPC_GPIO_PORT, led3.gpio,led3.bit,OUTPUT_PORT);

	/* Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2));*/
	 Chip_GPIO_ClearValue(LPC_GPIO_PORT, led0R.gpio,led0R.bit);
	 Chip_GPIO_ClearValue(LPC_GPIO_PORT, led0G.gpio,led0G.bit);
	 Chip_GPIO_ClearValue(LPC_GPIO_PORT, led0B.gpio,led0B.bit);
	 Chip_GPIO_ClearValue(LPC_GPIO_PORT, led1.gpio,led1.bit);
	 Chip_GPIO_ClearValue(LPC_GPIO_PORT, led2.gpio,led2.bit);
	 Chip_GPIO_ClearValue(LPC_GPIO_PORT, led3.gpio,led3.bit);
};

void Led1_On(){
	//LedOn(led1);
	Chip_GPIO_SetValue(LPC_GPIO_PORT, led1.gpio, led1.bit);
};

void Led2_On(){
	Chip_GPIO_SetValue(LPC_GPIO_PORT, led2.gpio, led2.bit);
};

void Led3_On(){
	Chip_GPIO_SetValue(LPC_GPIO_PORT, led3.gpio, led3.bit);
};

void Led1_Off(){
	//LedOff(led1);
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, led1.gpio, led1.bit);
};

void Led2_Off(){
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, led2.gpio, led2.bit);
};

void Led3_Off(){
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, led3.gpio, led3.bit);
};

void Led1_Toggle(){
	Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 0,14);
};

void Led2_Toggle(){
	Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 1,11);
};

void Led3_Toggle(){
	Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 1,12);
};

void Led_R_On(){
	Chip_GPIO_SetValue(LPC_GPIO_PORT, led0R.gpio,led0R.bit);
};
void Led_G_On(){
	Chip_GPIO_SetValue(LPC_GPIO_PORT, led0G.gpio,led0G.bit);

};
void Led_B_On(){
	Chip_GPIO_SetValue(LPC_GPIO_PORT, led0B.gpio,led0B.bit);
};


void Led_R_Off(){
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, led0R.gpio,led0R.bit);
};
void Led_G_Off(){
	Chip_GPIO_ClearValue(LPC_GPIO_PORT,led0G.gpio,led0G.bit);
};
void Led_B_Off(){
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, led0B.gpio,led0B.bit);
};


void Led_R_Toggle(){
	Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 5,0);
};
void Led_G_Toggle(){
	Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 5,1);
};
void Led_B_Toggle(){
	Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 5,2);
};




void Led_Color(uint32_t R,uint32_t G,uint32_t B){
	uint32_t i=0;
	uint32_t max_Value=0;

	if(R==G&&G==B&&B==R)max_Value=R;
	if(R>G){
		if(R>B)max_Value=R;
		else max_Value=B;
	}
	else{


		if(G>B)max_Value=G;
		else max_Value=B;
	}



	for(i=0;i<max_Value;i++){
		if(R>i){
			Led_R_On();}
		else Led_R_Off();
		if(G>i){
			Led_G_On();}
		else Led_G_Off();
		if(B>i){
			Led_B_On();}
		else Led_B_Off();
	}

	Led_R_Off();
	Led_G_Off();
	Led_B_Off();
};
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */




/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

