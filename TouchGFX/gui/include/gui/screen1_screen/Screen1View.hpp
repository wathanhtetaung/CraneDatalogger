#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    //int uint16_t value;
    virtual void newADCValue(int val);
    virtual int getADCValue();

    virtual void analogUpdate_ADC1(uint16_t value);
    virtual void analogUpdate_ADC3(uint16_t value);

protected:
};

#endif // SCREEN1VIEW_HPP
