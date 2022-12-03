#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_Interface.h"



void LCD_VoidWriteCommend (u8 Commend)
{
	DIO_VoidSetPinValue(0,0,0);//RS to commend
	DIO_VoidSetPinValue(0,1,0);//Rw to commend
	DIO_VoidSetPortValue(2, Commend);//send data
	DIO_VoidSetPinValue(0,2,1);
	_delay_ms(1);
	DIO_VoidSetPinValue(0,2,0);
	_delay_ms(2);
	
}
void LCD_VoidWriteData (u8 Data)
{
	DIO_VoidSetPinValue(0,0,1);//RS to commend 
	DIO_VoidSetPinValue(0,1,0);//Rw to commend
	DIO_VoidSetPortValue(2, Data);//send data
	DIO_VoidSetPinValue(0,2,1);
	_delay_ms(1);
	DIO_VoidSetPinValue(0,2,0);
	_delay_ms(2);
	
} 
void LCD_VoidInit(void)
{
	DIO_VoidSetPinDirection(0,0,1);
	DIO_VoidSetPinDirection(0,1,1);
	DIO_VoidSetPinDirection(0,2,1);
	DIO_VoidSetPortDirection(2,0b11111111);
	
	_delay_ms(40);
	LCD_VoidWriteCommend(0b00111100);
	_delay_ms(1);
	LCD_VoidWriteCommend(0b00001111);
	_delay_ms(1);
	LCD_VoidWriteCommend(0b00000001);
	_delay_ms(2);
	
	
}
void LCD_VoidFullName(u8 string[]) 
{
	u8 i=0; 
	while(string[i]!=0)
	{
		LCD_VoidWriteData(string[i]);
		i++;
		_delay_ms(2);
	}
}
void LCD_VoidWriteNum(u16 num)
{
	u16 rev=0,x=0;
	while(num!=0)
	{
		rev=rev*10+(num%10);
		num=num/10;
	}
	while(rev!=0)
	{
		x=rev%10;
		rev=rev/10;
		LCD_VoidWriteData(x+48);
	}
}
void LCD_VoidSetCursor(u8 row, u8 column)
{
	if(0==row)
	{
		LCD_VoidWriteCommend(128+column);
	}else if(1==row)
	{
		LCD_VoidWriteCommend(128+64+column);
	}
}
