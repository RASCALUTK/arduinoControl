

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
    int potVal, pwm, minVal,maxVal;
    int pinPot, pin1, pin2;
    linAct(int pinA, int pinB, int pinC);
    void off();
    void forward();
    void reverse();
  private:
    hBridge* hB;
};

class relay {
  public:
    relay(int p);
    int pin;
    bool onOff;
    void set(int x);
};


// ends the if definiton statement
#endif
