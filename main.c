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
    TRISA = 1;
    /* Configure the oscillator for the device */
    //ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    //InitApp();
    
    //Initialize the LCD module
    //LCD_Module_Initialize();
    
    // Power ON
    // Function Set - do three times
    __delay_ms(20000);
    
    for(int i =0; i<3 ; i++)
    {
    // Set function to use 8-bit data length, Number_of_lines and font are don't cares.
    Set_Command(0x3C);
    // long wait to view behavior
    __delay_ms(20000);
    }
    // Set function to use 8-bit data length, 2-lines, and 5x7 dots
    Set_Command(0x3C);
    //  Wait a long time to view behavior.
    __delay_ms(20000);
    //  Display off, Cursor, and Blink are set to off
    Set_Command(0x08);
    //  Wait a long time to observe behavior.
    __delay_ms(20000);
    //  Clear the display, send cursor to upper left corner
    Set_Command(0x01);
    //  Wait a long time to observe behavior.
    __delay_ms(20000);
    //  Set the entry mode.  Increment.
    Set_Command(0x06);
    //  Wait a long time to observe behavior.
    __delay_ms(20000);
    //  Enable display, cursor, and blink.
    Set_Command(0x0F);
    //Write_Data_to_CG_or_DD_RAM(0x4C);

}

