#include "control.h"

stepperMotor::stepperMotor(int pinE, int pinD, int pinPWM, int limSwiMax, int limSwiMin) {
  //direction pin
  pinDir = pinD;
  pinMode(pinDir, OUTPUT);
  //enable pin
  pinEnable = pinE;
  pinMode(pinEnable, OUTPUT);
  //pwm pin TEST THIS ON multiple motors
  pinPwm = pinPWM;
  pinMode(pinPwm, OUTPUT);
  pwm = 0;
  //limit swithces
  pinLimMin = limSwiMin;
  pinLimMax = limSwiMax;
  pinMode (pinLimMin, INPUT);
  pinMode (pinLimMax, INPUT);
  dir = true;
  enable = false;
  //checks to see if it is on the end
  isMinMax();

  return;
}

void stepperMotor::spin() {
  isMinMax();
  if (isMax || isMin) {
    return;
  }
}

void stepperMotor::isMinMax() {
  if (pinLimMax == HIGH) {
    isMax = true;
    return;
  } else if (pinLimMin == HIGH) {
    isMin = true;
    return;
  }
  isMax = false;
  isMin = false;
}

void stepperMotor::setMin() {
  isMinMax();
  if (isMin) {
    return;
  }
}

void stepperMotor::setMax() {
  isMinMax();
  if (isMax) {
    return;
  }
}


