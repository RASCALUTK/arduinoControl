#include <LiquidCrystal.h>
#include <stdio.h>
#include <Arduino.h>
// this is neccesary so it does not add multiple times
#ifndef control_h
#define control_h
#include"sensors.h"
#include "max6675.h"
#include "Adafruit_TMP007.h"


class stepperMotor {
  public:
    // pins used for motor
    int  pinDir, pinEnable, pinPul, pinLimMin, pinLimMax;
    //variables
    int posMax, posMin, pos, pwm, delayTime;
    bool dir, enable, isMax, isMin, prevDir;
    stepperMotor(int pinE, int pinD, int pinPulse, int limSwiMax, int limSwiMin);
    //spins motor
    void spin();
    //helper functions
    void setMax();
    void setMin();
    void isMinMax();
    void enableDisable();
    void pwmSet(int newPwm);
    void stepM();
    void forward();
    void reverse();
    void badPwm();
    //void dirChange();
    void dirChange();
    void stopM();
};

class hBridge {
  public:
    int pin1, pin2, pinE;
    hBridge(int pinA, int pinB, int pinC);
    void off();
    void on();
    void forward();
    void reverse();

};

class linAct {
  public:
    int potVal, pwm;
    double minVal, maxVal;
    int pinPot, pin1, pin2;
    //constructor
    linAct(int pinA, int pinB, int pinC, int pinD);
    void off();
    void forward();
    void reverse();
    // toMin and toMax will stop all code until they reahc their end
    void toMax();
    void toMin();
    void readVal();
    void printVal();
    hBridge* hB;

  private:
    // uses hBridge class since it uses hbridge
};

class relay {
  public:
    //constructor]
    relay(int p);
    int pin;
    bool onOff;
    void set(int x);
};
class vfd {
  public:
    int speedPin, forwardPin, jogPin;
    vfd(int r, int j, int an);
};
// ends the if definiton statement
#endif
