

#include <LiquidCrystal.h>
#include <stdio.h>
#include <String.h>
#include <Arduino.h>

// this is neccesary so it does not add multiple times
#ifndef control_h
#define control_h


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

class stepperMotor {
  public:
    // pins used for motor
    int  pinDir, pinEnable, pinPwm, pinLimMin, pinLimMax;
    //variables
    int posMax, posMin, pos, pwm;
    bool dir, enable, isMax, isMin;
    stepperMotor(int pinE, int pinD, int pinPWM, int limSwiMax, int limSwiMin);
    //spins motor
    void spin();
    
    //helper functions
    void setMax();
    void setMin();
    void isMinMax();
};

class linActuator {
    int pot, pwm;
    int pinPot,pinPwm;
};

// ends the if definiton statement
#endif
