/*
 * _DMA_ADC.c
 *
 *  Created on: Sep 24, 2019
 *      Author: Puja
 */

#include <Drivers/_DMA_Throttle.h>

extern ADC_HandleTypeDef hadc1;
uint16_t THROTTLE_ADC_DMA_Buffer[THROTTLE_BUFFER_SIZE];
extern uint16_t DB_MCU_RPM;

void Throttle_DMA_Init(void) {
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*) THROTTLE_ADC_DMA_Buffer, THROTTLE_BUFFER_SIZE);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
	uint8_t i;
	uint16_t ADC_Average_Value;
	uint32_t tempValue = 0;

	// sum all adcBuffer sample
	for (i = 0; i < THROTTLE_BUFFER_SIZE; i++) {
		tempValue += THROTTLE_ADC_DMA_Buffer[i];
	}

	// calculate the average (max value 12 bit = 4095)
	ADC_Average_Value = (tempValue / THROTTLE_BUFFER_SIZE);

	// transform value to RPM
	DB_MCU_RPM = ADC_Average_Value * MCU_RPM_MAX / 4095;
}
