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
uint32_t Contador=0;

static uint32_t ecg[250]={512,512,512,512,513,513,513,514,514,514,514,515,515,515,516,516,525,534,543,551,560,569,578,587,596,605,614,623,632,640,649,658,667,676,685,675,666,657,647,638,629,619,610,600,591,582,572,563,553,544,535,525,516,516,515,515,515,515,515,514,514,514,514,514,513,513,513,513,513,512,512,512,512,512,512,487,462,438,413,389,364,415,465,516,567,618,668,719,770,820,871,922,972,1023,945,866,788,709,631,553,474,396,318,239,161,82,154,225,297,368,440,512,512,512,512,512,512,513,513,513,513,513,514,514,514,514,514,515,515,515,515,515,516,516,516,516,516,517,517,517,517,517,517,518,518,518,518,518,519,519,519,519,519,520,520,520,520,525,529,534,538,543,548,552,557,561,566,571,575,580,584,589,593,598,603,598,594,590,585,581,577,572,568,564,559,555,551,546,542,538,533,529,525,520,519,518,518,517,516,515,514,513,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512
};



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
SetTimer(250);

Config_dac();
Init_conv_dac();


//if(Contador==249)Contador=0;

	while(1){

	}

}
/*
void RutinaTimer(){
	Led1_On();


};
*/

void RutinaTimer(){

	Push_value(ecg[Contador]);

	Contador=Contador+1;
	if(Contador==250)Contador=0;

};

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

