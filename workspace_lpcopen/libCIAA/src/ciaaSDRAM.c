/*
 * ciaaSDRAM.c
 *
 *  Created on: Jul 2, 2014
 *      Author: pablo
 */

#include "ciaaSDRAM.h"

void ciaaSDRAMInit(void)
{
	/* FIXME!!! */
	  //Memory documentation: http://www.issi.com/pdf/42-45S16400F.pdf

//	  LPC_RGU->RESET_CTRL0 = (1UL << 21);                             //Reset EMC
//
//	  while(LPC_RGU->RESET_ACTIVE_STATUS0 &  (1UL << 21) == 0);       //Wait for the reset
//	  waitUS(200);                                                    //wait for good measure
//
//	  //EMS Config
//	  LPC_EMC->CONTROL = 1;                                           //Enable EMC // normal memory map
//	  LPC_EMC->CONFIG = 0;                                            // Little endian clock is 1:1
//
//	  //Configuration common to all dynamic memories
//	  LPC_EMC->DYNAMICREFRESH       = N_TO_EMC_CLOCKS(15625UL)>>4;   // Multiples of 16 CLK (1=16)
//	  LPC_EMC->DYNAMICREADCONFIG    = 3UL;                           // Do not leave at 0
//	  LPC_EMC->DYNAMICRP            = N_TO_EMC_CLOCKS(18UL) - 1;     // tRP- (n+1 (my data sheet has tRP but no tPR
//	  LPC_EMC->DYNAMICRAS           = N_TO_EMC_CLOCKS(42UL) - 1;     // tRAS - (n+1) (Data sheet says 42-1000)
//	  LPC_EMC->DYNAMICSREX          = N_TO_EMC_CLOCKS(60UL) - 1;     // tSREX,tXSR- (n+1) (trc page 6
//	  LPC_EMC->DYNAMICAPR           = 1-1;                           // tAPR - n+1  (Not found in data sheet) used timing diagram
//	  LPC_EMC->DYNAMICDAL           = N_TO_EMC_CLOCKS(18UL) +2;      // tDAL,tAPW - 2 clk + trp (18ns)
//	  LPC_EMC->DYNAMICWR            = 2UL -1;                        // tWRt,tDPL,tRWL,,tRDL - (n+1)
//	  LPC_EMC->DYNAMICRC            = N_TO_EMC_CLOCKS(60UL) - 1;     // tRC - (n+1)
//	  LPC_EMC->DYNAMICRFC           = N_TO_EMC_CLOCKS(60UL) - 1;     // tRFC,tRC - (n+1)  TODO: couldn't find value, used tRC per tmming diagram
//	  LPC_EMC->DYNAMICXSR           = N_TO_EMC_CLOCKS(66UL) - 1;     // tXSR - (n+1)
//	  LPC_EMC->DYNAMICRRD           = N_TO_EMC_CLOCKS(12UL) - 1;     // tRRD - (n+1)
//	  LPC_EMC->DYNAMICMRD           = 2UL -1;                        // tMRD,tRSA - (n+1)
//
//	  //Configuration specific to each memory by chip select
//	  //Address mapping for our part (16 bit interface)
//	  // 14 12  11:9  8:7
//	  // 0  0   001   01   64 Mb (4Mx16), 4 banks, row length = 12, column length = 8  enhanced (RBC)
//	  // 0  1   001   01   64 Mb (4Mx16), 4 banks, row length = 12, column length = 8  normal   (BRC)
//
//	  LPC_EMC->DYNAMICCONFIG0 = (1UL << 7) | (1UL << 9);              // | (1UL << 12);
//
//	  LPC_EMC->DYNAMICRASCAS0 = (3UL) | (3UL << 8);                   //RAS CAS latency
//
//
//	  //Initialization of the SDRAM
//	  LPC_EMC->DYNAMICCONTROL = (1UL << 0) | (1UL << 1) | (3 << 7);   //CS=1 CE=1 OP=NOP
//	  waitUS(100);
//
//	  LPC_EMC->DYNAMICCONTROL = (1UL << 0) | (1UL << 1) | (2 << 7);   //CS=1 CE=1 OP=Precharge
//	  LPC_EMC->DYNAMICREFRESH = 2;
//	  waitUS(100);
//
//	  LPC_EMC->DYNAMICREFRESH = N_TO_EMC_CLOCKS(15625UL) >>4;         //Put the dynamic refresh back to the correct value
//	  waitUS(100);
//
//	  LPC_EMC->DYNAMICCONTROL = (1UL << 0) | (1UL << 1) | (1 << 7);   //CS=1 CE=1 OP=MODE Send mode
//
//	  //                                                      Burst=8      CAS of 3
//	  *((volatile uint32_t *)(EMC_ADDRESS_DYCS0/*SDRAM0_ADDR*/ + (((3UL << 0) | (3UL << 4)) << (8UL + 1UL + 2UL))));  // Set mode register!
//
//
//	  LPC_EMC->DYNAMICCONTROL = (3 << 7);                             //CS=0 CE=0 OP=NOP //Datasheet says next command must be nop
//	  waitUS(100);
//
//	  LPC_EMC->DYNAMICCONTROL = 0;
//	  LPC_EMC->DYNAMICCONFIG0 = (1UL << 19);                          //enable buffers
//
//
//	  //Mem Test
//	  volatile uint32_t * ramPtr = (volatile uint32_t *)(EMC_ADDRESS_DYCS0);//(SDRAM0_ADDR);
//
//	  uint32_t testVal = 0x102;
//	  while((uint32_t)ramPtr < (/*SDRAM0_ADDR*/EMC_ADDRESS_DYCS0 + (8000000UL-1UL)))
//	  {
//	    *ramPtr = testVal;
//	    ++ramPtr;
//	    testVal += 0x101;
//	  }
}
