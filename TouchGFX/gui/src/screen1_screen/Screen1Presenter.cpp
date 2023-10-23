#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <stdio.h>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::newADCValue(int val)
{
	view.newADCValue(val);
}

void Screen1Presenter::analogUpdate_ADC1(uint16_t value)
{
	printf("go into presenter_ADC1\r\n");
	view.analogUpdate_ADC1(value);
}

void Screen1Presenter::analogUpdate_ADC3(uint16_t value)
{
	printf("go into presenter_ADC3\r\n");
	view.analogUpdate_ADC3(value);
}

