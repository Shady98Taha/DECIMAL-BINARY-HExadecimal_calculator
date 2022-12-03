/*
 * main.c
 *
 *  Created on: Nov 21, 2022
 *      Author: shady
 */

#include"STD_TYPES.h"
#include"BIT_Math.h"
#include"LCD_Interface.h"
#include"KEYPAD_Interface.h"
#include"CALC_Interface.h"
void main(void)
{
	LCD_VoidInit();
	KEYPAD_VoidInit();
while(1)
{
	u8 x=0,y=0,z=0;
	u32 bit_bit=0, total_decimal_number=0;
	u8 i=0;
	u8 num_dec=0;
	u16 total_number=0;
	u16 bit_total_number;
	/*Hex to Decimal variables*/
	u8 HEX_bit=0;
	u8 Count_up_hex=0;
	u8 Count_down_hex=0;
	u16 Hex_1[]={0};
	u16 Hex_2[]={0};
	u8 Count_down_max;
	u16 total_hex_number=1;
	u16 total_number_decimal=0;
	/*                                */
	LCD_VoidWriteCommend(1);
	LCD_VoidSetCursor(0,0);
	LCD_VoidWriteNum(1);
	LCD_VoidFullName("DEC");
	LCD_VoidWriteData(' ');
	LCD_VoidWriteNum(2);
	LCD_VoidFullName("BIN");
	LCD_VoidWriteData(' ');
	LCD_VoidWriteNum(3);
	LCD_VoidFullName("HEX");
	LCD_VoidSetCursor(1,0);
	while(x!=15)
			{
				x=KEYPAD_VoidGetNumber();
				if(x!=100 && x!=15)
				{
					switch(x)
					{
					case 1: LCD_VoidWriteNum(x); y=x; break;
					case 2: LCD_VoidWriteNum(x); y=x; break;
					case 3: LCD_VoidWriteNum(x); y=x; break;
					default: LCD_VoidFullName("Wrong"); break;
					}

				}

			}
			LCD_VoidWriteCommend(1);
	if(y==1)
	{
				LCD_VoidSetCursor(0,0);
				LCD_VoidWriteNum(1);
				LCD_VoidFullName("DEC>>Bin");
				LCD_VoidSetCursor(1,0);
				LCD_VoidWriteNum(2);
				LCD_VoidFullName("Dec>>Hex");
				LCD_VoidSetCursor(1,9);
				while(z!=15)
				{
					z=KEYPAD_VoidGetNumber();
					if(z!=100 && z!=15)
					{
						switch(z)
						{
							case 1: num_dec=z; break;
							case 2: num_dec=z; break;
						}
					}
					if(z==1 || z==2)
					{
						break;
					}
				}
			LCD_VoidWriteCommend(1);
			switch(num_dec)
		{
			case 1:
			{
				z=100;
				LCD_VoidSetCursor(0,0);
				LCD_VoidFullName("DEC:");
				LCD_VoidSetCursor(1,0);
				LCD_VoidFullName("BIN:");
				LCD_VoidSetCursor(0,4);
				while(z!=15)
				{
					z=KEYPAD_VoidGetNumber();
					if(z!=100 && z!=15)
					{
						if(z==0)
						{
						LCD_VoidWriteData(48);
						}else
						{
						LCD_VoidWriteNum(z);
						}
						total_number=(total_number*10)+z;
					}

				}
				LCD_VoidSetCursor(1,4);
				CALC_DecToBin(total_number);
				while(z!=14)
				{
					z=KEYPAD_VoidGetNumber();
					x=100;
					y=0;
				}
				break;

			}
			case 2:
			{
				z=100;
				LCD_VoidSetCursor(0,0);
				LCD_VoidFullName("DEC:");
				LCD_VoidSetCursor(1,0);
				LCD_VoidFullName("HEX:");
				LCD_VoidSetCursor(0,4);
				while(z!=15)
				{
					z=KEYPAD_VoidGetNumber();
					if(z!=100 && z!=15)
					{
						if(z==0)
						{
						LCD_VoidWriteData(48);
						}else
						{
						LCD_VoidWriteNum(z);
						}
						total_number=(total_number*10)+z;
					}
				}
				while(total_number!=0)
				{
					HEX_bit=total_number%16;
					total_number=total_number/16;
					Hex_1[Count_down_hex]=HEX_bit;
					Count_down_hex++;
				}
				Count_down_hex--;
				while(Count_down_hex>0)
				{
					Hex_2[Count_up_hex]=Hex_1[Count_down_hex];
					Count_down_hex--;
					Count_up_hex++;
				}
				Hex_2[Count_up_hex]=Hex_1[Count_down_hex];
				LCD_VoidSetCursor(1,4);
				while(Count_down_hex<=Count_up_hex)
				{
					if(Hex_2[Count_down_hex]>=10 && Hex_2[Count_down_hex]<=15)
					{
						switch(Hex_2[Count_down_hex])
						{
							case 10: LCD_VoidWriteData('A'); break;
							case 11: LCD_VoidWriteData('B'); break;
							case 12: LCD_VoidWriteData('C'); break;
							case 13: LCD_VoidWriteData('D'); break;
							case 14: LCD_VoidWriteData('E'); break;
							case 15: LCD_VoidWriteData('F'); break;
						}

					}else
					{
						if(Hex_2[Count_down_hex]==0)
						 {
							LCD_VoidWriteData(48);

						 }else
						 	 {
							 	 LCD_VoidWriteNum(Hex_2[Count_down_hex]);
						 	 }
					}
						Count_down_hex++;
					}

				while(z!=14)
				{
					z=KEYPAD_VoidGetNumber();
					x=100;
					y=0;
				}
				break;

			}
		}
	}else if(y==2)
	{
	LCD_VoidSetCursor(0,0);
	LCD_VoidWriteNum(1);
	LCD_VoidFullName("BIN>DEC");
	LCD_VoidSetCursor(1,0);
	LCD_VoidWriteNum(2);
	LCD_VoidFullName("BIN>Hex");
	LCD_VoidSetCursor(1,9);
	while(z!=15)
	{
		z=KEYPAD_VoidGetNumber();
		if(z!=100 && z!=15)
		{
			switch(z)
			{
				case 1: num_dec=z; break;
				case 2: num_dec=z; break;
			}
		}
		if(z==1 || z==2)
		{
			break;
		}
	}
	LCD_VoidWriteCommend(1);
	switch(num_dec)
	{
			case 1:
			{
				z=100;
				u8 j=11;
				LCD_VoidSetCursor(0,0);
				LCD_VoidFullName("BIN:");
				LCD_VoidSetCursor(1,0);
				LCD_VoidFullName("DEC:");
				LCD_VoidSetCursor(0,4);
				while(z!=15)
				{
					z=KEYPAD_VoidGetNumber();
					if(z!=100 && z!=15)
					{
						LCD_VoidSetCursor(0,j);
						if(z==0)
						{
							LCD_VoidWriteData(48);
							j=j-1;
						}else if(z==1)
						{
							LCD_VoidWriteNum(z);
							j=j-1;
						}
						bit_bit=CALC_BinToDec(z);
						total_decimal_number=total_decimal_number + bit_bit;
					}

				}
				LCD_VoidSetCursor(1,4);
				if(total_decimal_number%10==0)
				{
					LCD_VoidWriteNum(total_decimal_number);
					while(total_decimal_number%10==0)
					{
						LCD_VoidWriteData(48);
						total_decimal_number=total_decimal_number/10;

					}
				}else
				{
					LCD_VoidWriteNum(total_decimal_number);
				}

				z=0;
				while(z!=14)
				{
					z=KEYPAD_VoidGetNumber();
				}
				break;
			}
			case 2:
			{
				z=100;
				u8 j=11;
				LCD_VoidSetCursor(0,0);
				LCD_VoidFullName("BIN:");
				LCD_VoidSetCursor(1,0);
				LCD_VoidFullName("HEX:");
				LCD_VoidSetCursor(0,4);
				while(z!=15)
					{
						z=KEYPAD_VoidGetNumber();
						if(z!=100 && z!=15)
						{
							LCD_VoidSetCursor(0,j);
							if(z==0)
								{
									LCD_VoidWriteData(48);
									j=j-1;
								}else if(z==1)
								{
									LCD_VoidWriteNum(z);
									j=j-1;
								}
							bit_bit=CALC_BinToDec(z);
							total_decimal_number=total_decimal_number + bit_bit;
						}

					}
				while(total_decimal_number!=0)
				{
					HEX_bit=total_decimal_number%16;
					total_decimal_number=total_decimal_number/16;
					Hex_1[Count_down_hex]=HEX_bit;
					Count_down_hex++;
				}
				Count_down_hex--;
				while(Count_down_hex>0)
				{
					Hex_2[Count_up_hex]=Hex_1[Count_down_hex];
					Count_down_hex--;
					Count_up_hex++;
				}
				Hex_2[Count_up_hex]=Hex_1[Count_down_hex];
				LCD_VoidSetCursor(1,4);
				while(Count_down_hex<=Count_up_hex)
				{
					if(Hex_2[Count_down_hex]>=10 && Hex_2[Count_down_hex]<=15)
					{
						switch(Hex_2[Count_down_hex])
						{
							case 10: LCD_VoidWriteData('A'); break;
							case 11: LCD_VoidWriteData('B'); break;
							case 12: LCD_VoidWriteData('C'); break;
							case 13: LCD_VoidWriteData('D'); break;
							case 14: LCD_VoidWriteData('E'); break;
							case 15: LCD_VoidWriteData('F'); break;
						}

					}else
					{
						if(Hex_2[Count_down_hex]==0)
						 {
							LCD_VoidWriteData(48);

						  }else
							{
								LCD_VoidWriteNum(Hex_2[Count_down_hex]);
							}

					}
					Count_down_hex++;
				}
				while(z!=14)
				{
					z=KEYPAD_VoidGetNumber();
				}
				break;

			}

	}
	}

	/* change from Hex to binary or decimal*/
	else if(y==3)
	{
			LCD_VoidSetCursor(0,0);
			LCD_VoidWriteNum(1);
			LCD_VoidFullName("HEX>DEC");
			LCD_VoidSetCursor(1,0);
			LCD_VoidWriteNum(2);
			LCD_VoidFullName("HEX>BIN");
			LCD_VoidSetCursor(1,9);
			while(z!=15)
			{
				z=KEYPAD_VoidGetNumber();
				if(z!=100 && z!=15)
				{
					switch(z)
					{
						case 1: num_dec=z; break;
						case 2: num_dec=z; break;
					}
				}
				if(z==1 || z==2)
				{
					break;
				}
			}
			LCD_VoidWriteCommend(1);
			switch(num_dec)
			{
			case 1:
				{
					LCD_VoidSetCursor(0,0);
					LCD_VoidFullName("HEX:");
					LCD_VoidSetCursor(1,0);
					LCD_VoidFullName("DEC:");
					LCD_VoidSetCursor(0,4);
					while(z!=16)
					{
						z=KEYPAD_VoidGetNumber();
						if(z==15)
						{
							z=z+1;
						}else if(z!= 16 && z!=100)
						   {
							if(z==13)
							{
								while(z==13 || z==100)
								{
									z=KEYPAD_VoidGetNumber();
									switch(z)
									{
									case 1: LCD_VoidWriteData('A'); z=10; break;
									case 2: LCD_VoidWriteData('B'); z=11; break;
									case 3: LCD_VoidWriteData('C'); z=12; break;
									case 4: LCD_VoidWriteData('D'); z=13; break;
									case 5: LCD_VoidWriteData('E'); z=14; break;
									case 6: LCD_VoidWriteData('F'); z=15; break;
								    }
									if(z==10||z==11||z==12||z==13||z==14||z==15)
									{
										break;
									}
								}
							}else if(z<10)
							{
								if(z==0)
								{
									LCD_VoidWriteData(48);
								}else
								{
									LCD_VoidWriteNum(z);
								}

							}
							Hex_1[Count_down_hex]=z;
							Count_down_hex++;
						}

					}
					Count_down_hex--;
					Count_down_max=Count_down_hex;
					while(Count_up_hex<Count_down_max)
					{
						Hex_2[Count_up_hex]=Hex_1[Count_down_hex];
						Count_up_hex++;
						Count_down_hex--;
					}
					Hex_2[Count_up_hex]=Hex_1[Count_down_hex];
					while(Count_down_hex<=Count_down_max)
					{
						for(u8 s=0;s<Count_up_hex;s++)
						{

								total_hex_number=total_hex_number*16;
						}
						if(Count_up_hex==0)
						{
							total_hex_number=1;
						}
						total_number_decimal=Hex_2[Count_up_hex]*total_hex_number+total_number_decimal;
						total_hex_number=1;
						Count_down_hex++;
						Count_up_hex--;
					}
					LCD_VoidSetCursor(1,4);
					if(total_number_decimal%10==0)
					{
						LCD_VoidWriteNum(total_number_decimal);
						while(total_number_decimal%10==0)
						{
							LCD_VoidWriteData(48);
							total_number_decimal=total_number_decimal/10;
						}

					}else
					{
						LCD_VoidWriteNum(total_number_decimal);
					}
					while(z!=14)
					{
						z=KEYPAD_VoidGetNumber();
					}
					break;
				}
			case 2:
			{
				LCD_VoidSetCursor(0,0);
				LCD_VoidFullName("HEX:");
				LCD_VoidSetCursor(1,0);
				LCD_VoidFullName("BIN:");
				LCD_VoidSetCursor(0,4);
				while(z!=16)
				{
					z=KEYPAD_VoidGetNumber();
					if(z==15)
					{
						z=z+1;
					}else if(z!= 16 && z!=100)
					   {
						if(z==13)
						{
							while(z==13 || z==100)
							{
								z=KEYPAD_VoidGetNumber();
								switch(z)
								{
								case 1: LCD_VoidWriteData('A'); z=10; break;
								case 2: LCD_VoidWriteData('B'); z=11; break;
								case 3: LCD_VoidWriteData('C'); z=12; break;
								case 4: LCD_VoidWriteData('D'); z=13; break;
								case 5: LCD_VoidWriteData('E'); z=14; break;
								case 6: LCD_VoidWriteData('F'); z=15; break;
							    }
								if(z==10||z==11||z==12||z==13||z==14||z==15)
								{
									break;
								}
							}
						}else if(z<10)
						{
							if(z==0)
							{
								LCD_VoidWriteData(48);
							}else
							{
								LCD_VoidWriteNum(z);
							}

						}
						Hex_1[Count_down_hex]=z;
						Count_down_hex++;
					}

				}
				Count_down_hex--;
				Count_down_max=Count_down_hex;
				while(Count_up_hex<Count_down_max)
				{
					Hex_2[Count_up_hex]=Hex_1[Count_down_hex];
					Count_up_hex++;
					Count_down_hex--;
				}
				Hex_2[Count_up_hex]=Hex_1[Count_down_hex];
				while(Count_down_hex<=Count_down_max)
				{
					for(u8 s=0;s<Count_up_hex;s++)
					{

							total_hex_number=total_hex_number*16;
					}
					if(Count_up_hex==0)
					{
						total_hex_number=1;
					}
					total_number_decimal=Hex_2[Count_up_hex]*total_hex_number+total_number_decimal;
					total_hex_number=1;
					Count_down_hex++;
					Count_up_hex--;
				}
				LCD_VoidSetCursor(1,4);
				CALC_DecToBin(total_number_decimal);
				while(z!=14)
				{
					z=KEYPAD_VoidGetNumber();
				}
				break;
			}

			}
	}
}
}
