
#include "control.h"

hBridge::hBridge(int pinA, int pinB, int pinC) {
  pinE = pinC;
  pinMode(pinE, OUTPUT);
  pin1 = pinA;
  pinMode(pin1, OUTPUT);
  pin2 = pinB;
  pinMode(pin2, OUTPUT);
  off();
  return;
}

void hBridge::on() {
  digitalWrite(pinE, HIGH);
  return;
}

void hBridge::off() {
  digitalWrite(pinE, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  return;
}

void hBridge::forward() {
  digitalWrite(pin2, LOW);
  digitalWrite(pin1, HIGH);
  on();
  return;
}

void hBridge::reverse() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  on();
}

