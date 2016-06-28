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
#include "Main_4.h"       /* <= own header */


/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
void Delay(uint32_t Time);
/*==================[internal data definition]===============================*/

uint32_t red=0;
uint32_t green=0;
uint32_t blue=0;


/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
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
//IniciarTimer();
IniciarTimer();
SetTimer(10);
Init_Ports_Leds();
Init_Ports_Tec();

    uint32_t contador_init=100000;
	uint32_t contador=contador_init;


	//Led2_Off();
	//Led3_Off();
	Led_R_On();
	while(1){


		//BorrarTimer();

		/*Led2_Off();

		Led1_Off();*/


		uint32_t velocidad=2;

		while(velocidad!=1){
			/*Delay(10000000);
			Led2_Off();

			Led1_Off();*/
			if(Leer_TEC1()==1){

				Delay(contador);

				if(Leer_TEC1()==1){

					red=red+10;
					if(red>10000)red=0;
				}


			}

			if(Leer_TEC2()==1){

							Delay(contador);

							if(Leer_TEC2()==1){

								green=green+10;
								if(red>10000)green=0;
							}


						}

			if(Leer_TEC3()==1){

							Delay(contador);

							if(Leer_TEC3()==1){

								blue=blue+10;
								if(blue>10000)blue=0;
							}


						}

			if(Leer_TEC4()==1){

										Delay(contador);

										if(Leer_TEC4()==1){

											red=green=blue=0;
										}


									}

			contador=contador_init;

		}
		//Led1_Off();



	}

}
/*
void RutinaTimer(){
	Led1_On();


};
*/

void RutinaTimer(){

	Led_Color(red,green,blue);


	BorrarTimer();


};

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

