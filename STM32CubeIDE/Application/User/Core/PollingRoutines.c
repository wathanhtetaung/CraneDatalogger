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
#include <stdbool.h>

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc3;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern osSemaphoreId_t binarySemAnalogHandle;

uint32_t uhADC1ConvertedValue[10]= {0};
uint32_t uhADC3ConvertedValue[10]= {0};
bool ATB_Status = false;
bool Bypass_Status = false;
extern bool Overload_Status;
extern bool HighAngle_Status;

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


	/* read Bypass IO and update */
	if (HAL_GPIO_ReadPin(GPIOI,GPIO_PIN_0) == true)
	{
		Bypass_Status = true;
		//printf("Bypass activated\r\n");
	}
	else
	{
		Bypass_Status = false;
	}

	/* read ATB IO and update to GUI */
	if (HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_7) == true)
	{
		ATB_Status = true;
		//printf("ATB activated\r\n");
	}
	else
	{
		ATB_Status = false;
	}

	/* to manage cutoff output for overload & ATB */
	if (((ATB_Status == true) && Bypass_Status == false) || ((Overload_Status == true) && Bypass_Status == false))
	{
		/* Output cutoff signal for overload and ATB*/
		HAL_GPIO_WritePin(GPIOH,GPIO_PIN_6,GPIO_PIN_SET);
		//printf("output cutoff signal for overload & ATB\r\n");

	}
	else
	{
		/* Output cutoff signal for overload and ATB*/
		HAL_GPIO_WritePin(GPIOH,GPIO_PIN_6,GPIO_PIN_RESET);
		//printf("Released cutoff signal for overload & ATB\r\n");
	}

	/* to manage cutoff output for high angle limit */
	if ((HighAngle_Status == true) && Bypass_Status == false)
	{

		/* Output cutoff signal for overload and ATB*/
		HAL_GPIO_WritePin(GPIOI,GPIO_PIN_3,GPIO_PIN_SET);
		//printf("ouput high angle cutoff\r\n");

	}
	else
	{
		/* Output cutoff signal for overload and ATB*/
		HAL_GPIO_WritePin(GPIOI,GPIO_PIN_3,GPIO_PIN_RESET);
		//printf("Released high angle cutoff\r\n");
	}

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	//printf("osSemaphore callback\r\n");
	osSemaphoreRelease (binarySemAnalogHandle);
}

void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
	printf("ADC conv error\r\n");
}

