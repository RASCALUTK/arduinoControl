
#include "control.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String x = "N";
String y = "N";
String z = "N";

void setup() {
  lcd.begin(16, 2);
  lcd.print("X    Y     Z");
  Serial.begin (9600);
  // Reads the initial state of the outputA
}

//constructor for rotary encoder with Button
// rotEncBut(int pinSwi, int pinA, int pinB);
//these are globals 
rotEncBut rotX(51, 50, 49);
rotEncBut rotY(48, 47, 46);

void loop() {
  Serial.println(rotX.count);
  rotX.encoder();
  rotY.encoder();
  lcd.setCursor(0, 0);
  lcd.print("X:" + x +  " Y:" + y + " Z:" + z);
  lcd.setCursor(0, 1);
  lcd.print( String(rotX.count) + " " + String (rotX.count ));
}




