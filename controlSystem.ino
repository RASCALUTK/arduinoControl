
#include "control.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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

//USBHost usb;
linAct lA = linAct(44, 43, A0,11);

void setup() {
  lcd.begin(16, 2);
  Serial.begin (9600);
  Serial.println("hello");
 // SerialUSB.begin(9600);
  //while (!SerialUSB.available());
}

//linAct lA = linAct(42, 43, A0);
//stepperMotor xAxis = stepperMotor(6, 10, 8, 48, 47);

void loop() {
 // 
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
delay(60000);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
delay(60000);

/*
  if (SerialUSB.available()) {
    int inByte = SerialUSB.read();
    Serial.write(inByte);
   SerialUSB.println("hello from arduino");
  }
  // read from port 0, send to port 1:
  */
}




