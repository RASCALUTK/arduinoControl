
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
  pwm = 255;

  //limit swithces
  pinLimMin = limSwiMin;
  pinLimMax = limSwiMax;
  pinMode (pinLimMin, INPUT);
  pinMode (pinLimMax, INPUT);
  isMinMax();
  dir = true;
  prevDir = dir;
  enable = false;
  enableDisable();
  //checks to see if it is on the end
  return;
}

void stepperMotor::dirChange() {
  if (dir && dir != prevDir) {
    digitalWrite(pinDir, HIGH);
  } else {
    digitalWrite(pinDir, LOW);
  }
  prevDir = dir;
  return;
}

void stepperMotor::spin() {
  isMinMax();
  if ((isMax && dir) || (isMin && !dir)) {
    digitalWrite(pinEnable, HIGH);
    return;
  }
  analogWrite(pinPul, pwm);
  return;
}
void stepperMotor::stopM() {
  digitalWrite(pinEnable, HIGH);
  return;
}

void stepperMotor::isMinMax() {
  if (digitalRead(pinLimMax) == HIGH) {
    isMax = true;
    return;
  } else if (digitalRead(pinLimMin) == HIGH) {
    isMin = true;
    return;
  }
  isMax = false;
  isMin = false;
  return;
}

void stepperMotor::setMin() {
  isMinMax();
  if (isMin) {
    return;
  }
  dir = false;
  while (!isMin) {
    spin();
  }
  return;
}

void stepperMotor::setMax() {
  isMinMax();
  if (isMax) {
    return;
  }
  dir = true;
  while (!isMax) {
    spin();
  }
  return;
}

void stepperMotor::pwmSet(int newPwm) {
  pwm = newPwm;
  return;
}


void stepperMotor::enableDisable() {
  if (enable && (!isMin || !isMax)) {
    digitalWrite(pinEnable, LOW);
  } else {
    digitalWrite(pinEnable, HIGH);
  }
  return;
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

