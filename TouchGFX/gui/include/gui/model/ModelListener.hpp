#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <touchgfx/hal/Types.hpp>
#include "main.h"

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    virtual void newADCValue(int val) {}
    virtual void analogUpdate_ADC1(uint16_t value) {}
    virtual void analogUpdate_ADC3(uint16_t value) {}
    virtual void newAngleValue(double val) {}
    virtual void newLoadValue(double val) {}
    virtual void newRadiusValue(double val) {}
    virtual void newSWLValue(double val) {}
    virtual void SetOverload(bool state) {}
    virtual void SetAngleLimit(bool state) {}
    virtual void SetATBLimit(bool state) {}
    virtual void SetBypass(bool state) {}

    void bind(Model* m)
    {
        model = m;
    }

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
