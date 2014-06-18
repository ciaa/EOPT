/*
 * webserver.h
 *
 *  Created on: Mar 3, 2014
 *      Author: Pablo
 */

#ifndef WEBSERVER_H_
#define WEBSERVER_H_

#define LED1_BIT			12
#define LED1_PORT			5
#define LED2_BIT			13
#define LED2_PORT			5

void enetInit(void);
void webPeriodicalTask(void);

extern unsigned int pagecounter;

#endif /* WEBSERVER_H_ */
