#include "control.h"

linAct::linAct(int pinA, int pinB, int pinC) {
  pinPot = pinC;
  pin1 = pinA;
  pin2 = pinB;
  hB = new hBridge(pin1, pin2);
  off();
  potVal = analogRead(pinPot);
}

void linAct::off() {
  // uses the hBridge function
  hB->off();
  return;
}

void linAct::forward() {
  if (potVal != maxVal) {
    // uses the hBridge function
    hB->forward();
  }
  return;
}

void linAct::reverse() {
  if (potVal != minVal) {
    // uses the hBridge function
    hB->reverse();
  }
  return;
}

void linAct::toMin() {
  while (potVal != minVal) {
    reverse();
  }
  off();
  return;
}
void linAct::toMax() {
  while (potVal != maxVal) {
    forward();
  }
  off();
  return;
}

