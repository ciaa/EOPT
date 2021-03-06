/*
 * ciaaNVM.h
 *
 *  Created on: Jun 27, 2014
 *      Author: pablo
 */

#ifndef CIAANVM_H_
#define CIAANVM_H_

#include "chip.h"
#include "ciaaI2C.h"

void mem48Read(uint8_t addr, void * buffer, int len);
void mem48Write(uint8_t addr, void * buffer, int len);
void memRead(uint16_t addr, void * buffer, int len);
void memWrite(uint16_t addr, void * buffer, int len);
void ciaaNVMInit(void);

#endif /* CIAANVM_H_ */
