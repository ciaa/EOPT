/*
 * ciaaUART.h
 *
 *  Created on: Jun 12, 2014
 *      Author: pablo
 */

#ifndef CIAAUART_H_
#define CIAAUART_H_

#include "lpc43xx_gpio.h"
#include "lpc43xx_scu.h"
#include "lpc43xx_uart.h"
#include "debug_frmwrk.h"
#include "string.h"

#define dbgPrint(x) uartSend((uint8_t *)(x), strlen(x))

#define UART_BUF_SIZE	1024

void ciaaUARTInit(void);
void uartSend(void * data, int datalen);
void ciaaUART485Send(void * data, int datalen);
void ciaaUART485Recv(void * data, int datalen);

#endif /* CIAAUART_H_ */
