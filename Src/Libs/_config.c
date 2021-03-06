/*
 * _config.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Puja
 */

#include <Libs/_config.h>

void BSP_Led_Write(uint8_t state) {
	HAL_GPIO_WritePin(BSP_LED_GPIO_Port, BSP_LED_Pin, state);
}

void BSP_Led_Toggle(void) {
	HAL_GPIO_TogglePin(BSP_LED_GPIO_Port, BSP_LED_Pin);
}
