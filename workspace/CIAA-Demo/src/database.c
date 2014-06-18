/*
 * database.c
 *
 *  Created on: Mar 8, 2014
 *      Author: Pablo
 */

#include "database.h"
#include "stdio.h"
#include "string.h"
#include "debug_frmwrk.h"
#include "lpc43xx_uart.h"

registro_t registro[MAX_TARJETAS];
int registro_count=0;
char currentUID[10];


/* MSN -> o[0], LSN -> o[1] */
void byte2hex(uint8_t b, char * o)
{
	o[0] = b >> 4;
	if(o[0] >= 0x0A)
	{
		o[0] -= 0x0A;
		o[0] += 'A';
	}
	else
		o[0] += '0';

	o[1] = b & 0x0F;
	if(o[1] >= 0x0A)
	{
		o[1] -= 0x0A;
		o[1] += 'A';
	}
	else
		o[1] += '0';
}

uint8_t hex2byte(char * s)
{
	uint8_t r = 0;

	if(s[0] >= 'A')
		r = (s[0]-'A'+0x0A) << 4;
	else
		r = (s[0]-'0') << 4;

	if(s[1] >= 'A')
		r |= (s[1]-'A'+0x0A);
	else
		r |= (s[1]-'0');

	return r;
}

int dbNewUID(char * strUID)
{
	if(registro_count >= MAX_TARJETAS)
		return -1;

	strncpy(currentUID, strUID, 8);

	int i;
	uint8_t uid[4];
	for(i=0; i<4; i++)
		uid[i] = hex2byte(strUID+2*i);

	for(i=0; i<registro_count; i++)
	{
		if(!memcmp(uid, registro[i].uid, 4))
			return -2;
	}

	memcpy(registro[registro_count].uid, uid, 4);
	registro[registro_count].nombre[0] = 0;

	registro_count++;

//	char str[50];

//	sprintf(str, "UID(%u):%s\r\n",registro_count-1, strUID);
//	UARTPuts((LPC_USARTn_Type*)LPC_UART1, str);

	return 0;
}

int dbSetName(char * strUID, char * nombre)
{
	int i;
	uint8_t uid[4];

	for(i=0; i<4; i++)
		uid[i] = hex2byte(strUID+2*i);

	for(i=0; i<TAM_NOMBRE; i++)
	{
		if(nombre[i]==' ')
		{
			nombre[i]=0;
			break;
		}
		if(nombre[i]=='-')
			nombre[i] = ' ';
	}

	if(i==TAM_NOMBRE) nombre[TAM_NOMBRE-1]=0;

	for(i=0; i<MAX_TARJETAS; i++)
	{
		if(!memcmp(registro[i].uid, uid, 4))
		{
//			char str[50];
			strncpy(registro[i].nombre, nombre, TAM_NOMBRE);
//			sprintf(str, "Nombre(%u):%s\r\n",i, registro[i].nombre);
//			UARTPuts((LPC_USARTn_Type*)LPC_UART1, str);
			break;
		}
	}
	if(i==MAX_TARJETAS) return -1;

	return 0;
}

void dbGetList(char * list)
{
	char buf[2*TAM_UID + TAM_NOMBRE + 10];
	int i;

	list[0]=0;

	if(currentUID[0])
	{
		sprintf(buf, "x%s,;", currentUID);
		strcat(list, buf);
		currentUID[0]=0;
	}

	for(i=0; i<registro_count;i++)
	{
		sprintf(buf, "%02X%02X%02X%02X,%s;",
				registro[i].uid[0],
				registro[i].uid[1],
				registro[i].uid[2],
				registro[i].uid[3],
				registro[i].nombre);
		strcat(list, buf);
	}

}

