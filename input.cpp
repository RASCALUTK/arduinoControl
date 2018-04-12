#include "control.h"

void inputControl(String input) {
  char  firstLetter = input[0];
  switch (firstLetter) {

    //stepper
    case 'S' :
      Serial.println("stepper");
      break;

    //Linear actuator
    case 'L' :
      Serial.println("linear actuator");
      break;

    //pump
    case 'P' :
      Serial.println("pump");
      break;

    //heater
    case 'H' :
      Serial.println("heater");
      break;

    //tempsensor
    case 'T' :
      Serial.println("Temp");
      break;

    //un recognized input
    default :
      Serial.println("INPUT ERROR : " + input);
      break;
  }

  return;
}


void stepperControl(String command){
    


  
}

