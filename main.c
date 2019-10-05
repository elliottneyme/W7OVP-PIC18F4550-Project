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
    // Function Set
    
    for(int i =0; i<3 ; i++)
    {__delay_ms(10000);
        Function_Set(1,0,0);
    }
   __delay_ms(30);
   Function_Set(1,1,0);
   __delay_ms(30);
   Display_On_Off_Control(0,0,0);   //(Display,Cursor,Blink)
    __delay_ms(30);
   //Display_On_Off_Control(1,1,1);
   //Function_Set(1,1,0);           //(1= 8-bit, 0 =1 line , 0 = 5x7 dots)
   __delay_ms(30);
   Clear_Display();
   __delay_ms(30);
   Entry_Mode_Set(1,0);
   __delay_ms(30);
   Display_On_Off_Control(1,1,1);
   //__delay_ms(100);
   //Display_On_Off_Control(1,1,1);
   Write_Data_to_CG_or_DD_RAM(0x4C);

}

