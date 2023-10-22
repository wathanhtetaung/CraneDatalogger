#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stm32f7xx_hal.h"
#include <cmsis_os.h>
//#include "PollingRoutines.h"
#include "main.h"
#include <stdio.h>

extern int angle_value;
extern uint16_t uhADCxConvertedValue[10];
extern osSemaphoreId_t binarySemAnalogHandle;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	analogUpdate();
	if (binarySemAnalogHandle != NULL)
	{
		if(osSemaphoreAcquire(binarySemAnalogHandle, 100) == osOK) //osSemaphoreAcquire osSemaphoreWait
		{
			analogUpdate();
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

void Model::analogUpdate()
{
	uint16_t sum = 0;
	for(int i =0; i<10;i++)
	{
		sum += uhADCxConvertedValue[i];
		//printf("ADC value = %d\r\n",uhADCxConvertedValue[i]);
		HAL_Delay(50);

	}
	printf("Avg ADC value = %d\r\n",sum/10);

	modelListener->analogUpdate(sum/10);
}

