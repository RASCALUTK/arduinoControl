
#include <LiquidCrystal.h>
#include <stdio.h>
#include <Arduino.h>
#include"sensors.h"

// this is neccesary so it does not add multiple times
#ifndef control_h
#define control_h


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

class hBridge {
  public:
    int pin1, pin2;
    hBridge(int pinA, int pinB);
    void off();
    void forward();
    void reverse();

};

class linAct {
  public:
    int potVal, pwm, minVal, maxVal;
    int pinPot, pin1, pin2;
    //constructor
    linAct(int pinA, int pinB, int pinC);
    void off();
    void forward();
    void reverse();
    // toMin and toMax will stop all code until they reahc their end
    void toMax();
    void toMin();
  private:
    // uses hBridge class since it uses hbridge
    hBridge* hB;
};

class relay {
  public:
    //constructor]
    relay(int p);
    int pin;
    bool onOff;
    void set(int x);
};


// ends the if definiton statement
#endif
