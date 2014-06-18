/*
===============================================================================
 Name        : main.c
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

#ifdef __USE_CMSIS
#include "LPC43xx.h"
#endif

#include "lpc43xx_gpio.h"
#include "lpc43xx_rit.h"
#include "lpc43xx_scu.h"

volatile uint32_t msec;

// Use Timer0 as CM0 in LPC43xx does not implement the Systick peripheral!
void M0_RIT_OR_WWDT_IRQHandler(void)
{
	if(RIT_GetIntStatus(LPC_RITIMER) == SET)
	{
		if(msec)msec--;
		NVIC_ClearPendingIRQ(M0_RITIMER_OR_WWDT_IRQn);
	}
}

#define LED_GPIO_PORT_USED		(1)
#define RED_GPIO_PIN_BIT		(8)

int main(void)
{
	scu_pinmux(1,5,MD_PUP,FUNC0);//GPIO1[8]

	GPIO_SetDir(LED_GPIO_PORT_USED, (1 << RED_GPIO_PIN_BIT), 1);

	GPIO_SetValue(LED_GPIO_PORT_USED,(1<<RED_GPIO_PIN_BIT));

	NVIC_EnableIRQ(M0_RITIMER_OR_WWDT_IRQn);

	while(1)
	{
		msec = 200;
		while(msec);

		LPC_GPIO_PORT->NOT[LED_GPIO_PORT_USED] = 1<<RED_GPIO_PIN_BIT;

	}
	return 0 ;
}

void check_failed(uint8_t *file, uint32_t line)
{
	while(1);
}
