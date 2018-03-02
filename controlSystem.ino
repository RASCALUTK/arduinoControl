
#include "control.h"
#include "sensors.h"

//#include <String>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

relay motor = relay(33);

 int x = 22;

//constructor for rotary encoder with Button
// rotEncBut(int pinSwi, int pinA, int pinB);
//these are globals now
void setup() {
  lcd.begin(16, 2);
  Serial.begin (9600);
  pinMode (x, INPUT);

}

  
void loop() {
  //  Serial.println(rotX.count);
  // calls the encoder function in rotEncBut
  if (digitalRead(x) == HIGH) {
    motor.set(0);
  } else {
    motor.set(1);
  }

}




