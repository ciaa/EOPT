/*
 * ciaaAIN.c
 *
 *  Created on: Jun 24, 2014
 *      Author: pablo
 */

#include "ciaaAIN.h"

uint16_t current_in[4];

void ADC0_IRQHandler(void)
{
	if(ADC_ChannelGetStatus(LPC_ADC0, ADC_CHANNEL_1, 1)==SET)
	{
		current_in[0] = ADC_DR_RESULT(ADC_GlobalGetData(LPC_ADC0));
	}
	if(ADC_ChannelGetStatus(LPC_ADC0, ADC_CHANNEL_2, 1)==SET)
	{
		current_in[1] = ADC_DR_RESULT(ADC_GlobalGetData(LPC_ADC0));
	}
	if(ADC_ChannelGetStatus(LPC_ADC0, ADC_CHANNEL_3, 1)==SET)
	{
		current_in[2] = ADC_DR_RESULT(ADC_GlobalGetData(LPC_ADC0));
	}
	if(ADC_ChannelGetStatus(LPC_ADC0, ADC_CHANNEL_4, 1)==SET)
	{
		current_in[3] = ADC_DR_RESULT(ADC_GlobalGetData(LPC_ADC0));
	}
}

void ciaaAINInit(void)
{
	ADC_Init(LPC_ADC0, 200000, 10);

	ADC_ChannelCmd(LPC_ADC0, ADC_CHANNEL_1, ENABLE);
	ADC_ChannelCmd(LPC_ADC0, ADC_CHANNEL_2, ENABLE);
	ADC_ChannelCmd(LPC_ADC0, ADC_CHANNEL_3, ENABLE);
	ADC_ChannelCmd(LPC_ADC0, ADC_CHANNEL_4, ENABLE);

	ADC_IntConfig(LPC_ADC0, ADC_ADINTEN1, ENABLE);
	ADC_IntConfig(LPC_ADC0, ADC_ADINTEN2, ENABLE);
	ADC_IntConfig(LPC_ADC0, ADC_ADINTEN3, ENABLE);
	ADC_IntConfig(LPC_ADC0, ADC_ADINTEN4, ENABLE);

	ADC_BurstCmd(LPC_ADC0, ENABLE);

	NVIC_EnableIRQ(ADC0_IRQn);
}

uint16_t ciaaAINRead(uint8_t input)
{
	if(input > 3) return -1;
	return current_in[input];
}
