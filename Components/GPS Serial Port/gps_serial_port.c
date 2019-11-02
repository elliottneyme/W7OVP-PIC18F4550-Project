#include "gps_serial_port.h"

//Set registers associated with the EUSART.
bool Serial_Port_Initialize(int baud_rate)
{
    //  Determine the serial port baud rate generator value
    char baud_rate_generator = (_XTAL_FREQ / baud_rate / 64) - 1;
    //  Set the relevent registers.
 
    SPEN = 1;
    RX9 = 0;
    
    
    
    
    
}

bool Send_Serial_Port(char *str_character_array)
{
    // TODO: write code.
    return true;
}

char * Receive_Serial_Port(void)
{
// TODO: write code.
    char *ch = "Hello Work!";
    return ch;
}