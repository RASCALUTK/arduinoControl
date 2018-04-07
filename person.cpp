#include "control.h"

 person::person(int a,String n,char g){
 age = a;
 firstName = n;
 gender = g;
  return;
 }

void person::getName(){
Serial.println(firstName);
return;
}
int person::returnAge(){
  return age;
}

