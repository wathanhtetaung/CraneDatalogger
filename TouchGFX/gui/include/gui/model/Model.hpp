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
    void newAngleValue(int val);
    void newLoadValue(int val);
    void newRadiusValue(int val);
    void SetOverload(double val);
    void SetAngleLimit();
    void SetATBLimit(bool state);
    void SetBypass(bool state);

    void tick();
protected:
    ModelListener* modelListener;
    int ADC1_VAL,ADC3_VAL;
    double Angle_Deg,Load_Ton;
    double Boom_Length = 12.2;
    double Radius_m;
    double angle_radians;
    double SlewOffset = 1.2;
    bool OL_state,AL_state;

};

#endif // MODEL_HPP
