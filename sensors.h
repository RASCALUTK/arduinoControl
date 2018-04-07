
#ifndef sensors_h
#define sensors_h

#include "control.h"

class rotEncBut {
  public:
    int count, state, lastState, outButt, outputA, outputB;
    //consturctor
    rotEncBut(int pinSwi, int pinA, int pinB);
    //spin code
    void encoder();
    //botton on or off
    void toggle();
    bool onOff;
};

class tempSense {
  public:
    int pinA, PinB, temp;
    tempSense(int pin1, int pin2);
    void tempRead();
};

class forceSensor {
  public:
    int pinA, PinB, force;
    forceSensor(int pin1, int pint2);
    void forceRead();
};

class wattMeter {
  public:
    int sensorOut, current, powerVA;
    int mVperAmp;
    double voltage,vRMS,ampsRMS;
    bool ac;
    wattMeter(int pinA, bool type);
    void readCurrent();
    void calculatePower();
    float getVPP();
};

#endif
