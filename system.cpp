#include "system.h"

project::project() {
  return;
}

void project::inputControl(void) {
  // serial input
  if (Serial.available() > 0 ) {
    String input = Serial.readString();
    switch (input[0]) {

      //Sensors
      //tempsensor
      case 'T' :
        Serial.println("T" + String(heatTemp.readCelsius()));
        break;

      //  currentsensor
      case 'C' : {
          ammeter.readCurrent();
          Serial.println("C" + String(ammeter.ampsRMS));
        }
        break;

      //  forcesensor
      case 'F' : {
          Serial.println("F0");
        }
        break;

      case 'X' : {
          // get number -1 0 1
          int number = (input.substring(1, input.length())).toInt();
          // turn on/off
          if (number == 0) {
        //    Serial.println("off");
            x0.pwm = 255;
            x1.pwm = 255;
            x0.enable = true;
            x1.enable = true;
            x0.enableDisable();
            x1.enableDisable();
            x0.spin();
            x1.spin();
          }
          else if (number == -1) {
            // turn off motors
            x0.enable = false;
            x1.enable = false;
            x0.enableDisable();
            x1.enableDisable();
            // change direction
            x0.dir = 1;
            x1.dir = 1;
            x0.dirChange();
            x1.dirChange();
            // set pwm
            x0.pwm = 127;
            x1.pwm = 127;
            //re enable
            x0.enable = true;
            x1.enable = true;
            x0.enableDisable();
            x1.enableDisable();
            // spin motors
            x0.spin();
            x1.spin();
          } else if (number == 1) {
          //  Serial.println("forward");
            // turn off motors
            x0.enable = false;
            x1.enable = false;
            x0.enableDisable();
            x1.enableDisable();
            // change direction
            x0.dir = 0;
            x1.dir = 0;
            x0.dirChange();
            x1.dirChange();
            // set pwm
            x0.pwm = 127;
            x1.pwm = 127;
            //re enable
            x0.enable = true;
            x1.enable = true;
            x0.enableDisable();
            x1.enableDisable();
            // spin motors
            x0.spin();
            x1.spin();
          } else {
         //   Serial.println("Error: input not corret you fucking moron");
          }
          // direction change
          // rotate if
        }
        break;

      case 'Y' : {
          // get number -1 0 1
          int number = (input.substring(1, input.length())).toInt();
          // turn on/off
          if (number == 0) {
          //  Serial.println("off");
            // set pwm
            y.pwm = 255;
            //re enable
            y.enable = true;
            y.enableDisable();
            // spin motors
            y.spin();
          }
          else if (number == -1) {
           // Serial.println("reverse");
            y.enable = false;
            y.enableDisable();
            // change direction
            y.dir = 1;
            y.dirChange();
            // set pwm
            y.pwm = 127;
            //re enable
            y.enable = true;
            y.enableDisable();
            // spin motors
            y.spin();
          } else if (number == 1) {
           // Serial.println("forward");
            y.enable = false;
            y.enableDisable();
            // change direction
            y.dir = 0;
            y.dirChange();
            // set pwm
            y.pwm = 127;
            //re enable
            y.enable = true;
            y.enableDisable();
            // spin motors
            y.spin();
          } else {
          //  Serial.println("Error: input not corret you fucking moron");
          }

        }
        break;

      case 'Z' : {
          // get number -1 0 1
          int number = (input.substring(1, input.length())).toInt();
          // turn on/off
          if (number == 0) {
         //   Serial.println("off");
          }
          else if (number == -1) {

         //   Serial.println("reverse");
          } else if (number == 1) {
         //   Serial.println("forward");
          } else {
           // Serial.println("Error: input not corret you fucking moron");
          }

        }
        break;

      case 'L' : {
          // get number -1 0 1
          int number = (input.substring(1, input.length())).toInt();

          // turn on/off
          if (number == 0) {
         //   Serial.println("off");
            imd.off();
          }
          else if (number == -1) {
         //   Serial.println("reverse");
            imd.on();
            imd.reverse();
          } else if (number == 1) {
         //   Serial.println("forward");
            imd.on();
            imd.forward();
          } else {
           // Serial.println("Error: input not corret you fucking moron");
          }

        }
        break;

      case 'H' : {
          // get number  0 1
          int number = (input.substring(1, input.length())).toInt();
          // turn on/off
          if (number == 0) {
            Serial.println("off");
          } else if (number == 1) {
            Serial.println("heater on");
          } else {
            Serial.println("Error: input not corret you fucking moron");
          }
        }
        break;


      //unrecognized input
      default :
        Serial.println("INPUT ERROR : " + input);
        break;
    }

  }
  return;
}


void project::xAxis(int num) {

  if ( abs(num) == 255) {

    x0.enable = 0;
    x1.enable = 0;

  }
  else if (num > 0) {

    x0.dir = 1;
    x1.dir = 1;

  }
  else {

    x0.dir = 0;
    x1.dir = 0;

  }



  x1.pwm = abs(num);
  x0.pwm = abs(num);

  x1.spin();
  x0.spin();


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

