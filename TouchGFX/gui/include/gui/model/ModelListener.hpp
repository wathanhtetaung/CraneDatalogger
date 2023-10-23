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

    void bind(Model* m)
    {
        model = m;
    }

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
