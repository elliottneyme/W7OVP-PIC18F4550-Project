/* 
 * File:   lcd_module.h
 * Author: elliott
 *
 * Created on September 28, 2019, 10:38 AM
 */

#ifndef LCD_MODULE_H
#define	LCD_MODULE_H

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_MODULE_H */
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <stdlib.h>        /* For string manipulation   */
#include <string.h>
#include "pic18f4550.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

//  Define bits for control lines
#define RS                  PORTCbits.RC0
#define RW                  PORTCbits.RC1
#define E                   PORTCbits.RC2
//  Define bits for data 
#define D0                  PORTDbits.RD0  
#define D1                  PORTDbits.RD1
#define D2                  PORTDbits.RD2
#define D3                  PORTDbits.RD3    
#define D4                  PORTDbits.RD4
#define D5                  PORTDbits.RD5
#define D6                  PORTDbits.RD6    
#define D7                  PORTDbits.RD7

//  Define PORTS for control and data
#define TRISCONTROL         TRISC
#define TRISDATA            TRISD
#define CONTROL             PORTC
#define DATA                PORTD
//  Define CONTROL I/O modes
#define WRITE_INSTRUCTION           0    //  Sets CONTROL to write
#define WRITE_CG_OR_DD_RAM          1    //  Sets CONTROL to write data to memory
#define READ_BUSY_FLAG              2    //  Sets CONTROL to read
#define READ_CG_OR_DD_RAM           3    //  Sets CONTROL to read data
//  Define DATA instructions
#define ZERO_OUT                0//0x00    //  Sets DATA to 0x00
#define CLEAR_DISPLAY           1//0x01    //  Clears the display.
#define DISPLAY_OFF             8//0x08    //  Display OFF, Cursor OFF, Blink OFF
#define DISPLAY_ON              15//0x0F    //  Display ON, Cursor ON, Blink ON
#define RETURN_HOME             2//0x02    //  Returns display to upper left corner.
#define ENTRY_MODE_SET          6//0x06    //  Entry mode is increment, shift display
#define FUNCTION_SET            56//0x38    //  8-bit, 2-line, 5x7 dots
#define SET_DD_RAM_ADDRESS      128//0x80    //  Set the DD RAM Address
#define SECOND_LINE_ADDRESS     64//0x40    //  This is the memory address of the second line
#define JUMP_TO_SECOND_LINE     192
#define SHIFT_RIGHT             28
#define SHIFT_LEFT              24
//  Function Declarations
void LCD_Module_Initialize(void);
void LCD_Module_Initialize_2(void);
void Clear_Display(void);
void Return_Home(void);
void Entry_Mode_Set(bool,bool);
void Display_On_Off_Control(bool, bool, bool);
void Cursor_Or_Display_Shift();
void Function_Set(bool, bool, bool);
void Set_CG_RAM_Address(unsigned char);
void Set_DD_RAM_Address(unsigned char);
bool Read_Busy_Flag_and_Address(void);
void Write_Data_to_CG_or_DD_RAM(unsigned char);
unsigned char Read_Data_from_CG_or_DD_RAM(void);
void Pulse_Enable_Bit(void);
unsigned char Set_Instruction(unsigned char, unsigned char);
bool Wait(void);
void Display_Message(char *);


