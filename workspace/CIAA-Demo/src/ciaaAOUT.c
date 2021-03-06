/*
 * ciaaAOUT.c
 *
 *  Created on: Jun 23, 2014
 *      Author: pablo
 */

#include "ciaaAOUT.h"


void ciaaAOUTInit(void)
{

	DAC_Init(LPC_DAC);

	DAC_CONVERTER_CFG_Type cfg;

	cfg.DMA_ENA = 1;
	cfg.CNT_ENA = 0;
	cfg.DBLBUF_ENA = 0;

	DAC_ConfigDAConverterControl(LPC_DAC, &cfg);

	DAC_UpdateValue(LPC_DAC, 0);


}

/* [in] level: Output level (0 - 100%) */
void ciaaAOUTSet(uint8_t level)
{
	if(level > 100) level = 100;

	DAC_UpdateValue(LPC_DAC, (level * 0x3FF) / 100);
}
