/*
 * UART.c
 *
 *  Created on: 27/6/2016
 *      Author: diego
 */

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

#include "UART.h"


void Config_SCU(){

	Chip_SCU_PinMux(7, 1, MD_PDN, FUNC6);              /* P7_1: UART2_TXD */
	Chip_SCU_PinMux(7, 2, MD_EZI, FUNC6);/* P7_2: UART2_RXD */
	Chip_UART_Init(LPC_USART2);
	Chip_UART_SetBaud(LPC_USART2, 115200);

	Chip_UART_SetupFIFOS(LPC_USART2, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);

	Chip_UART_TXEnable(LPC_USART2);

	/*Chip_SCU_PinMux(1, 15, MD_PDN, FUNC1);              /* P7_1: UART2_TXD */
	/*Chip_SCU_PinMux(1, 16, MD_PLN|MD_EZI|MD_ZI, FUNC1); /* P7_2: UART2_RXD */
}

void EnviarByte(uint8_t data){
	Chip_UART_SendByte(LPC_USART2,data);
}
uint8_t LeerByte(){
	return (uint8_t) Chip_UART_ReadByte(LPC_USART2);
}
