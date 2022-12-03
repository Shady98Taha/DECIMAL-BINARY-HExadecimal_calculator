#ifndef BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(PORT,BIT_Num) PORT=PORT|(1<<BIT_Num)
#define CLR_BIT(PORT,BIT_Num) PORT=PORT&(~(1<<BIT_Num))
#define GET_BIT(PORT,BIT_Num) ((PORT>>BIT_Num)&1)
#define TGL_Bit(PORT,BIT_Num) PORT=PORT^(1<<BIT_Num)


#endif
