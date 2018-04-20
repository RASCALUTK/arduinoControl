#include "control.h"

void inputControl(String input) {
  char  firstLetter = input[0];
  switch (firstLetter) {

    //stepper
    case 'S' :
      Serial.println("stepper");
      stepperControl(input);
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


void stepperControl(String command) {
  int temp;
  // get name
  temp = command.indexOf('_');
  String sTemp = command.substring(0, temp);
  command = command.substring(temp, command.length());
  Serial.println("name " + sTemp);

  // get on off setting
  temp = command.indexOf('_');
  String onOff = command.substring(0, temp);
  command = command.substring(temp, command.length());
 Serial.println("on/Off: " + onOff);
  // get pwm speed
  temp = command.indexOf('_');
  String pwm = command.substring(0, temp);
  command = command.substring(temp, command.length());
 Serial.println("pwm: " + pwm);
  // get direction
  temp = command.indexOf('_');
  String dir = command.substring(0, temp);
  command = command.substring(temp, command.length());
 Serial.println("direction: " + dir);
 
  if (sTemp = "SX0") {
   x0.pwm = pwm.toInt();
   x0.dir = dir.toInt;
   xo.enable = onOff.toInt();
  } else if (sTemp = "SX1") {
    //x1.pwm = pwm.toInt();
    //x1.dir = dir.toInt;
    //x1.enable = onOff.toInt();
  } else if (sTemp  = "SY") {
    //y.pwm = pwm.toInt();
    //y.dir = dir.toInt;
    //y.enable = onOff.toInt();
  } else if (sTemp  = "SZ") {
    //z.pwm = pwm.toInt();
    //z.dir = dir.toInt;
    //z.enable = onOff.toInt();
  } else {
    Serial.println("ERROR Name not recognized:" + sTemp);
  }
  return;
}

void vfdControl(String command) {
  // remove name

  //on off

  // direction

  //jog

  //speed

  return;
}

void heaterControl(String command) {
  // remove name

  // on off

  return;
}

void linActControl(String command) {
  // remove name

  // on off
  return;
}

void thermoControl(String command) {
  // remove name
  // read and send temp
  return;
}

void pumpControl(String command) {
  // remove name
  // on off
  return;
}

void forceControl(String command) {
  //remove name
  // return force val
  return;
}


