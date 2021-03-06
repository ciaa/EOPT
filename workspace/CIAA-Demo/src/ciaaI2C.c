/*
 * ciaaI2C.c
 *
 *  Created on: Jun 16, 2014
 *      Author: pablo
 */


#include "ciaaI2C.h"


void ciaaI2CInit(void)
{
	//configuro i2c y lo activo
	I2C_Init(LPC_I2C0, 100000);
	I2C_Cmd(LPC_I2C0, ENABLE);

}

Status ciaaI2CWrite(uint8_t sl_addr, uint8_t * buffer, int len)
{
	Status s;

	I2C_M_SETUP_Type i2cSetup;

	i2cSetup.sl_addr7bit = sl_addr; //control byte: ver hoja de datos!
	i2cSetup.tx_data = buffer;
	i2cSetup.tx_length = len;
	i2cSetup.retransmissions_max = 1;
	i2cSetup.rx_data = 0;
	i2cSetup.rx_length = 0;
	s = I2C_MasterTransferData(LPC_I2C0, &i2cSetup, I2C_TRANSFER_POLLING);

	return s;
}

Status ciaaI2CRead(uint8_t sl_addr, uint8_t * buffer, int len)
{
	Status s;
	I2C_M_SETUP_Type i2cSetup;

	i2cSetup.sl_addr7bit = sl_addr; //control byte: ver hoja de datos!
	i2cSetup.tx_data = 0;
	i2cSetup.tx_length = 0;
	i2cSetup.retransmissions_max = 1;
	i2cSetup.rx_data = buffer;
	i2cSetup.rx_length = len;
	s = I2C_MasterTransferData(LPC_I2C0, &i2cSetup, I2C_TRANSFER_POLLING);

	return s;

}
