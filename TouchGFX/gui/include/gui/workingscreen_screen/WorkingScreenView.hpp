#ifndef WORKINGSCREENVIEW_HPP
#define WORKINGSCREENVIEW_HPP

#include <gui_generated/workingscreen_screen/WorkingScreenViewBase.hpp>
#include <gui/workingscreen_screen/WorkingScreenPresenter.hpp>

class WorkingScreenView : public WorkingScreenViewBase
{
public:
    WorkingScreenView();
    virtual ~WorkingScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void newAngleValue(double val);
    virtual void newLoadValue(double val);
    virtual void newRadiusValue(double val);
    virtual void newSWLValue(double val);
    virtual void SetOverload(bool state);
    virtual void SetAngleLimit(bool state);
    virtual void SetATBLimit(bool state);
    virtual void SetBypass(bool state);

protected:
};

#endif // WORKINGSCREENVIEW_HPP
