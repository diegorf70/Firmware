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
#include "Ctrl_Leds_5.h"       /* <= own header */


/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
void Delay(uint32_t Time);
void Fiesta();

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
void Delay(uint32_t Time){
	uint32_t contador=Time;
	while(contador!=0){
					contador=contador-1;

				}
};

void Fiesta(){
			Led1_Off();
			Led2_Off();
			Led3_Off();
			Led_R_Off();
			Led_G_Off();
			Led_B_Off();

			Delay(2000000);

			Led1_On();
			Led2_On();
			Led3_On();
			Led_R_On();
			Led_G_On();
			Led_B_On();

			Delay(2000000);

			Led1_Off();
			Led2_Off();
			Led3_Off();
			Led_R_Off();
			Led_G_Off();
			Led_B_Off();
};
/*==================[internal functions definition]==========================*/

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
Init_Ports();
Init_Ports_Tec();



uint32_t contador_init=100;
	uint32_t contador=contador_init;
	uint32_t Times=1000000;

	//Led2_Off();
	//Led3_Off();

	while(1){

		/*Led1_Off();
		Led2_Off();
		Led3_Off();
		Led_R_Off();
		Led_G_Off();
		Led_B_Off();*/
		/*-----------------Tecla 1--->LED RGB-------------------*/
		Led_R_On();
		Led_G_On();
		Led_B_On();
		Delay(Times);
		if(Leer_TEC1()==1){
			Delay(contador_init);
			if(Leer_TEC1()==1){
				Led_R_On();
				Led_G_On();
			    Led_B_On();

			    while(1){
			    	Led_R_Off();
			    	Led_G_Off();
			    	Led_B_Off();
			    	Fiesta();
			    	Led_R_On();
			    	Led_G_On();
			    	Led_B_On();
			    	Delay(10000000);
			    }
			}
			contador=contador_init;
			Delay(contador_init);

		}
				Led_R_Off();
				Led_G_Off();
				Led_B_Off();
				Delay(Times);
		/*-----------------Tecla 2--->LED1-------------------*/
				Led1_On();
				Delay(Times);

				if(Leer_TEC2()==1){
			Delay(contador_init);
				if(Leer_TEC2()==1){
					Led1_On();
					while(1){
						Led1_Off();
						Fiesta();
						Led1_On();
						Delay(10000000);
					};
				}
				contador=contador_init;
				Delay(contador_init);
			}
				Led1_Off();
				Delay(Times);
		/*-----------------Tecla 3--->LED2-------------------*/
				Led2_On();
				Delay(Times);
		if(Leer_TEC3()==1){
			Delay(contador_init);
				if(Leer_TEC3()==1){
					Led2_On();
					while(1){
						Led2_Off();
						Fiesta();
						Led2_On();
						Delay(10000000);
					};
				}
				contador=contador_init;
				Delay(contador_init);
			}
		Led2_Off();
		Delay(Times);
		/*-----------------Tecla 4--->LED3-------------------*/
		Led3_On();
		Delay(Times);
		if(Leer_TEC4()==1){
			Delay(contador_init);
				if(Leer_TEC4()==1){
					Led3_On();
					while(1){
						Led3_Off();
						Fiesta();
						Led3_On();
						Delay(10000000);
					};
				}
				contador=contador_init;
				Delay(contador_init);
			}
		Led3_Off();
				Delay(Times);
		//Led2_On();


		contador=contador_init;




	}

}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

