/*
 * ciaaUART.c
 *
 *  Created on: Jun 12, 2014
 *      Author: pablo
 */

#include "ciaaUART.h"

uint8_t uartRxBuf[UART_BUF_SIZE];
uint8_t uartTxBuf[UART_BUF_SIZE];
uint8_t * pTxIn = uartTxBuf;
uint8_t * pTxOut = uartTxBuf;
uint32_t uartRxDataCount = 0;

void ciaaUARTInit(void)
{
	/* UART2 (USB-UART) */
	Chip_UART_Init(LPC_USART2);
	Chip_UART_SetBaud(LPC_USART2, 115200);

	Chip_UART_TXEnable(LPC_USART2);

	Chip_SCU_PinMux(7, 1, MD_PDN, FUNC6); 					// P7_1: UART2_TXD
	Chip_SCU_PinMux(7, 2, MD_PLN|MD_EZI|MD_ZI, FUNC6); 		// P7_2: UART2_RXD

	Chip_UART_IntEnable(LPC_USART2, UART_IER_RBRINT);

	NVIC_EnableIRQ(USART2_IRQn);

	/* UART3 (RS232) */
//	cfg.Baud_rate = 57600;
//	UART_Init(LPC_USART3, &cfg);
//	UART_TxCmd(LPC_USART3, ENABLE);
//
//	scu_pinmux(2, 3, MD_PDN, FUNC2); 					// P2_3: UART3_TXD
//	scu_pinmux(2, 4, MD_PLN|MD_EZI|MD_ZI, FUNC2); 		// P2_4: UART3_RXD
//
//	UART_IntConfig((LPC_USARTn_Type *)LPC_USART3, UART_INTCFG_RBR, ENABLE);
//	NVIC_EnableIRQ(USART3_IRQn);

}

void UART2_IRQHandler(void)
{
	uint8_t status = Chip_UART_ReadLineStatus(LPC_USART2);

	if(status & UART_LSR_RDR)
	{
		uartRxBuf[uartRxDataCount] = Chip_UART_ReadByte(LPC_USART2);
		uartRxDataCount++;
	}
	if(status & UART_LSR_THRE)
	{
		pTxOut++;
		if(pTxOut == (uartTxBuf + UART_BUF_SIZE))
			pTxOut = uartTxBuf;
		if(pTxIn == pTxOut)
		{
			Chip_UART_IntDisable(LPC_USART2, UART_IER_THREINT);
			return;
		}
		Chip_UART_SendByte(LPC_USART2, *pTxOut);
	}
}

void UART3_IRQHandler(void)
{

}

void uartSend(void * data, int datalen)
{
	int i;

	if(datalen==0) return;

	for(i=0; i<datalen; i++)
	{
		*pTxIn = ((uint8_t*)data)[i];

		if(pTxIn == pTxOut)
		{
			Chip_UART_SendByte(LPC_USART2, *pTxOut);
			Chip_UART_IntEnable(LPC_USART2, UART_IER_THREINT);
		}

		pTxIn++;
		if(pTxIn == (uartTxBuf + UART_BUF_SIZE))
			pTxIn = uartTxBuf;
	}
}
