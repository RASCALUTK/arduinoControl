#include "control.h"

relay::relay(int p) {
  onOff = false;
  pin = p;
  pinMode(pin, OUTPUT);
  return;
}

void relay::set(int x) {
  if (x == 1) {
    onOff = true;
    digitalWrite(pin, LOW);
    return;
  } else {
    onOff = false;
    digitalWrite(pin, HIGH);
  }
  return;
}

