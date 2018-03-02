#include "control.h"

hBridge::hBridge(int pinA, int pinB) {

  pin1 = pinA;
  pinMode(pin1, OUTPUT);
  pin2 = pinB;
  pinMode(pin2, OUTPUT);
  off();
  return;
}

void hBridge::off() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  return;
}
void hBridge::forward() {
  off();
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  return;
}
void hBridge::reverse() {
  off();
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  return;

}

