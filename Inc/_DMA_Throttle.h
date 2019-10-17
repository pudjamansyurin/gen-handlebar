/*
 * _DMA_ADC.h
 *
 *  Created on: Sep 24, 2019
 *      Author: Puja
 */

#ifndef DMA_ADC_H_
#define DMA_ADC_H_

#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdint.h>

#define THROTTLE_BUFFER_SIZE 		100
#define MCU_RPM_MAX				 			10000

void Throttle_DMA_Init(void);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);

#endif /* DMA_ADC_H_ */
