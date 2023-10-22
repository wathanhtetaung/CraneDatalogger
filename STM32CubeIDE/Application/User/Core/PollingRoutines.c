/*
 * PollingRoutines.c
 *
 *  Created on: Oct 22, 2023
 *      Author: wathan
 */

#include "main.h"
#include "PollingRoutines.h"
#include "stm32f7xx_hal_dma.h"
#include "cmsis_os.h"

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern osSemaphoreId_t binarySemAnalogHandle;

uint32_t uhADCxConvertedValue[10]= {0};

void PollingInit()
{
	HAL_ADC_Start_DMA(&hadc1, uhADCxConvertedValue, 10);
	HAL_TIM_Base_Start_IT(&htim1);
}

void PollinRoutine()
{

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	osSemaphoreRelease (binarySemAnalogHandle);
}
