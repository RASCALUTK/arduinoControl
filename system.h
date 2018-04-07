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
    stepperMotor xAxis;
    stepperMotor yAxis;
    stepperMotor zAxis;
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
