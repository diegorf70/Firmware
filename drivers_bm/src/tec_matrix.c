/*==================[inclusions]=============================================*/





#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

#include "tec_matrix.h"

/*==================[macros and definitions]=================================*/
/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void Init_Tec_Mat(){

	  Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[4], SW1 */
		   Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[8], SW2 */
		   Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[9], SW3 */
		   Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO1[9], SW4 */

		   Chip_GPIO_SetDir(LPC_GPIO_PORT, 0,(1<<4)|(1<<8)|(1<<9),0);
		   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1,(1<<9),0);

};
uint16_t Leer_Tec_Mat(){

};
