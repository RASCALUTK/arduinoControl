
#include "control.h"

relay::relay(int p) {
  onOff = false;
  pin = p;
  pinMode(pin, OUTPUT);
  set(0);
  return;
}

void relay::set(int x) {
  // I am using the normally open relay pins
  // that is the reason for this code
  
  if (x == 1) {
    // connecting the pin to HIGH will turn it off    
    onOff = true;
    digitalWrite(pin, HIGH);
    return;
  } else {
    //also making it low HIGH turn it off
    onOff = false;
    digitalWrite(pin, LOW);
  }
  return;
  
}

