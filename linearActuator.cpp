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
  hB->off();
  return;
}
void linAct::forward() {
  if (potVal != maxVal) {
    hB->forward();
  }
  return;
}

void linAct::reverse() {
  if (potVal != minVal) {
    hB->reverse();
  }
  return;
}

