#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_Interface.h"
#include <avr/delay.h>

void KEYPAD_VoidInit(void)
{
	DIO_VoidSetPortDirection(3,0b00001111);
	DIO_VoidSetPortValue(3,0b11111111);
}

u8 KEYPAD_VoidGetNumber(void)
{
	u8 x=0;
	u8 pressed_key=100;
	for(u8 column=0; column<4;column++)
	{
		DIO_VoidSetPinValue(3,column,0);
		for(u8 row=0;row<4;row++)
		{
			x = DIO_U8GetPinValue(3,(row+4));
			if(0==x)
			{
				pressed_key=((row*4)+column);
				while(0==x)
				{
					x=DIO_U8GetPinValue(3,(row+4));
				}
				_delay_ms(2);
			}
		}
		DIO_VoidSetPinValue(3,column,1);
	}
	return pressed_key;
}













