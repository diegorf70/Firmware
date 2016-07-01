/* Copyright 2016, Ferreyra Diego
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

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
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
#include "EJ_FINAL.h"       /* <= own header */


/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

void AumentaGanancia();
void DisminuyeGanancia();
void Mute();

void Send_Word(uint8_t* Palabra);
void Delay(uint32_t Time);
/*==================[internal data definition]===============================*/
uint32_t Contador=0;

uint16_t data=0;

uint16_t gain=1;

uint8_t flag=0;



/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
void AumentaGanancia(){

	if(gain<=5){
		gain=gain+1;

	}

	Config_SCU();


	uint8_t msj[]={"Aument Ganancia"};
					Send_Word( msj);
}
void DisminuyeGanancia(){

	if(gain>=0){
			gain=gain-1;

		}


	Config_SCU();

		uint8_t msj[]={"Dismin Ganancia"};
				Send_Word( msj);
}
void Mute(){

	gain=0;

	Config_SCU();

		uint8_t msj[]={"MUTE"};
		Send_Word( msj);


}

void Send_Word(uint8_t* Palabra){
	uint16_t i=0;

	while(Palabra[i]!='\0'){
		EnviarByte(Palabra[i]);
		i=i+1;
	}

	EnviarByte('\n');


}
void Delay(uint32_t Time){

	uint32_t contador=Time;

	while(contador!=0){

		contador=contador-1;

	}
};

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */



int main(void)
{
   /* perform the needed initialization here */



	IniciarTimer();
	SetTimer(100);
	Init_Ports_Leds();
	Init_Ports_Tec();

	Config_dac();
	Init_conv_dac();







	Led1_Off();
	Led2_Off();
	Led3_Off();

	Led_R_Off();
	Led_G_Off();
	Led_B_Off();

	while(1){



	}




}
/*
void RutinaTimer(){
	Led1_On();


};
*/

void RutinaTimer(){

Led1_Toggle();

ADC_Init();
data=ADC_Leer();



if(!flag){
	Push_value(data*gain);
	Led3_Off();

}
else{


	if((data*gain)>512)Push_value(1000);
		if((data*gain)<512)Push_value(0);
}

if(Leer_TEC1()==1){

	AumentaGanancia();
}

if(Leer_TEC2()==1){

	DisminuyeGanancia();
}

if(Leer_TEC3()==1){

	Mute();
}

if(Leer_TEC4()==1){

	flag= !flag;
	Led3_On();
}


BorrarTimer();


};

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

