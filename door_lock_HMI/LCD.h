 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD.h
 *
 * Description: LCD module header file
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define DATA_MODE 4

#if ( DATA_MODE == 4 )


#define HIGHER_NIBBLE_PORT

#endif

#define RS 0
#define RW 1
#define EN 2
#define LCD_data_port 'A'
#define LCD_ctrl_port 'B'

//COMMANDS

// 1) modes


#define LCD_8bit_1line 0x30
#define LCD_8bit_2line 0x38
#define LCD_4bit_1line 0x20
#define LCD_4bit_2line 0x28

// 2) display

#define LCD_displayOff_cursorOff 0x08
#define LCD_displayOn_cursorOff 0x0C
#define LCD_displayOn_cursorOn 0x0E
#define LCD_displayOn_cursorBlink 0x0F

// 3) Cursor Navigation

#define LCD_Cursor_reset 0x02
#define LCD_Cursor_left 0x10
#define LCD_Cursor_right 0x14
#define LCD_Cursor_move_to 0x80
#define LCD_Cursor_second_line 0xC0

// 4) Display Shift

#define LCD_Display_shift_left 0x18
#define LCD_Display_shit_right 0x1C

// 5) Clearing

#define LCD_clear_cmd 0x01



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void LCD_Command(uint8 cmd);
void LCD_displayChar(uint8 data);
void LCD_displayString(const char *str);
void LCD_init(void);
void LCD_Clear(void);
void LCD_display_String_Row_Column(uint8 row,uint8 col, const char *str);
void LCD_MoveTo_Row_Column(uint8 row, uint8 col);
void LCD_integerToString(sint8 data);
void LCD_refresh(void);
void LCD_display_int(uint8 data);
void LCD_display_int_nodelay(sint8 data);

#endif /* LCD_H_ */
