/* 
 * File:   GPS_Serial_Port.h
 * Author: elliott
 *
 * Created on October 21, 2019, 6:37 PM
 */

#ifndef GPS_SERIAL_PORT_H
#define	GPS_SERIAL_PORT_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* GPS_SERIAL_PORT_H */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>        /* For uint8_t definition */
#include <stdlib.h>        /* For string manipulation   */
#include <string.h>
#include "pic18f4550.h"
#include <xc.h>

#define _XTAL_FREQ 4000000


bool Serial_Port_Initialize(int);
bool Send_Serial_Port(char *);
char * Receive_Serial_Port(void);