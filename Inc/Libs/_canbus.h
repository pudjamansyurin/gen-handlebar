/*
 * _canbus.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Puja
 */

#ifndef CANBUS_H_
#define CANBUS_H_

#include "_can.h"
#include "_config.h"

// CAN Nodes
#define CAN_NODE_VCU												SetBit(0)
#define CAN_NODE_MCU												SetBit(1)
#define CAN_NODE_BMS												SetBit(2)
#define CAN_NODE_HMI												SetBit(3)

// CAN Node Selector
#define CAN_NODE														(CAN_NODE_MCU | CAN_NODE_BMS)

// CAN Message Address
#define CAN_ADDR_VCU_SWITCH					 				0x000
#define CAN_ADDR_VCU_RTC						 				0x001
#define CAN_ADDR_VCU_SELECT_SET			 				0x002
#define CAN_ADDR_VCU_TRIP_MODE			 				0x003
#define CAN_ADDR_MCU_DUMMY									0x7A0
#define CAN_ADDR_BMS_DUMMY									0x7B0

// Others Parameters
#define MCU_SPEED_MAX 											200
#define MCU_RPM_MAX 												119999
#define VCU_ODOMETER_MAX										99999
#define HMI_DRIVE_MODE_MAX									3

// ==================================== MCU =========================================
#if (CAN_NODE & CAN_NODE_MCU)
uint8_t CANBUS_MCU_Dummy(void);
#endif
// ==================================== BMS =========================================
#if (CAN_NODE & CAN_NODE_BMS)
uint8_t CANBUS_BMS_Dummy(void);
#endif

#endif /* CANBUS_H_ */
