#include "control.h"
#include "sensors.h"

#ifndef system_h
#define system_h

class project {
  public
  
  //all parts needed as of now
    relay drillMotor;
    relay pump;
    relay heater;
    stepperMotor x0;
    stepperMotor x1;
    stepperMotor y;
    stepperMotor z;
    linAct holder;
    tempSense heatTemp;
    forceSensor bitForce;
    forceSensor holdertemp;
    wattMeter meter;
    
    project();
    String axisCoords();
    String forces();
    String powerlevels();
    
    
};


#endif
