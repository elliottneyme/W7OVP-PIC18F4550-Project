#include "lcd.h"
#include "pic18f4550.h"
/* Function:    LCD_Module_Initialize(void)
 * 
 * Software initialization of the the LCD module
 */
void LCD_Module_Initialize(void)
{
        /*  Power On    */
    
        /*  Wait more than 15ms after Vcc = 4.5V    
         *
         *  No data should be transferred to or from the display during
         *  this time.
         */
       __delay_ms(20);

        /*  Function Set Command: (8-bit interface)
         *
         *  BF cannot be checked before this command.
         */
       Function_Set(1,1,0);  
       
       /*  Wait more than 4.1ms    
        *
        *  No data should be transferred to or from the display during
        *  this time.
        */
       __delay_ms(5);

       /*  Function Set Command: (8-bit interface)
        *
        *  BF cannot be checked before this command.
        */
       Function_Set(1,1,0);  
       
       /*  Wait more than 100us   
         *
         *  No data should be transferred to or from the display during
         *  this time.
         */
       __delay_ms(1);

        /*  Function Set Command: (8-bit interface)
         *
         *  After this command is written, BF can be checked.
         */
        Function_Set(1,1,0);  
        //while(Read_Busy_Flag_and_Address())
            __delay_ms(1);
        /*   
        *   (Interface =  8 bits, Set No. of lines and display font)
        */
        Function_Set(1,0,0);    /* (8-bits, 1-line, 5 x 7 dots */
        
        /*  Read and wait on BF */
        while(Read_Busy_Flag_and_Address())
            __delay_ms(1);
        
        
        /*  Display OFF 
         *
         * (Display, Cursor, Blink) */
        Display_On_Off_Control(0,0,0);  /* Display, Cursor, and Blink set to off.*/
        
        /*  Read and wait on BF */
        while(Read_Busy_Flag_and_Address())
            __delay_ms(1);          
        
        /*  Clear Display   */
        Clear_Display();

        /*  Read and wait on BF */
        while(Read_Busy_Flag_and_Address())
            __delay_ms(1);
        
        /*  Entry Mode Set  
         * 
         * (Increment_Decrement, Set)
         */
        Entry_Mode_Set(1,0);
        
        /*  Read and wait on BF */
        while(Read_Busy_Flag_and_Address())
            __delay_ms(1);
        
        /*  Display ON
         *
         * (Set C and B for cursor/Blink options.)
         * (Display, Cursor, Blink)   */
        Display_On_Off_Control(1,1,0);  /* Display, Cursor, and Blink are on.*/
       
        /*  Initialization Complete, Display Ready.
         *
         *  Note:   BF should be checked before each of the instructions
         *  starting with Display OFF.  */
}

/* Function:  Clear_Display
    Writes the space code "20" (hexadecimal) into all addresses of DD RAM. 
 Returns display to its original position if it was shifted. 
 In other words the display clears and the cursor or blink moves to the
 upper left edge of the display.  The execution of clear display instruction 
 sets entry mode to increment mode. 
 LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
 Code        -> 0   0   0   0   0   0   0   0   0   1
 */
void Clear_Display(void)
{   /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    /* Set port B for output.*/
    TRISB = 0;
    
     // control bits
    RS = 0;
    RW = 0;
    // data bits
    /*
    D0 = 1;
    D1 = 0;
    D2 = 0;
    D3 = 0;
    D4 = 0;
    D5 = 0;
    D6 = 0;
    D7 = 0;
     */
    Data = 0x01;
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
 
}

/* Function:  Return_Home
 Note: x = Don't Care
 * Sets the DD RAM address "0" in address counter.  Return display to its
 * original position if it was shifted.  DD RAM contents do not change.
 * The cursor or the blink moves to the upper left of the display.  Text
 * on the display remains unchanged.
 LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
 Code        -> 0   0   0   0   0   0   0   0   1   x
 */
void Return_Home(void)
{
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
   /* Set port B for output.*/
    TRISB = 0;
    Data = 0x02;
    // control bits
    RS = 0;
    RW = 0;
    // data bits
    /*D0 = 0; // Don't care.
    D1 = 0;
    D2 = 1;
    D3 = 0;
    D4 = 0;
    D5 = 0;
    D6 = 0;
    D7 = 0;
    */
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
}

/* Function:  Entry_Mode_Set
 Sets the Increment/Decrement and Shift modes to the desired settings.
 * I/D: Increments (I/D = 1) or Decrements(ID = 0) the DD RAM address by 1 when 
 * a character code is written into or read from the DD RAM.
 * 
 * The cursor or blink moves to the right when incremented by +1/
 * 
 * The same applies to writing and reading the CG RAM.
 * 
 * S: Shifts the entire display either to the right or to the left when S = 1; 
 * shift to the left when I/D = 1 and to the right when I/D = 0.  Thus it looks
 * as if the cursor stands still and only the display seems to move.
 * 
 * The display does not shift when reading from DD RAM nor when S = 0;
 * 
 LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
 Code        -> 0   0   0   0   0   0   0   1   I/D S
 */
void Entry_Mode_Set(bool Increment_Decrement, bool Set)
{     
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    /* Set port B for output.*/
    TRISB = 0;
    Data = 0x00;
    // control bits
    RS = 0;
    RW = 0;
    // data bits
    D0 = Set;
    D1 = Increment_Decrement;
    D2 = 1;
    D3 = 0;
    D4 = 0;
    D5 = 0;
    D6 = 0;
    D7 = 0;
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
}

/* Function:  Display_On_Off_Control(bool Display, bool Cursor, bool Blink)
 Controls the display ON/OFF status, Cursor ON/OFF and Cursor Blink function.
 * 
 * D:  The display is ON when D = 1 and OFF when D = 0.  When OFF due to D = 0, 
 * display data remains in the DD RAM.   It can be displayed immediately by
 * setting D =  1.
 * 
 * C:   The cursor displays when C = 1 and does not display when C = 0.  The 
 * cursor is displayed on the 8th line when a 5x7 dot character font has been
 * selected.
 * 
 * B: The character indicated by the cursor blinks when B =  1.  The blink is 
 * displayed by switching between all blank dots and display characters at .4 
 * sec intervals.
 * The cursor and the blink can be set to display simultaneously.
 LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
 Code        -> 0   0   0   0   0   0   1   D   C   B
 */
void Display_On_Off_Control(bool Display, bool Cursor, bool Blink)
{ 
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    /* Set port B for output.*/
    TRISB = 0;
    Data = 0x00;
    // control bits
    RS = 0;
    RW = 0;
    // data bits
    D0 = Blink;      // 0 = don't Blink, 1 = Blink
    D1 = Cursor;     // 0 = Cursor off, 1 = Cursor on
    D2 = Display;    // 0 = Display off, 1 = Display on
    D3 = 1;
    D4 = 0;
    D5 = 0;
    D6 = 0;
    D7 = 0;
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
}

/* Function:  Cursor_or_Display_Shift(bool Shift_Cursor_or_Display, bool Right_Left)
 Note: x = Don't Care
 *  Shifts the cursor position or display to the right or left without writing 
 * or reading display data.  This function is used to correct or search for the 
 * display.  In a 2-line display the cursor moves to the 2nd line when it passes 
 * the 40th digit of the 1st line.  Notice that the 1st and 2nd line displays 
 * will shift at the same time.
 * 
 * When the displayed data is shifted repeatedly each line only moves
 * horizontally but the 2nd line display does not shift into the 1st line 
 * position.
 * 
 * S/C  R/L
 * 0    0   Shifts cursor position to the left (AC is decremented by one)
 * 0    1   Shifts cursor position to the right (AC is incremented by one)
 * 1    0   Shifts the entire display to the left. The cursor follows the
 *          display shift.
 * 1    1   Shifts the entire display to the right.  The cursor follows the
 *          display shift.
 * 
 * The contents of the Address Counter(AC) do not change if the only action 
 * performed is shifting display.
 LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
 Code        -> 0   0   0   0   0   1   S/C R/L x   x
 */
void Cursor_or_Display_Shift(bool Shift_Cursor_or_Display, bool Right_Left)
{
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    /* Set port B for output.*/
    TRISB = 0;
    // control bits
    RS = 0;
    RW = 0;
    // data bits
    D0 = 0;
    D1 = 0;
    D2 = Right_Left;                 // 0 = Left, 1 = Right
    D3 = Shift_Cursor_or_Display;    // 0 = Cursor, 1 = Display
    D4 = 1;
    D5 = 0;
    D6 = 0;
    D7 = 0;
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
}

/* Function:  Function_Set(bool Data_Length, bool Number_of_Lines, bool
 *                                              Set_Character_Font)
 * Sets the interface data length, the number of lines, and the character font.
 * 
 * Note: x =  Don't Care
 * 
 * DL:  Sets interface data length.  Data is sent or received in 8-bit length
 * (DB7~DB0) when DL = "1", and in 4-bit length(DB7~DB4) when DL = 0.  When the 
 * 4-bit length is selected, data must be sent or received twice.
 * 
 * N:   Sets the number of lines
 *      N = "0" :   1 line display (1/8 duty)
 *      N = "1" :   2 line display (1/16 duty)
 * 
 * F:   Sets character font.
 *      F = "1" :   5 x 10 dots
 *      F = "0" :   5 x 7 dots
 * 
 * Note:    Perform the function at the head of the program before executing all
 * instructions (except Busy flag/address read).  From this point, the function
 * set instruction cannot be executed other than to change interface length.
 * 
 LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
 Code        -> 0   0   0   0   1   DL  N   F   x   x
 */
void Function_Set(bool Data_Length, bool Number_of_Lines, bool Set_Character_Font)
{
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    /* Set port B for output.*/
    TRISB = 0;
    Data = 0x00;
    // control bits
    RS = 0;
    RW = 0;
    // data bits
    D0 = 0;                  // Don't Care
    D1 = 0;                  // Don't Care
    D2 = Set_Character_Font; // 0 = 5 x 7 dots, 1 = 5 x 10 dots
    D3 = Number_of_Lines;    // 0 = 1 line display, 1 = 2 line display
    D4 = Data_Length;        // 0 = 4-bit, 1 = 8-bit
    D5 = 1;
    D6 = 0;
    D7 = 0;
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
}

/* Function:  Set_CG_RAM_Address(unsigned char CG_RAM_Address)
 *  Sets the address counter to the CG RAM address AAAAAAA. Data is then written
 * /read from the CG RAM.
 *  LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
    PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
    Code        -> 0   0   0   1   A5  A4  A3  A2  A1  A0
 */
void Set_CG_RAM_Address(unsigned char CG_RAM_Address)
{
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    /* Set port B for output.*/
    TRISB = 0;
    Data = 0x00;
    // control bits
    RS = 0;
    RW = 0;
    // data bits
    Data = CG_RAM_Address;
    D6 = 1;
    D7 = 0;
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
}


/* Function:  Set_DD_RAM_Address(bool A0, bool A1, bool A2, bool A3, bool A4, bool A5, bool A6)
 
 *  Sets the address counter to the DD RAM address AAAAAAA.  Data is then written
 * /read from the DD RAM.
 * 
 * For a 1-line display module AAAAAAA is "00"~"4F" (hexadecimal).  For 2-line 
 * display module AAAAAAA is "00" ~ "27" (hexadecimal) for the first line and 
 * "40" ~ "67" (hexadecimal) for the second line.  (See section 1.7.6 "DD RAM 
 * addressing")
 * LCD Display ->   RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
   PIC 18F4550 ->   RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
   Code        ->   0   0   1   A6   A5  A4  A3  A2  A1  A0
 */
void Set_DD_RAM_Address(unsigned char DD_RAM_Address)
{
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    /* Set port B for output.*/
    TRISB = 0;
    Data = 0x00;
    // control bits
    RS = 0;
    RW = 0;
    // data bits
    Data = DD_RAM_Address;
    D7 = 1;
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
}


/* Function:    Read_Busy_Flag_and_Address(bool& A0, bool& A1, bool& A2, bool& A3, 
 *              bool& A4, bool& A5, bool& A6, bool& Busy_Flag)
 *  Reads the busy flag (BF) and the value of the address counter (AC).  BF =1 
 * indicates that on internal operation is in progress and the next instruction
 * will not be accepted until BF is set to "0".  If the display is written while
 * BF = 1, abnormal operation will occur.
 * 
 * The BF status should be checked before each write operation.
 * 
 * At the same time the value of the address counter expressed in binary AAAAAAA
 * is read out.  The address counter is used by both CG and DD RAM and its 
 * value is determined by the previous instruction.  Address contents are the 
 * same as in section 3.1.7 and 3.1.8.
 * 
 LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
 Code        -> 0   1   BF  A6   A5  A4  A3  A2  A1  A0
 */
bool Read_Busy_Flag_and_Address(void)
{
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    // Set port B as input.
    TRISB = 1;
    // control bits
    RS = 0;
    RW = 1;
   
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
    
    
    /*  Return BF   */
    return D7;
}


/* Function:    Write_Data_to_CG_or_DD_RAM(bool D0, bool D1, bool D2, bool D3,
 *                          bool D4, bool D5, bool D6, bool D7)
 * 
 *  Writes binary 8-bit data DDDDDDDD to the CG or DD RAM.
 * 
 * The previous designation determines whether the CG or DD RAM is to be written
 * (CG RAM address set or DD RAM address set).  After a write the entry mode will
 * automatically increase or decrease the address by 1.  Display shift will also
 * follow the entry mode.
 * 
 LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
 Code        -> 1   0   D7  D6  D5  D4  D3  D2  D1  D0
 */
void Write_Data_to_CG_or_DD_RAM(unsigned char CG_or_DD_RAM)
{
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    /* Set port B for output.*/
    TRISB = 0;
    Data = 0x00;
    // control bits
    RS = 1;
    RW = 0;
    // data bits
    Data = CG_or_DD_RAM;
    
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
}

/* Function:    Read_Data_From_CG_or_DD_RAM(bool& D0, bool& D1, bool& D2, bool& D3,
 *                          bool& D4, bool& D5, bool& D6, bool& D7)
 * 
 *  Reads binary 8-bit data DDDDDDDD from the CG or DD RAM.
 * 
 * The previous designation determines whether the CG or DD RAM is to be read.
 * 
 * Before entering the read instruction, you must execute either the CG RAM or 
 * DD RAM address set instruction.  
 * 
 * If you don't, the first read data will be invalidated.  When serially 
 * executing the "read" instruction the next address data is normally read from
 * the second read.
 * 
 * The "address set" instruction need not be executed just before the "read"
 * instruction (when reading DD RAM).  The cursor shift instruction operation
 * is the same as that of the DD RAM address set instruction.
 * 
 * After a read, the entry mode automatically increases or decreases the address
 * by 1; however, display shift is not executed no matter what the entry mode is.
 * 
 * Note:    The address counter (AC) is automatically incremented or decremented
 * by 1 after a "write" instruction to either CG RAM or DD RAM.  RAM data 
 * selected by the AC cannot then be read out even if "read" instructions are 
 * executed.
 * 
 * The conditions for correct data reads are:  (a) Execute either the address 
 * set instruction or cursor shift instruction (only with DD RAM) or (b) 
 * The execution of the "read data" instruction from the second time when the 
 * read instruction is performed multiple times in serial.
 * 
 * 
 LCD Display -> RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 PIC 18F4550 -> RC0 RC1 RB7 RB6 RB5 RB4 RB3 RB2 RB1 RB0
 Code        -> 1   1   D7  D6  D5  D4  D3  D2  D1  D0
 */
unsigned char Read_Data_from_CG_or_DD_RAM(void)
{
    /* Set port D for output.*/
    TRISD = 0;
    PORTD = 0x00;
    // Set port B as input. 
    TRISB = 1;
    // control bits
    RS = 1;
    RW = 1;
    // pulse the enable bit to enable instruction
    Pulse_Enable_Bit();
    return Data;
}
void Pulse_Enable_Bit(void)
{
  
    E = 1;
    __delay_ms(1);
    E = 0;
    __delay_ms(1);
}

/*  Function:   Function_Set_Command(unsigned char Command) */
void Set_Command(unsigned char Command)
{
    /*  Set Port D to output.*/
    TRISD = 0;
    /*  Initialize Port D   */
    PORTD = 0x00;
    /*  Set Port B to output.*/
    TRISB = 0;
    PORTB = 0x00;
    /*  Set Control Bits    */
    RS = 0;
    RW = 1;
    /*  Set Command to Data */
    Data = Command;
    
    Pulse_Enable_Bit();
}
