#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

void LCD_VoidWriteCommend (u8 Commend);
void LCD_VoidWriteData (u8 Data);
void LCD_VoidInit(void);
void LCD_VoidFullName(u8 string[]);
void LCD_VoidWriteNum(u8 num);
void LCD_VoidSetCursor(u8 row, u8 column);












#endif
