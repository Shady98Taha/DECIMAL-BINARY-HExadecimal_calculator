#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "LCD_Interface.h"


void CALC_DecToBin(u32 z)
{
	u32 x,i=0;
	for(i=0;i<8;i++)
	{
		x=z&128;
		if(x==128)
		{
			LCD_VoidWriteNum(1);
		}else if(x==0)
		{
			LCD_VoidWriteData(48);
		}
		z=z<<1;
	}
}


/*
u8 *CALC_DecToHex(u8 num)
{
	u8 total_number=0;
	u8 HEX_bit=0;
	u8 Count_up_hex=0;
	u8 Count_down_hex=0;
	u8 Hex_1[]={0};
	static u8 *Hex_2;
	u8 x=0;
	total_number=num;
	while(total_number!=0)
	{
		HEX_bit=total_number%16;
		total_number=total_number/16;
		Hex_1[Count_down_hex]=HEX_bit;
		Count_down_hex++;
	}
	while(Count_down_hex>=0)
	{
		Hex_2[Count_up_hex]=Hex_1[Count_down_hex];
		Count_down_hex--;
		Count_up_hex++;
	}
	return final_arr;
}
*/


u16 CALC_BinToDec(u8 bin)
{
	static u16 count_bit=1;
	static u16 k=1;
	u32 z=0;
		if(bin==1)
		{
			k=k+1;
			z=count_bit;
			count_bit=count_bit*2;
		}else if(bin==0)
		{
			k=k+1;
			z=0;
			count_bit=count_bit*2;
		}
		if(k==9)
		{
			k=1;
			count_bit=1;
		}
	return z;
}
