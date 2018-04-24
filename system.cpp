#include "system.h"

project::project() {
  // Adafruit_TMP007 tmp(0x40);

  //x0
  /*
    vfd drillMotor;
    relay pump;
    relay heater;
    //stepperMotor(int pinE, int pinD, int pinPulse, int limSwiMax, int limSwiMin
    stepperMotor x0;
    stepperMotor x1;
    stepperMotor y;
    stepperMotor z;
    linAct holder;
    MAX6675 heatTemp;
    forceSensor bitForce;
    forceSensor holdertemp;
    wattMeter meter;
  */

  return;
}


void project::inputControl(String input) {
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


void project::stepperControl(String command) {
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
    x0.dir = dir.toInt();
    x0.enable = onOff.toInt();
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

void project::vfdControl(String command) {
  // remove name

  //on off

  // direction

  //jog

  //speed

  return;
}

void project::heaterControl(String command) {
  // remove name

  // on off

  return;
}

void project::linActControl(String command) {
  // remove name

  // on off
  return;
}

void project::thermoControl(String command) {
  // remove name
  // read and send temp
  return;
}

void project::pumpControl(String command) {
  // remove name
  // on off
  return;
}

void project::forceControl(String command) {
  //remove name
  // return force val
  return;
}
/*
  //examples of how to initialize a new componant
  //relay(int pin)
  relay motor = relay(33);
  //stepperMotor(int pinEnable, int pinDisable, int pinPul, int limitSwitchMax, int limSwiMin);
  stepperMotor xAxis = stepperMotor(50, 49, 11, 48, 47);

  //hBridge(int pinA, int pinB,int pinEnable)
  hBridge hB = hBridge(46, 45,31);

  //linAct(int pinA, int pinB, int pinC, pin pin Enable)
  //pinC is an analog pin

  //rotEncButt(int pinSwi, int pinA, int pinB)
  rotEncBut counter = rotEncBut(42,41,40);
*/

