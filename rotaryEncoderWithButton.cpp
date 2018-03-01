
#include "control.h"

rotEncBut::rotEncBut(int pinSwi, int pinA, int pinB) {
  //sets all variables in the rotEncBut class
  outputB = pinB;
  outputA = pinA;
  outButt = pinSwi;
  pinMode (outputB, INPUT);
  pinMode (outputA, INPUT);
  pinMode (outButt, INPUT);
  lastState = digitalRead(outputA);
  count = 0;
  return;
}

void rotEncBut::encoder() {
  //read state
  state = digitalRead(outputA);
//compare to prevstate
  if (state != lastState) {
    if (digitalRead(outputB) != state) {
      count++;
    } else {
      count--;
    }
    Serial.print("Position: " + count);
  }
//change state
  lastState = state; 
  return;
}

void rotEncBut::toggle() {
  //checks on off
  if (digitalRead(outButt) == LOW) {
    onOff = true;
  } else {
    onOff = false;
  }
  return;
}

