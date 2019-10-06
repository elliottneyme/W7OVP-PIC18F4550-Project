/* 
 * File:   lcd.h
 * Author: elliott
 *
 * Created on September 28, 2019, 10:38 AM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */
#include "stdbool.h"
#include "pic18f4550.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

//  Define bits for control lines
#define RS                  PORTDbits.RD0
#define RW                  PORTDbits.RD1
#define E                   PORTDbits.RD2
//  Define bits for data 
#define D0                  PORTBbits.RB0  
#define D1                  PORTBbits.RB1
#define D2                  PORTBbits.RB2
#define D3                  PORTBbits.RB3    
#define D4                  PORTBbits.RB4
#define D5                  PORTBbits.RB5
#define D6                  PORTBbits.RB6    
#define D7                  PORTBbits.RB7
//  Define PORTB as "DATA"
#define DATA                PORTB
//  Define PORTD I/O modes
#define PORT_WRITE_INSTRUCTION          0x00    //  Sets PORTD to write
#define PORT_READ_INSTRUCTION           0x01    //  Sets PORTD to read
#define PORT_WRITE_DATA         0x02    //  Sets PORTD to write data to memory
#define PORT_READ_DATA          0x03    //  Sets PORTD to read data
//  Define PORTB instructions
#define ZERO_OUT                0x00    //  Sets PORTB
#define CLEAR_DISPLAY           0x01    //  Clears the display.
#define DISPLAY_OFF             0x08    //  Display OFF, Cursor OFF, Blink OFF
#define DISPLAY_ON              0x0F    //  Display ON, Cursor ON, Blink ON
#define RETURN_HOME             0x02    //  Returns display to upper left corner.
#define ENTRY_MODE_SET          0x06    //  Entry mode is increment, shift display
#define FUNCTION_SET            0x38    //  8-bit, 2-line, 5x7 dots

void LCD_Module_Initialize(void);
void Clear_Display(void);
void Return_Home(void);
void Entry_Mode_Set(bool, bool);
void Display_On_Off_Control(bool, bool, bool);
void Cursor_Or_Display_Shift();
void Function_Set(bool, bool, bool);
void Set_CG_RAM_Address(unsigned char);
void Set_DD_RAM_Address(unsigned char);
bool Read_Busy_Flag_and_Address(unsigned char);
void Write_Data_to_CG_or_DD_RAM(unsigned char);
unsigned char Read_Data_from_CG_or_DD_RAM(void);
void Pulse_Enable_Bit(void);
void Set_Instruction(unsigned char);
