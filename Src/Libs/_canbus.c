/*
 * _canbus.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Puja
 */

#include <Libs/_canbus.h>

CAN_Tx TxCan;
const TickType_t tick100ms = pdMS_TO_TICKS(500);
extern uint32_t DB_MCU_RPM;
extern uint8_t DB_MCU_Temperature;
extern uint8_t DB_BMS_SoC;
extern uint8_t DB_BMS_Temperature;

// ==================================== MCU =========================================
#if (CAN_NODE & CAN_NODE_MCU)
uint8_t CANBUS_MCU_Dummy(void) {
	// set message
	// RPM data
	TxCan.TxData[0] = (DB_MCU_RPM >> 0) & 0xFF;
	TxCan.TxData[1] = (DB_MCU_RPM >> 8) & 0xFF;
	TxCan.TxData[2] = (DB_MCU_RPM >> 16) & 0xFF;
	TxCan.TxData[3] = (DB_MCU_RPM >> 24) & 0xFF;
	// Temperature data
	TxCan.TxData[4] = DB_MCU_Temperature;

	// dummy algorithm
	DB_MCU_Temperature++;

	// set default header
	CAN_Set_Tx_Header(&(TxCan.TxHeader), CAN_ADDR_MCU_DUMMY, 5);

	// send message
	return CAN_Write(&TxCan);
}
#endif

// ==================================== BMS =========================================
#if (CAN_NODE & CAN_NODE_BMS)
uint8_t CANBUS_BMS_Dummy(void) {
	static TickType_t tick;

	// set message
	// SoC data
	TxCan.TxData[0] = DB_BMS_SoC;
	// Temperature data
	TxCan.TxData[1] = DB_BMS_Temperature++;

	// dummy algorithm
	if ((osKernelSysTick() - tick) >= tick100ms) {
		tick = osKernelSysTick();
		DB_BMS_SoC = (!DB_BMS_SoC ? 100 : (DB_BMS_SoC - 1));
	}

	// set default header
	CAN_Set_Tx_Header(&(TxCan.TxHeader), CAN_ADDR_BMS_DUMMY, 2);

	// send message
	return CAN_Write(&TxCan);
}
#endif
