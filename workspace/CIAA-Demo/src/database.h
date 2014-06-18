/*
 * database.h
 *
 *  Created on: Mar 8, 2014
 *      Author: Pablo
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#define TAM_UID			4
#define TAM_NOMBRE		30
#define MAX_TARJETAS 	10

#include "stdint.h"

typedef struct
{
	uint8_t uid[TAM_UID];
	char nombre[TAM_NOMBRE];
}registro_t;


int dbNewUID(char * strUID);
int dbSetName(char * strUID, char * nombre);
void dbGetList(char * list);


#endif /* DATABASE_H_ */
