
#include "control.h"

linAct::linAct(int pinA, int pinB, int pinC, int pinD) {
  Serial.print("setup start");
  pinPot = pinC;
  pin1 = pinA;
  pin2 = pinB;
  hB = new hBridge(pin1, pin2, pinD);
  minVal = 216;
  maxVal = 806;
  off();
  readVal();
  Serial.print("setup complete");
}

void linAct::printVal(){
  readVal();
  Serial.println(potVal);
  return;
}
void linAct::off() {
  // uses the hBridge function
  hB->off();
  return;
}

void linAct::readVal() {
  potVal = analogRead(pinPot);
  return;
}
void linAct::forward() {
  potVal = analogRead(pinPot);
  if (potVal != maxVal) {
    // uses the hBridge function
    hB->forward();
  }
  return;
}

void linAct::reverse() {
  potVal = analogRead(pinPot);
  if (potVal != minVal) {
    // uses the hBridge function
    hB->reverse();
  }
  return;
}

void linAct::toMin() {
  while (potVal != minVal) {
    forward();    
  }
  off();
  return;
}
void linAct::toMax() {
  while (potVal != maxVal) {
    reverse();
  }
  off();
  return;
}

