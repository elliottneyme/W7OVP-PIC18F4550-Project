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
    unsigned char strmessage[16] = "Hello ELMAN, you rule.";
    
    // Write to 1st line of DD RAM
    for (int i = 0; i < 8; i++) {
        Set_Instruction(WRITE_CG_OR_DD_RAM, strmessage[i]);
        Wait();
    }

    // Write to 2nd line of DD RAM
    //Set_DD_RAM_Address(0x40);
    Set_Instruction(WRITE_INSTRUCTION, 0xC0);
    //Wait();
   // __delay_ms(20);
    Set_Instruction(WRITE_INSTRUCTION, ENTRY_MODE_SET);
    Wait();

    for (int j = 8; j < strlen(strmessage); j++) {
        Set_Instruction(WRITE_CG_OR_DD_RAM, strmessage[j]);
        Wait();
    }

}

