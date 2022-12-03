#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_Private.h"

void DIO_VoidSetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
	if(1==Direction)
	{
		switch(Port)
		{
			case 0: SET_BIT(DDRA,Pin);  break;
			case 1: SET_BIT(DDRB,Pin);  break;
			case 2: SET_BIT(DDRC,Pin);  break;
			case 3: SET_BIT(DDRD,Pin);  break;	
		}
	}else if(0==Direction)
	{
		switch(Port)
		{
			case 0: CLR_BIT(DDRA,Pin);  break;
			case 1: CLR_BIT(DDRB,Pin);  break;
			case 2: CLR_BIT(DDRC,Pin);  break;
			case 3: CLR_BIT(DDRD,Pin);  break;			
		}
	}
	
}
void DIO_VoidSetPinValue (u8 Port, u8 Pin, u8 value)
{
	if(1==value)
	{
		switch(Port)
		{
			case 0: SET_BIT(PORTA,Pin);  break;
			case 1: SET_BIT(PORTB,Pin);  break;
			case 2: SET_BIT(PORTC,Pin);  break;
			case 3: SET_BIT(PORTD,Pin);  break;			
		}
		
	}else if(0==value)
	{
		switch(Port)
		{
			case 0: CLR_BIT(PORTA,Pin);  break;
			case 1: CLR_BIT(PORTB,Pin);  break;
			case 2: CLR_BIT(PORTC,Pin);  break;
			case 3: CLR_BIT(PORTD,Pin);  break;
		}

	}
}
u8 DIO_U8GetPinValue (u8 Port, u8 Pin)
{
	u8 x=0;
	switch(Port)
	{
			case 0: x=GET_BIT(PINA,Pin); break;
			case 1: x=GET_BIT(PINB,Pin); break;
			case 2: x=GET_BIT(PINC,Pin); break;
			case 3: x=GET_BIT(PIND,Pin); break;		
	}
	return x;
}
void DIO_VoidSetPortDirection(u8 Port, u8 Direction)
{
		switch(Port)
		{
			case 0: DDRA= Direction; break;
			case 1: DDRB= Direction; break;
			case 2: DDRC= Direction; break;
			case 3: DDRD= Direction; break;
		}
}
void DIO_VoidSetPortValue(u8 Port, u8 Value)
{
	switch(Port)
	{
		case 0: PORTA= Value; break;
		case 1: PORTB= Value; break;
		case 2: PORTC= Value; break;
		case 3: PORTD= Value; break;
	}
}
void DIO_VoidTogglePin(u8 Port,u8 Pin)
{
	switch(Port)
	{
		case 0:TGL_Bit(PORTA,Pin); break;
		case 1:TGL_Bit(PORTB,Pin); break;
		case 2:TGL_Bit(PORTC,Pin); break;
		case 3:TGL_Bit(PORTD,Pin); break;
	}
}
