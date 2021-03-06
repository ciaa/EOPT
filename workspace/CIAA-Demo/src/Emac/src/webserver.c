/*
 * webserver.c
 *
 *  Created on: Mar 3, 2014
 *      Author: Pablo
 */

#include "webserver.h"

#include "lpc43xx_gpio.h"
#include "lpc43xx_scu.h"
#include "lpc43xx_cgu.h"
#include "lpc43xx_i2c.h"

#include "emac.h"         // Keil: *.c -> *.h    // ethernet packet driver
#define extern            // Keil: Line added for modular project management
#include "easyweb.h"
#include "tcpip.h"        // Keil: *.c -> *.h    // easyWEB TCP/IP stack
#include "webpage.h"                             // webside for our HTTP server (HTML)
#include "string.h"
#include "stdio.h"

#include "debug_frmwrk.h"

#include "database.h"

#include "ciaaUART.h"

unsigned int res = 0;
unsigned int pagecounter = 100;
unsigned int adcValue    =   0;
unsigned int led_d2=0;
unsigned int led_d1=0;

void init_memory(void) {
   int i;
   char * pMem = (char *)0x20008000;

   for (i=0;i<10000;i++) {
	  (*pMem++) = 0x00;

   }
}

void enetInit(void)
{
	CGU_EnableEntity(CGU_CLKSRC_32KHZ_OSC, ENABLE);			// Enable 32 kHz & 1 kHz on osc32k

//	scu_pinmux(0x2 ,11 , MD_PUP, FUNC0); 	// P2.11 : GPIO1_11: Xplorer BOARD (LED3)
//	GPIO_SetDir(LED1_PORT,(1<<LED1_BIT), 1);
//	GPIO_ClearValue(LED1_PORT,(1<<LED1_BIT));
//	scu_pinmux(0x2 ,12 , MD_PUP, FUNC0); 	// P2.12 : GPIO1_12: Xplorer BOARD (LED4)
//	GPIO_SetDir(LED2_PORT,(1<<LED2_BIT), 1);
//	GPIO_ClearValue(LED2_PORT,(1<<LED2_BIT));

	CGU_EnableEntity(CGU_CLKSRC_ENET_RX_CLK, ENABLE);
	CGU_EnableEntity(CGU_CLKSRC_ENET_TX_CLK, ENABLE);

	CGU_SetDIV(CGU_CLKSRC_IDIVA, 1);
	CGU_EntityConnect(CGU_CLKSRC_ENET_TX_CLK, CGU_CLKSRC_IDIVA);
	CGU_EntityConnect(CGU_CLKSRC_IDIVA, CGU_BASE_PHY_TX);
	CGU_EntityConnect(CGU_CLKSRC_IDIVA, CGU_BASE_PHY_RX);

	TCPLowLevelInit();

	HTTPStatus = 0;

	TCPLocalPort = TCP_PORT_HTTP;                  // set port we want to listen to
}


void webPeriodicalTask(void)
{
    if (!(SocketStatus & SOCK_ACTIVE)) TCPPassiveOpen();   // listen for incoming TCP-connection

    if(SocketStatus & SOCK_ERROR_MASK)
    {
    	TCPClose();
    	TCPLowLevelInit();
    }

    DoNetworkStuff();                                      // handle network and easyWEB-stack events
    HTTPServer();
}

// This function implements a very simple dynamic HTTP-server.
// It waits until connected, then sends a HTTP-header and the
// HTML-code stored in memory. Before sending, it replaces
// some special strings with dynamic values.
// NOTE: For strings crossing page boundaries, replacing will
// not work. In this case, simply add some extra lines
// (e.g. CR and LFs) to the HTML-code.

void HTTPServer(void)
{
	static char sendPage = 0;

	if (SocketStatus & SOCK_CONNECTED)             // check if somebody has connected to our TCP
	{
		if (SocketStatus & SOCK_DATA_AVAILABLE)      // check if remote TCP sent data
		{
			dbgPrint("[HTTPServerTask]Data received: ");
			dbgPrint((char*)TCP_RX_BUF);

			TCPReleaseRxBuffer();

			if(SocketStatus & SOCK_TX_BUF_RELEASED)
			{
				if(strstr((char *)TCP_RX_BUF, "getList"))
				{
					char lista[512];

					dbGetList(lista);

					if(strlen(lista)==0)
						strcpy(lista, ",;");

					PWebSide = (unsigned char *)lista;//"01AB02CD,Paco Rodriguez;01AB02CE,Juan pepito;01AB02CF,;01AB02D0,toto;";
					HTTPBytesToSend = strlen((char *)PWebSide)+1;
					memcpy(TCP_TX_BUF, PWebSide, HTTPBytesToSend);
					TCPTxDataCount = HTTPBytesToSend-1;
					TCPTransmitTxBuffer();
					TCPClose();
					HTTPBytesToSend = 0;

					dbgPrint("[HTTPServerTask]Data sent: ");
					dbgPrint((char*)TCP_TX_BUF);
					dbgPrint("\n");

					return;
				}
				else if(strstr((char *)TCP_RX_BUF, "setName"))
				{
					/* GET /192.168.0.123/setName?uid=01234567&name=aaasdasdasd HTTP/1.1 ... */
					char * p = strstr((char *)TCP_RX_BUF, "uid=");
					p+=4;
					char * q = strstr((char *)TCP_RX_BUF, "name=");
					q+=5;

					dbSetName(p, q);

					PWebSide = (unsigned char *)"OK";
					HTTPBytesToSend = strlen((char *)PWebSide)+1;
					memcpy(TCP_TX_BUF, PWebSide, HTTPBytesToSend);
					TCPTxDataCount = HTTPBytesToSend-1;
					TCPTransmitTxBuffer();
					TCPClose();
					HTTPBytesToSend = 0;

					dbgPrint("[HTTPServerTask]Data sent: ");
					dbgPrint((char*)TCP_TX_BUF);
					dbgPrint("\n");

					return;
				}
				else if(strstr((char*)TCP_RX_BUF, "getCurrent"))
				{

				}
				else //if(strstr((char *)TCP_RX_BUF, "GET / "))
					sendPage = 1;
			}
		}

		if(sendPage && (SocketStatus & SOCK_TX_BUF_RELEASED))
		{
			if (!(HTTPStatus & HTTP_SEND_PAGE))        // init byte-counter and pointer to webside
			{                                          // if called the 1st time
				HTTPBytesToSend = sizeof(WebSide) - 1;   // get HTML length, ignore trailing zero
				PWebSide = (unsigned char *)WebSide;     // pointer to HTML-code
			}

			if (HTTPBytesToSend > MAX_TCP_TX_DATA_SIZE)     // transmit a segment of MAX_SIZE
			{
				if (!(HTTPStatus & HTTP_SEND_PAGE))           // 1st time, include HTTP-header
				{
					memcpy(TCP_TX_BUF, GetResponse, sizeof(GetResponse) - 1);
					memcpy(TCP_TX_BUF + sizeof(GetResponse) - 1, PWebSide, MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse) + 1);
					HTTPBytesToSend -= MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse) + 1;
					PWebSide += MAX_TCP_TX_DATA_SIZE - sizeof(GetResponse) + 1;
				}
				else
				{
					memcpy(TCP_TX_BUF, PWebSide, MAX_TCP_TX_DATA_SIZE);
					HTTPBytesToSend -= MAX_TCP_TX_DATA_SIZE;
					PWebSide += MAX_TCP_TX_DATA_SIZE;
				}

				TCPTxDataCount = MAX_TCP_TX_DATA_SIZE;   // bytes to xfer
				TCPTransmitTxBuffer();                   // xfer buffer
			}
			else if (HTTPBytesToSend)                  // transmit leftover bytes
			{
				memcpy(TCP_TX_BUF, PWebSide, HTTPBytesToSend);
				TCPTxDataCount = HTTPBytesToSend;        // bytes to xfer
				TCPTransmitTxBuffer();                   // send last segment
				TCPClose();                              // and close connection
				HTTPBytesToSend = 0;                     // all data sent
				sendPage = 0;
			}
			HTTPStatus |= HTTP_SEND_PAGE;              // ok, 1st loop executed

			dbgPrint("[HTTPServerTask]Data sent: ");
			dbgPrint((char*)TCP_TX_BUF);
			dbgPrint("\n");

		}
	}
	else
		HTTPStatus &= ~HTTP_SEND_PAGE;               // reset help-flag if not connected
}
