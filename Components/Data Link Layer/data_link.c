#include "data_link.h"
//  FILES to include
#include <stdbool.h>
#include "pic18f4550.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

void Emit_Audio_1200Hz_Square(void)     //  Simply pulses a pin
{
    while(1)
    {
    PORTAbits.RA0 = 1;
    __delay_us(464);
    PORTAbits.RA0 = 0;
    __delay_us(464);
    }
}
void Emit_Audio_1200Hz_Sin(void)        //  Approximates a sin wave
{
    PORTA = 0x00;           // Zero out all PORTA bits.
    
    while (1)
    {
        PORTAbits.RA0 = 1;
        __delay_us(52);
        PORTAbits.RA1 = 1;
        __delay_us(52);
        PORTAbits.RA2 = 1;
        __delay_us(52);
        PORTAbits.RA3 = 1;
        __delay_us(52);
        PORTAbits.RA3 = 0;
        __delay_us(52);
        PORTAbits.RA2 = 0;
        __delay_us(52);
        PORTAbits.RA1 = 0;
        __delay_us(52);
        PORTAbits.RA1 = 0;
        __delay_us(52);
    }
}
void Emit_Audio_2200Hz_Square(void)     //  Simply pulses a pin
{

}
void Emit_Audio_2200Hz_Sin(void)        //  Simply pulses a pin
{

}


bool Send_Packet(char * packet)
{
    // TODO write code here.
    return true;
}
char * Receive_Packet(void)
{
    char * ch = "Hello World!";
    return ch;
}