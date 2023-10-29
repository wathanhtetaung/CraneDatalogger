#include <gui/workingscreen_screen/WorkingScreenView.hpp>
#include <gui/workingscreen_screen/WorkingScreenPresenter.hpp>
#include <stdio.h>

WorkingScreenPresenter::WorkingScreenPresenter(WorkingScreenView& v)
    : view(v)
{

}

void WorkingScreenPresenter::activate()
{

}

void WorkingScreenPresenter::deactivate()
{

}

void WorkingScreenPresenter::newAngleValue(double val)
{
	//printf("updated new AngleValue@WorkingScreenPresenter\r\n");
	view.newAngleValue(val);
}

void WorkingScreenPresenter::newLoadValue(double val)
{
	//printf("new LoadValue updated@WorkingScreenPresenter\r\n");
	view.newLoadValue(val);
}

void WorkingScreenPresenter::newRadiusValue(double val)
{
	//printf("new RadiusValue updated@WorkingScreenPresenter\r\n");
	view.newRadiusValue(val);
}

void WorkingScreenPresenter::newSWLValue(double val)
{
	//printf("new SWLValue updated@WorkingScreenPresenter\r\n");
	view.newSWLValue(val);
}

void WorkingScreenPresenter::SetOverload(bool state)
{
	//printf("new SWLValue updated@WorkingScreenPresenter\r\n");
	view.SetOverload(state);
}

void WorkingScreenPresenter::SetAngleLimit(bool state)
{
	//printf("new SWLValue updated@WorkingScreenPresenter\r\n");
	view.SetAngleLimit(state);
}

void WorkingScreenPresenter::SetATBLimit(bool state)
{
	//printf("new SWLValue updated@WorkingScreenPresenter\r\n");
	view.SetATBLimit(state);
}

void WorkingScreenPresenter::SetBypass(bool state)
{
	//printf("new SWLValue updated@WorkingScreenPresenter\r\n");
	view.SetBypass(state);
}

