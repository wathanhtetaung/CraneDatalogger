#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void newADCValue(int val);
    int setADC(int val);
    void analogUpdate();
    void analogUpdate_ADC1();
    void analogUpdate_ADC3();

    void tick();
protected:
    ModelListener* modelListener;
    //int ADC_VAL;
};

#endif // MODEL_HPP
