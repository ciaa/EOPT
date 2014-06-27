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
#include "ciaaIO.h"
#include "ciaaAIN.h"
#include "ciaaUART.h"
#include "ciaaNVM.h"

#include "stdio.h"

#include <cr_section_macros.h>

volatile int pausemscont;

void SysTick_Handler(void)
{
	if(pausemscont) pausemscont--;

	volatile static int cont=0;

	cont++;

	if(cont==250)
	{
		ciaaWriteOutput(5, 1);
	}
	if(cont==500)
	{
		ciaaWriteOutput(5, 0);
		cont = 0;
	}
}

void pausems(int t)
{
	pausemscont = t;
	while(pausemscont) __WFI();
}

int main(void)
{
	char str[100];

	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);

	ciaaIOInit();
	ciaaAINInit();
	ciaaUARTInit();
	ciaaNVMInit();

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
		dbgPrint("OK\r\n");
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
		pausems(1000);
	}

}