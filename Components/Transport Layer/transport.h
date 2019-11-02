/* 
 * File:   Transport_Layer.h
 * Author: elliott
 *
 * Created on October 21, 2019, 6:53 PM
 */

#ifndef TRANSPORT_H
#define	TRANSPORT_H

#ifdef	__cplusplus
extern "C" {
#endif


    

#ifdef	__cplusplus
}
#endif

#endif	/* TRANSPORT_LAYER_H */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <stdlib.h>        /* For string manipulation   */
#include <string.h>        /* For string manipulation   */

char * Assemble_Packet(char *);
char * Compute_Checksum(char *);
    