
#include "control.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String x = "N";
String y = "N";
String z = "N";

//constructor for rotary encoder with Button
// rotEncBut(int pinSwi, int pinA, int pinB);
//these are globals now
rotEncBut rotX = rotEncBut(51,50,49);
void setup() {
  lcd.begin(16, 2);
  lcd.print("X    Y     Z");
  Serial.begin (9600);
}

void loop() {
 Serial.println(rotX.count);
  // calls the encoder function in rotEncBut


  lcd.setCursor(0, 0);
  lcd.print("X:" + x +  " Y:" + y + " Z:" + z);
  lcd.setCursor(0, 1);
}




