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

    void tick();
protected:
    ModelListener* modelListener;
    //int ADC_VAL;
};

#endif // MODEL_HPP
