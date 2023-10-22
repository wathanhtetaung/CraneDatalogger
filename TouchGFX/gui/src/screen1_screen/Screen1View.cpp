#include <gui/screen1_screen/Screen1View.hpp>
#include "string.h"
#include <stdio.h>

int global_val;

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    int angle_deg;
    angle_deg = getADCValue();
    newADCValue(angle_deg);

    //newADCValue(30);

    //Unicode::snprintf(angle_textBuffer, ANGLE_TEXT_SIZE, "%d", 10);
    //angle_text.invalidate();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::analogUpdate(uint16_t value)
{
	printf("update to screen done %d\r\n", value);

	memset(&textArea1Buffer,0,TEXTAREA1_SIZE);
    Unicode::snprintfFloat(textArea1Buffer, TEXTAREA1_SIZE, "%.3f", value * 0.000805664);
    textArea1.invalidate();
}

void Screen1View::newADCValue(int val)
{
	//val++;
    Unicode::snprintf(angle_textBuffer, ANGLE_TEXT_SIZE, "%d", val);
    angle_text.invalidate();
    //touchgfx_printf("newADCValue\n");
}


int Screen1View::getADCValue()
{
	//int val;
	global_val++;
	//touchgfx_printf("getADCValue\n");
	return global_val++;
}









