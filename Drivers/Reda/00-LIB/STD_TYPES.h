/*
 ============================================================================
 Name        : STD_TYPES
 Layer		 : Service layer
 Target		 : Generic
 Author      : Muhamed REDA
 Version     : 1.0
 Date		 : 26/07/2023
 Copyright   : This is an open source code for all embedded systems students
 Description : This file defines the standard data types
 ============================================================================
 */
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long  int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long  int s32;

typedef float  f32;
typedef double f64;


#define NULL (void *)0

//Standard type for API's return type
typedef enum{
	E_OK,		//API status OK
	E_NOK		//API status Not OK
}Error_state;

/* User defined union Data Type to access bits and bytes */
typedef union{
	struct
	{
		u8 Bit0 : 1;
		u8 Bit1 : 1;
		u8 Bit2 : 1;
		u8 Bit3 : 1;
		u8 Bit4 : 1;
		u8 Bit5 : 1;
		u8 Bit6 : 1;
		u8 Bit7 : 1;
	}BitAccess;
	u8 ByteAccess;
}Register;


#endif