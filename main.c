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

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "lcd.h"           /* LCD module funct/params, like LCD_Module_Initialize */

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/




void main(void)
{   
    /* Enable Port A for input.
     * 
     * Used for stepping through the code. */
    /* Configure the oscillator for the device */
    //ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();
    
    //Initialize the LCD module
    LCD_Module_Initialize();
    
    
    unsigned char array[16];
    array[0]    =   'L';
    array[1]    =   'C';
    array[2]    =   'D';    
    array[3]    =   ' ';
    array[4]    =   'M';
    array[5]    =   'O';
    array[6]    =   'D';
    array[7]    =   'U';
    array[8]    =   'L';    
    array[9]    =   'E';
    array[10]    =   ' ';
    array[11]    =   'D';
    array[12]    =   'M';    
    array[13]    =   'C';
    array[14]    =   '1';
    array[15]    =   '6';
    
    for(int i = 0; i < 8; i++)
    {
    Wait();
    Set_Instruction(WRITE_CG_OR_DD_RAM, array[i]);
    }
    Wait();
    
    // Write to "2nd line" of DD RAM
    Set_DD_RAM_Address(0x40);
   
    //Wait();
    Set_Instruction(WRITE_INSTRUCTION, ENTRY_MODE_SET);
    
    for(int i = 8; i < 16; i++)
    {
    Wait();
    Set_Instruction(WRITE_CG_OR_DD_RAM, array[i]);
    }
    Wait();
}

