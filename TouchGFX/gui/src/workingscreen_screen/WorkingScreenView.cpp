#include <gui/workingscreen_screen/WorkingScreenView.hpp>
#include <stdio.h>

WorkingScreenView::WorkingScreenView()
{

}

void WorkingScreenView::setupScreen()
{
    WorkingScreenViewBase::setupScreen();
}

void WorkingScreenView::tearDownScreen()
{
    WorkingScreenViewBase::tearDownScreen();
}

void WorkingScreenView::newAngleValue(double val)
{
	//Unicode::UnicodeChar a[] = {0x00B0,0};
	//printf("new angle value updated@WorkingScreenView %d\r\n", val);
    //Unicode::snprintf(AngleValueBuffer1, ANGLEVALUEBUFFER1_SIZE, "%d %s", val,a);
    Unicode::snprintfFloat(AngleValueBuffer, ANGLEVALUE_SIZE, "%.1f", val);
    AngleValue.invalidate();
}

void WorkingScreenView::newLoadValue(double val)
{
	//printf("new LoadValue updated@WorkingScreenView %d\r\n", val);
    Unicode::snprintfFloat(LoadValueBuffer, LOADVALUE_SIZE, "%.1f", val);
    LoadValue.invalidate();
}

void WorkingScreenView::newRadiusValue(double val)
{
	//printf("new RadiusValue updated@WorkingScreenView %d\r\n", val);
    Unicode::snprintfFloat(RadiusValueBuffer, LOADVALUE_SIZE, "%.1f", val);
    RadiusValue.invalidate();
}

void WorkingScreenView::newSWLValue(double val)
{
	//printf("new SWLValue updated@WorkingScreenView %1f\r\n", val);
	Unicode::snprintfFloat(SWLValueBuffer, SWLVALUE_SIZE, "%.1f", val);
    SWLValue.invalidate();
}

void WorkingScreenView::SetOverload(bool state)
{
	Overloaded.setVisible(state);
	Overloaded.invalidate();
}

void WorkingScreenView::SetAngleLimit(bool state)
{
	AngleLimitButton_A.setVisible(state);
	AngleLimitButton_A.invalidate();
}

void WorkingScreenView::SetATBLimit(bool state)
{
	ATBButton_A.setVisible(state);
	ATBButton_A.invalidate();
}

void WorkingScreenView::SetBypass(bool state)
{
	BypassButton_A.setVisible(state);
	BypassButton_A.invalidate();
}
