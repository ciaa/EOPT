/*
 * ciaaUART.h
 *
 *  Created on: Jun 12, 2014
 *      Author: pablo
 */

#ifndef CIAAUART_H_
#define CIAAUART_H_

#include "chip.h"
#include "string.h"

#define dbgPrint(x) uartSend((uint8_t *)(x), strlen(x))

#define UART_BUF_SIZE	1024

void ciaaUARTInit(void);
void uartSend(void * data, int datalen);

#endif /* CIAAUART_H_ */
