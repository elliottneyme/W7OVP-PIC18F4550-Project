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

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "./Components/LCD Module/lcd_module.h"           /* LCD module funct/params, like LCD_Module_Initialize */
#include "./Components/Data Link Layer/data_link.h"       /* Data link funct/params, like Emit audio */
#include "./Components/GPS Serial Port/gps_serial_port.h" /* GPS and Serial Port funct/params */
#include "./Components/Morse Code Interpreter/morse_code_interpreter.h" 
#include "./Components/Transport Layer/transport.h"       /* Transport funct/params */

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
    //  Emit_Audio_1200Hz_Square();
    //  Initialize a message to display on the LCD module
    char message[40] = "Hello to you today!!!";
    

    //  Display the message 
    int len = strlen(message);
    // Write to 1st line of DD RAM
    for(int i = 0; i < len; i++)
    {
        Set_Instruction(WRITE_CG_OR_DD_RAM, message[i]);
        Wait();
    }
    // Write to 2nd line of DD RAM
    Set_Instruction(WRITE_INSTRUCTION,192);// SET_DD_RAM_ADDRESS & SECOND_LINE_ADDRESS);
    //Wait();  
    // Set entry mode.
    Set_Instruction(WRITE_INSTRUCTION, ENTRY_MODE_SET);
    //  Write all but the first 8 characters to the second half of the LCD module
    for(int j = 8; j < len; j++) 
    {
        Wait();
        Set_Instruction(WRITE_CG_OR_DD_RAM,message[j]);
    }
    
    
    //  Now the LCD module contains the message in both of the two line display
    //  Shift left to see the whole message.
    for(int l = 0; l < len; l++)
    {
        Set_Instruction(WRITE_INSTRUCTION,SHIFT_LEFT);
        Wait();
        __delay_ms(4000);
    }

}

