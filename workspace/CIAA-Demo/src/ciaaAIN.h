/*
 * ciaaAIN.h
 *
 *  Created on: Jun 24, 2014
 *      Author: pablo
 */

#ifndef CIAAAIN_H_
#define CIAAAIN_H_

#include "lpc43xx_adc.h"

void ciaaAINInit(void);
uint16_t ciaaAINRead(uint8_t input);

#endif /* CIAAAIN_H_ */
