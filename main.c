/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
#include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <stdlib.h>        /* For string manipulation   */
#include <string.h>        /* For string manipulation   */
//#include <cstring>         /* For string manipulation   */
#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "lcd.h"           /* LCD module funct/params, like LCD_Module_Initialize */
#include "ax_25.h"         /* AX.25 funct/params, like Emit audio */
/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */

/******************************************************************************/




void main(void) {
   
    /* Configure the oscillator for the device */
    //ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();
    //Emit_Audio_1200Hz_Square();
    //initialize a message to display on the LCD module
    //unsigned char strmessage[16] = "Hello World";
    //  Write a message
    unsigned char array[12];
    array[0] = 'H';
    array[1] = 'E';
    array[2] = 'L';
    array[3] = 'L';
    array[4] = 'O';
    array[5] = ' ';
    array[6] = 'D';
    array[7] = 'A';
    array[8] = 'V';
    array[9] = 'E';
 /*   array[10] = '';
    array[11] = '';
    array[12] = '';
    array[13] = '';
    array[14] = '';
    array[15] = '';
*/
    //Wait();
    //Set_Instruction(WRITE_INSTRUCTION, CLEAR_DISPLAY);
   // Wait();
    // Write to 1st line of DD RAM
   
    for (int i = 0; i < 8; i++) {
        Set_Instruction(WRITE_CG_OR_DD_RAM, array[i]);
        Wait();
    }

/*
    // Write to 2nd line of DD RAM
    Set_DD_RAM_Address(0x40);

    //Wait();
    Set_Instruction(WRITE_INSTRUCTION, ENTRY_MODE_SET);
    Wait();

    for (int j = 8; j < 11; j++) {
        Set_Instruction(WRITE_CG_OR_DD_RAM, array[j]);
        Wait();
    }
  */ 
}

