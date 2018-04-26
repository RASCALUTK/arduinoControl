#include "control.h"
#include "sensors.h"

#ifndef system_h
#define system_h

class project {
  public:

    //all parts needed as of now
    //vfd drillMotor;
    //   relay pump;
    //   relay heater;
    //(int pinE, int pinD, int pinPulse, int limSwiMax, int limSwiMin)
    stepperMotor x0 = stepperMotor(30, 32, 4, 48, 47);;
    //  stepperMotor x1;
    //   stepperMotor y;
    //  stepperMotor z;
    //  linAct holder;
    //  MAX6675 heatTemp;
    //  forceSensor bitForce;
    //  forceSensor holdertemp;
    //  wattMeter meter;

    project();

    String axisCoords();
    String forces();
    String powerlevels();

    void inputControl(String input);
    void stepperControl(String command);
    void vfdControl(String command);
    void heaterControl(String command);
    void linActControl(String command);
    void thermoControl(String command);
    void pumpControl(String command);
    void forceControl(String command);


};


#endif
