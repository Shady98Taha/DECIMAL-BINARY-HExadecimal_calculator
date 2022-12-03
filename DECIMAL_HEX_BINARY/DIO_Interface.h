#ifndef _INTERFACE_H_
#define _INTERFACE_H_

void DIO_VoidSetPinDirection(u8 Port, u8 Pin, u8 Direction);
void DIO_VoidSetPinValue (u8 port, u8 pin, u8 value);
u8 DIO_U8GetPinValue (u8 Port, u8 Pin);
void DIO_VoidSetPortDirection(u8 Port, u8 Direction);
void DIO_VoidSetPortValue(u8 Port, u8 Value);
void DIO_VoidTogglePin(u8 Port,u8 Pin);



#endif
