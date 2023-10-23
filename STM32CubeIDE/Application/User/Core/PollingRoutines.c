/*
 * PollingRoutines.c
 *
 *  Created on: Oct 22, 2023
 *      Author: wathan
 */

#include "main.h"
#include "PollingRoutines.h"
#include "stm32f7xx_hal_dma.h"
#include "stm32f7xx_hal_adc.h"
#include "cmsis_os.h"
#include <stdio.h>

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc3;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern osSemaphoreId_t binarySemAnalogHandle;

uint32_t uhADC1ConvertedValue[10]= {0};
uint32_t uhADC3ConvertedValue[10]= {0};

void PollingInit()
{
	HAL_Delay(500);
	HAL_StatusTypeDef status;
	status = HAL_ADC_Start_DMA(&hadc1, uhADC1ConvertedValue, 10);
	if (status != HAL_OK)
	{
		printf("ADC1 start Error\r\n");
	}

	status = HAL_ADC_Start_DMA(&hadc3, uhADC3ConvertedValue, 10);
	//printf("polling initiated\r\n");
	if (status != HAL_OK)
	{
		printf("ADC3 start Error\r\n");
	}

	status = HAL_TIM_Base_Start_IT(&htim1);
	if (status == HAL_OK)
	{
		printf("timer1 OK\r\n");
	}
	else
	{
		printf("timer1 error\r\n");
	}
//	HAL_Delay(500);
//	if (HAL_TIM_Base_Start_IT(&htim2) != HAL_OK)
//	{
//		printf("timer1 error\r\n");
//	}

}

void PollingRoutine()
{

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	printf("osSemaphore callback\r\n");
	osSemaphoreRelease (binarySemAnalogHandle);
}

void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
	printf("ADC conv error\r\n");
}

