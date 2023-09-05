/**
 * @file ADC_interface.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


void MADC_voidInit() ;
u16 MADC_u16StartConversionSync(u8 Copy_u8ChannelNumber) ;
void MADC_voidStartConversionAsync(u8 Copy_u8ChannelNumber);
void MADC_voidSetCallback(void (*Copy_pvNotificationFunction)(void)) ;
s32 MAP(s32 Output_Max , s32 Output_Min , s32 Input_Max , s32 Input_Min, s32 Input_value);

#define ADC_CHANNEL0	0
#define	ADC_CHANNEL1	1
#define	ADC_CHANNEL2	2
#define ADC_CHANNEL3	3
#define	ADC_CHANNEL4	4
#define	ADC_CHANNEL5	5
#define	ADC_CHANNEL6	6
#define	ADC_CHANNEL7	7


#endif
