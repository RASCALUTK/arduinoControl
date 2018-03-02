#include "control.h"

relay::relay(int p) {
  onOff = false;
  pin = p;
  pinMode(pin, OUTPUT);
  set(0);
  return;
}

void relay::set(int x) {
  if (x == 1) {
    // connecting the pin to ground will turn it on
    //that is strange but it does work
    onOff = true;
    digitalWrite(pin, LOW);
    return;
  } else {
    //also making it high will turn it off
    onOff = false;
    digitalWrite(pin, HIGH);
  }
  return;
}

