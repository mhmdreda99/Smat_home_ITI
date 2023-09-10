/**
 * @file ADC_Config.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef		ADC_CONFIG_H
#define		ADC_CONFIG_H

/* Options:
			ADC_AREF	
			ADC_AVCC    
			ADC_INTERNAL
*/
#define		ADC_REFVOLT		ADC_AVCC


/* Options:
			ENABLE	
            DISABLE
*/
#define		ADC_ADJUST_CTRL		 RIGHT

#define     ADC_PRESCALAR_VAL    ADC_PRESCALAR_BY_128


#endif
