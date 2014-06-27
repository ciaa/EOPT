/*
 * ciaaNVM.c
 *
 *  Created on: Jun 27, 2014
 *      Author: pablo
 */

#include "ciaaNVM.h"

void ciaaNVMInit(void)
{
	ciaaI2CInit();
}

void mem48Read(uint8_t addr, void * buffer, int len)
{
	int i;

	/* Primero escribo dirección: 1 byte */
	ciaaI2CWrite(0x51, &addr, 1);

	//tiempo de establecimiento de la memoria
	//for(i=0; i<0xFFFF; i++);

	/* Leo byte (lectura propiamente dicha) */
	ciaaI2CRead(0x51, buffer, len);

	//tiempo de establecimiento de la memoria
	for(i=0; i<0xFFFF; i++);
}

void mem48Write(uint8_t addr, void * buffer, int len)
{
	uint8_t * pdatos = (uint8_t *)buffer;
	uint8_t buf[34];
	int i;

	while(len>0)
	{
		buf[0] = addr;

		for(i=0; i < ( len > 32 ? 32 : len ); i++)
			buf[i+1] = pdatos[i];

		ciaaI2CWrite(0x51, buf, len > 32 ? 34 : len+2);
		//tiempo de establecimiento de la memoria
		for(i=0; i<0xFFFF; i++);

		addr += 32;
		len -= 32;
		pdatos+=32;
	}
}

void memRead(uint16_t addr, void * buffer, int len)
{
	unsigned char txbuf[2];
	int i;

	txbuf[0] = addr >> 8;
	txbuf[1] = addr & 0xFF;

	/* Primero escribo dirección: 2 bytes */
	ciaaI2CWrite(0x50, txbuf, 2);

	//tiempo de establecimiento de la memoria
	//for(i=0; i<0xFFFF; i++);

	/* Leo byte (lectura propiamente dicha) */
	ciaaI2CRead(0x50, buffer, len);

	//tiempo de establecimiento de la memoria
	for(i=0; i<0xFFFF; i++);
}

void memWrite(uint16_t addr, void * buffer, int len)
{
	uint8_t * pdatos = (uint8_t *)buffer;
	uint8_t buf[34];
	int i;

	while(len>0)
	{
		buf[0] = addr >> 8;
		buf[1] = addr & 0xFF;

		for(i=0; i < ( len > 32 ? 32 : len ); i++)
			buf[i+2] = pdatos[i];

		ciaaI2CWrite(0x50, buf, len > 32 ? 34 : len+2);
		//tiempo de establecimiento de la memoria
		for(i=0; i<0xFFFF; i++);

		addr += 32;
		len -= 32;
		pdatos+=32;
	}
}
