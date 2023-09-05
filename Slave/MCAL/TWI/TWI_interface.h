/**
 * @file TWI_interface.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartConditionError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,

}TWI_ErrorStatus_t;


void 				MTWI_voidMasterInit(u8 Copy_u8SlaveAddress);
void 				MTWI_voidSlaveInit(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus_t 	MTWI_ErrorStatusSendStartCondition(void);
TWI_ErrorStatus_t 	MTWI_ErrorStatusSendRepeatedStartCondition(void);
TWI_ErrorStatus_t 	MTWI_ErrorStatusSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus_t 	MTWI_ErrorStatusSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus_t MTWI_ErrorStatusMasterWriteDataByte(u8 Copy_u8Data);
TWI_ErrorStatus_t MTWI_ErrorStatusMasterReadDataByte(u8 * Copy_pu8ReceivedData) ;
void MTWI_voidSendStopCondition(void) ;



#endif
