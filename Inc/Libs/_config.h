/*
 * _config.h
 *
 *  Created on: Aug 26, 2019
 *      Author: Puja
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "main.h"
#include "cmsis_os.h"
#include "_swv.h"

// macro to manipulate bit
#define SetBit(x) 								(1 << x)
#define SetBitOf(var, x) 					(var |= 1 << x)
#define ClearBitOf(var, x) 				(var &= ~(1 << x))
#define ToggleBitOf(var, x) 			(var ^= 1 << x)

// Events list
#define EVENT_CAN_RX_IT							SetBit(0)

// Function prototype
void BSP_Led_Write(uint8_t state);
void BSP_Led_Toggle(void);

#endif /* CONFIG_H_ */
