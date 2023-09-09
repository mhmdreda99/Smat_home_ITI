/*
 * M_ADC_INT.c
 *
 *  Created on: ??�/??�/????
 *      Author: m
 */

#include"Std_Library.h"
#include"std_types.h"
#include"macros.h"
#include"M_ADC_PRIVATE.h"
#include"M_ADC_CNFG.h"
#include"M_ADC_REG.h"
#include"M_ADC_INT.h"

#if ADC_STATE==ADC_STATE_ENABLE

void MADC_voidInit(void)
{
/*********SELECT V REG************/
#if ADC_VOLATAGE_REFERENCE==AVCC_with_external_capacitor_at_AREF_pin
	ADC_ENABLE_AVCC_VOLTAGE_REF();
#elif ADC_VOLATAGE_REFERENCE==AREF_Internal_Vref_turned_off
	ADC_ENABLE_AREEF_VOLTAGE_REF();
#elif ADC_VOLATAGE_REFERENCE==AREF_Internal_2_56v_at_AREF_pin
	ADC_ENABLE_INTERNAL_2_56_REF();

#else
#error "wrong voltage reference for ADC CHECK ADC CNFG"
#endif
	/****************SELECT RIGHT ADJUST********/
#if ADC_DATA_ADJUSTMENT==ADC_RIGHT_ADJUST
	ADC_RIGHT_ADJUSTMENT();
#elif ADC_DATA_ADJUSTMENT==ADC_LEFT_ADJUST
	ADC_LEFT_ADJUSTMENT();
#else

#endif

	/*************** ADC PRESCALER CLOCK SET **********/
	 ADC_SELECT_CLOCK(ADC_PRESCALER_VAL);
	/*************** Enable_ADC***************/
	 ADC_ENABLE();
}
u16 MADC_u16_GetVal_BLOCKING(u8 ADC_channel)
{
		ADC_SELECT_CHANNEL(ADC_channel);
	/***********start conversion************/
	ADC_START_CONVERSION();
	//busy wait till conversion//
	while(GET_BIT(ADCSRA,ADIF)==0);
	ADC_FLAG_CLEAR();
	return ADC_DATA_REG;
}
u16 MADC_u16_GetVal_INTERRUPT(u8 ADC_channel)
{
		ADC_SELECT_CHANNEL(ADC_channel);
	/***********start conversion************/
	ADC_START_CONVERSION();
	//busy wait till conversion//
	while(GET_BIT(ADCSRA,ADIF)==0);
	ADC_FLAG_CLEAR();
	return ADC_DATA_REG;
}
/**************************************************** */
u16 MADC_u16_GetVal_POOLING(u8 ADC_channel)
{
	int i ;
		ADC_SELECT_CHANNEL(ADC_channel);
	/***********start conversion************/
	ADC_START_CONVERSION();
	for(int i=0; i<35;i++)
	{
		i++;
	}
	ADC_FLAG_CLEAR();
	return ADC_DATA_REG;
}
/*****************************************************/
double Mapping_Values(u16 X_max , u16 X_min , u16 Y_max ,u16 Y_min , u16 y )
{
	double X =0;
 X=((((double)X_max-X_min)*(y-Y_min))/((double)Y_max-Y_min))+X_min;
 return X;
}
#endif
