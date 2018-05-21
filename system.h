#include "control.h"
#include "sensors.h"

#ifndef system_h
#define system_h

class project {
  public:

    //all parts needed as of now
    //   relay pump;
     relay heater = relay(25);
    //(int pinE, int pinD, int pinPulse, int limSwiMax, int limSwiMin)
    stepperMotor x0 = stepperMotor(30, 32, 4, 37, 38);
    stepperMotor x1 = stepperMotor(30, 32, 13, 39, 40);
    stepperMotor y = stepperMotor(33, 34, 10, 41, 42);
    stepperMotor z = stepperMotor(35, 36, 7, 43, 44);
    //  stepperMotor x1;
    //   stepperMotor y;
    //  stepperMotor z;
    linAct imd = linAct( 22, 23, A15, 24);
    //linAct(int pinA, int pinB, int pinC, int pinD)
    // pinA  = forward
    // pinB = reverse
    // pin C = analog pin
    // pin D =  enable
    MAX6675 heatTemp = MAX6675(45, 46, 47);
    //  forceSensor bitForce = forceSensor() ;
    //  forceSensor holdertemp;
    wattMeter ammeter = wattMeter(A0, true);

    project();

    String axisCoords();
    String forces();
    String powerlevels();

    void inputControl(void);
    void xAxis(int num);
    void yAxis(int num);
    void zAxis(int num);
    void xOne(int num);
    void xZero(int num);
    void vfdControl(String command);
    void heaterControl(String command);
    void linActControl(String command);
    void thermoControl(String command);
    void pumpControl(String command);
    void forceControl(String command);


};


#endif
