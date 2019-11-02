/* 
 * File:   Data_Link_Layer.h
 * Author: elliott
 *
 * Created on October 21, 2019, 6:52 PM
 */

#ifndef DATA_LINK_H
#define	DATA_LINK_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* DATA_LINK_LAYER_H */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <stdlib.h>        /* For string manipulation   */
#include <string.h>


void Emit_Audio_1200Hz_Square(void);    //  Simply pulses a pin
void Emit_Audio_1200Hz_Sin(void);       //  Approximates a sin wave
void Emit_Audio_2200Hz_Square(void);    //  Simply pulses a pin
void Emit_Audio_2200Hz_Sin(void);       //  Simply pulses a pin

bool Send_Packet( char *);
char * Receive_Packet(void);