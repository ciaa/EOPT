/*
===============================================================================
 Name        : ciaaTest.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "chip.h"
#include "ciaa.h"

//#define SEMIHOST

#include "stdio.h"

#include "stdlib.h"

#include <cr_section_macros.h>

volatile int pausemscont;

void SysTick_Handler(void)
{
	if(pausemscont) pausemscont--;
}

void pausems(int t)
{
	pausemscont = t;
	while(pausemscont) __WFI();
}

int main(void)
{
	char str[100], i;

	/* Ojo que #define MAX_CLOCK_FREQ (102000000)!!!
	 * Termina dando 96MHz. Originalmente estaba en 204000000.
	 * Ver lpc_chip_43xx/inc/clock_18xx_43xx.h
	 */
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);

	ciaaIOInit();
	ciaaAINInit();
	ciaaAOUTInit();
	ciaaUARTInit();
	ciaaNVMInit();


	/* DAC test */
	ciaaAOUTSet(0);

	ciaaAOUTSet(25);

	ciaaAOUTSet(50);

	ciaaAOUTSet(75);

	ciaaAOUTSet(100);



	dbgPrint("CIAA Test (with LPCOpen libraries).\r\n");

	dbgPrint("Non-Volatile Memories test... ");

	char txbuf[3] = {0x55,0xF0,0xAA};
	char rxbuf[3] = {0,0,0};
	char rxbuf48[3] = {0,0,0};

	memWrite(0, txbuf, 3);

	memRead(0, rxbuf, 3);

	mem48Write(0, txbuf, 3);
	mem48Read(0, rxbuf48, 3);

	uint8_t uid48[6] = {0,0,0,0,0,0};

	mem48Read(0xFA, uid48, 6);

	if((rxbuf[0]==0x55)&&(rxbuf[1]==0xF0)&&(rxbuf[2]==0xAA)&&
		(rxbuf48[0]==0x55)&&(rxbuf48[1]==0xF0)&&(rxbuf48[2]==0xAA)	)
	{
		sprintf(str, "OK. EUI-48: %02X-%02X-%02X-%02X-%02X-%02X\r\n",
				uid48[0], uid48[1], uid48[2], uid48[3],
				uid48[4], uid48[5]);
		dbgPrint(str);
	}
	else
		dbgPrint("ERROR\r\n");

	while(1)
	{
		sprintf(str, "AIN: %d %d %d %d\r\n",
				ciaaAINRead(0), ciaaAINRead(1),
				ciaaAINRead(2), ciaaAINRead(3));
		dbgPrint(str);
		sprintf(str, "DIN: 0x%02X\r\n", ciaaDigitalInputs());
		dbgPrint(str);
    	for(i=4; i<8; i++)
    	{
			ciaaWriteOutput(i, 1);
			pausems(200);
			ciaaWriteOutput(i, 0);
    	}
	}

}
