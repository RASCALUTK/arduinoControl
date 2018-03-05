
#include "control.h"

stepperMotor::stepperMotor(int pinE, int pinD, int pinPulse, int limSwiMax, int limSwiMin) {
  //direction pin
  pinDir = pinD;
  pinMode(pinDir, OUTPUT);
  
  //enable pin
  pinEnable = pinE;
  pinMode(pinEnable, OUTPUT);
  
  //pwm pin TEST THIS ON multiple motors
  pinPul = pinPulse;
  pinMode(pinPul, OUTPUT);
  pwm = 0;
  
  //limit swithces
  pinLimMin = limSwiMin;
  pinLimMax = limSwiMax;
  pinMode (pinLimMin, INPUT);
  pinMode (pinLimMax, INPUT);
  
  dir = true;
  enable = false;
  enableDisable();
  //checks to see if it is on the end
  isMinMax();
  return;

}

void stepperMotor::spin() {
  isMinMax();
  if ((isMax && dir ) || (isMin && !dir)) {
    return;
  }
  enable = true;
  enableDisable();
  analogWrite(pinPul, pwm);
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
  // set dir
  //while()
  //spin()
}

void stepperMotor::setMax() {
  isMinMax();
  if (isMax) {
    return;
  }
  //set dir
  //while()
  //spin()
}

void stepperMotor::pwmSet(int newPwm) {
  pwm = newPwm;
}


void stepperMotor::enableDisable() {
  if (enable) {
    digitalWrite(pinEnable, LOW);
  } else {
    digitalWrite(pinEnable, HIGH);
  }
}

// does a step
void stepperMotor::stepM() {
  isMinMax();
  if ((isMax && dir ) || (isMin && !dir)) {
    return;
  }
  enable = true;
  enableDisable();
  if (pinPul == HIGH) {
    digitalWrite(pinPul, LOW);
  } else {
    digitalWrite(pinPul, HIGH);

  }
}

// this is a really shitty way of doing this but it does work.
void stepperMotor::badPwm() {
  stepM();
  delay(delayTime);
  stepM();
  return;
}


