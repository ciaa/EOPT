/*
===============================================================================
 Name        : ciaaBlink.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC43xx.h"
#endif

#include <cr_section_macros.h>

#include "lpc43xx_cgu.h"
#include "ciaaIO.h"

volatile int contms;

void SysTick_Handler(void)
{
	if(contms) contms--;
}

void pausems(int t)
{
	contms = t;
	while(contms) __WFI();
}

int main(void)
{
	int i;
    SysTick_Config(CGU_GetPCLKFrequency(CGU_PERIPHERAL_M4CORE)/1000);
    ciaaIOInit();

    while(1)
    {
    	for(i=4; i<8; i++)
    	{
			ciaaWriteOutput(i, 1);
			pausems(100);
			ciaaWriteOutput(i, 0);
    	}
    }
}
