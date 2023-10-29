#ifndef WORKINGSCREENPRESENTER_HPP
#define WORKINGSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class WorkingScreenView;

class WorkingScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    WorkingScreenPresenter(WorkingScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();
    virtual void newAngleValue(double val);
    virtual void newLoadValue(double val);
    virtual void newRadiusValue(double val);
    virtual void newSWLValue(double val);
    virtual void SetOverload(bool state);
    virtual void SetAngleLimit(bool state);
    virtual void SetATBLimit(bool state);
    virtual void SetBypass(bool state);

    virtual ~WorkingScreenPresenter() {}

private:
    WorkingScreenPresenter();

    WorkingScreenView& view;
};

#endif // WORKINGSCREENPRESENTER_HPP
