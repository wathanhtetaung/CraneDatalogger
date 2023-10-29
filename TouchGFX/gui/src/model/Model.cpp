#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stm32f7xx_hal.h"
#include <cmsis_os.h>
//#include "PollingRoutines.h"
#include "main.h"
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>

extern int angle_value;
extern uint16_t uhADC1ConvertedValue[10];
extern uint16_t uhADC3ConvertedValue[10];
extern osSemaphoreId_t binarySemAnalogHandle;
extern bool ATB_Status;
extern bool Bypass_Status;

struct LoadData {
    double radius; // Radius in meters
    double loadCapacity; // Safe load capacity in kilograms
};

// Function to find the working load based on the provided radius with linear interpolation
double findWorkingLoad(const std::vector<LoadData>& loadChart, double radius) {
    for (size_t i = 0; i < loadChart.size() - 1; ++i) {
        if (loadChart[i].radius <= radius && radius <= loadChart[i + 1].radius) {
            double load1 = loadChart[i].loadCapacity;
            double load2 = loadChart[i + 1].loadCapacity;
            double radius1 = loadChart[i].radius;
            double radius2 = loadChart[i + 1].radius;
            return load1 + (load2 - load1) * (radius - radius1) / (radius2 - radius1);
        }
    }
    return 0.0; // Return 0 if the radius is not found in the chart
}

std::vector<LoadData> loadChart = {
    {3.6, 50.0},
    {4.0, 50.0},
    {4.5, 43.4},
    {5.0, 36.5},
    {6.0, 27.6},
    {7.0, 22.1},
    {8.0, 18.4},
    {9.0, 15.7},
    {10.0, 13.7},
    {11.3, 11.7}
};

double map(long x, long in_min, long in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min +1) / (in_max - in_min +1) + out_min;
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	osStatus_t status;
	//analogUpdate();
	analogUpdate_ADC1();
	analogUpdate_ADC3();

    //double radius;
	//printf("radius = %d\r\n", Radius_m);
    double workingLoad = findWorkingLoad(loadChart, Radius_m);

	modelListener->newSWLValue(workingLoad);

    if (workingLoad > 0)
    {
    	//printf("SafeWorkingLoad = %.1f\r\n", workingLoad);
    }
    else
    {
        //printf("Working load data not found for the specified radius\r\n");
        workingLoad = 0;
    }

	if (binarySemAnalogHandle != NULL)
	{
		status = osSemaphoreAcquire(binarySemAnalogHandle, 100);
		if(status == osOK) //osSemaphoreAcquire osSemaphoreWait
		{
			//printf("ADCx values updated\r\n");
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
	newAngleValue(ADC1_VAL);
	newLoadValue(ADC3_VAL);
	SetAngleLimit();
	SetOverload(workingLoad);

	//printf("ATB = %d\r\n", ATB_Status);
	SetATBLimit(ATB_Status);
	SetBypass(Bypass_Status);

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

void Model::newAngleValue(int val)
{
//	int new_AngleValue =0;
//	if (uhADC1ConvertedValue[0] < 10)
//	{
//		new_AngleValue = 30;
//	}
//	else
//	{
//		new_AngleValue = 50;
//	}

	Angle_Deg = map(val, 0, 4095, 0.0, 100.0);

	//printf("angle degree = %.1f deg\r\n", Angle_Deg);
	modelListener->newAngleValue(Angle_Deg);

    angle_radians = Angle_Deg * (M_PI / 180.0);

	Radius_m = Boom_Length * cos(angle_radians);
	//Radius_m = Boom_Length * tan(Angle_Deg);

	//Radius_m = Boom_Length * Angle_Deg;

	Radius_m = Radius_m + SlewOffset;
	modelListener->newRadiusValue(Radius_m);

	//printf("new Angle value updated\r\n");
}

void Model::newLoadValue(int val)
{
//	int new_AngleValue =0;
//	if (uhADC3ConvertedValue[0] < 10)
//	{
//		new_AngleValue = 30;
//	}
//	else
//	{
//		new_AngleValue = 50;
//	}

	Load_Ton = map(val, 0, 4095, 0, 100);

	modelListener->newLoadValue(Load_Ton);
	//printf("new LoadValue updated\r\n");
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

	//printf("Avg ADC1 value = %d\r\n",sum_ADC1/10);
	sum_ADC1 = sum_ADC1/10;
	ADC1_VAL = map(sum_ADC1, 0, 4095, 0, 4095);
	modelListener->analogUpdate_ADC1(ADC1_VAL);
	//modelListener->analogUpdate_ADC1(sum_ADC1/10);

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

	//printf("Avg ADC3 value = %d\r\n",sum_ADC3/10);
	sum_ADC3 = sum_ADC3/10;
	ADC3_VAL = map(sum_ADC3, 0, 4095, 0, 4095);
	modelListener->analogUpdate_ADC3(ADC3_VAL);
	//modelListener->analogUpdate_ADC3(sum_ADC3/10);

}

void Model::SetOverload(double val)
{
	if (Load_Ton > val)
	{
		OL_state = true;
	}
	else
	{
		OL_state = false;
	}
	modelListener->SetOverload(OL_state);

}

void Model::SetAngleLimit()
{
	if (Angle_Deg > 80)
	{
		AL_state = true;
	}
	else
	{
		AL_state = false;
	}
	modelListener->SetAngleLimit(AL_state);

}

void Model::SetATBLimit(bool state)
{
	//extern bool ATB_Status;
	modelListener->SetATBLimit(state);
}

void Model::SetBypass(bool state)
{
	//extern bool ATB_Status;
	modelListener->SetBypass(state);
}

