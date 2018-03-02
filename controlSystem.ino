
#include "control.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*
//examples of how to initialize a new componant

//relay(int pin)
relay motor = relay(33);

//stepperMotor(int pinEnable, int pinDisable, int pinPul, int limitSwitchMax, int limSwiMin);
stepperMotor xAxis = stepperMotor(50, 49, 11, 48, 47);

//hBridge(int pinA, int pinB)
hBridge hB = hBridge(46, 45);

//linAct(int pinA, int pinB, int pinC)
//pinC is an analog pin
linAct lA = linAct(44, 43, A0);

//rotEncButt(int pinSwi, int pinA, int pinB)
rotEncBut counter = rotEncBut(42,41,40);
*/

//USBHost usb;

void setup() {
  lcd.begin(16, 2);
  Serial.begin (9600);
//  pinMode (x, INPUT);

}

stepperMotor xAxis = stepperMotor(6, 10, 8, 48, 47);

void loop() {
Serial.print("Does this work");
xAxis.stepM();
delay(30);
}




