#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stm32f7xx_hal.h"
#include <cmsis_os.h>
//#include "PollingRoutines.h"
#include "main.h"
#include <stdio.h>

extern int angle_value;
extern uint16_t uhADC1ConvertedValue[10];
extern uint16_t uhADC3ConvertedValue[10];
extern osSemaphoreId_t binarySemAnalogHandle;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	osStatus_t status;
	//analogUpdate();
	analogUpdate_ADC1();
	analogUpdate_ADC3();

	if (binarySemAnalogHandle != NULL)
	{
		status = osSemaphoreAcquire(binarySemAnalogHandle, 100);
		if(status == osOK) //osSemaphoreAcquire osSemaphoreWait
		{
			printf("ADCx values updated\r\n");
			analogUpdate_ADC1();
			analogUpdate_ADC3();

		}
		else if(status == osErrorTimeout)
		{
			//printf("OS Timeout\r\n");
		}
		else
		{
			printf("OS error\r\n");
		}
	}

	newADCValue(angle_value);
}

void Model::newADCValue(int val)
{
	for (int i =0; i <10; i++)
	{
		angle_value++;
	}
	if (angle_value == 900)
	{
		angle_value =0;
	}
	modelListener->newADCValue(angle_value);
}

void Model::analogUpdate_ADC1()
{
	uint16_t sum_ADC1 = 0;

	for(int i =0; i<10;i++)
	{
		sum_ADC1 += uhADC1ConvertedValue[i];
		//printf("ADC value = %d\r\n",uhADC1ConvertedValue[i]);
		//HAL_Delay(50);
	}

	printf("Avg ADC1 value = %d\r\n",sum_ADC1/10);

	modelListener->analogUpdate_ADC1(sum_ADC1/10);

}

void Model::analogUpdate_ADC3()
{
	uint16_t sum_ADC3 = 0;

	for(int i =0; i<10;i++)
	{
		sum_ADC3 += uhADC3ConvertedValue[i];
		//printf("ADC value = %d\r\n",uhADC1ConvertedValue[i]);
		//HAL_Delay(50);

	}

	printf("Avg ADC3 value = %d\r\n",sum_ADC3/10);

	modelListener->analogUpdate_ADC3(sum_ADC3/10);

}
