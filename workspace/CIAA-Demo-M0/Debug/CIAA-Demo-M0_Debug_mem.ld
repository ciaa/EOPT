/*
 * GENERATED FILE - DO NOT EDIT
 * (c) Code Red Technologies Ltd, 2008-2014
 * (c) NXP Semiconductors 2013-2014
 * Linker script memory definitions
 * Created from LinkMemoryTemplate
 * By LPCXpresso v7.2.0 [Build 153] [2014-05-19]  on Tue Jul 08 14:47:10 ART 2014)
*/

MEMORY
{
  /* Define each memory region */
  RamLoc40 (rwx) : ORIGIN = 0x10080000, LENGTH = 0xa000 /* 40K bytes */


}
  /* Define a symbol for the top of each memory region */
  __top_RamLoc40 = 0x10080000 + 0xa000;



