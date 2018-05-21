
#include "system.h"
int num1;
//USBHost usb;
project ice;

void setup() {
  noInterrupts();// kill interrupts until everybody is set up
  Serial.begin (9600);
  Serial.println("hello humans");
  int frequency = 1; // in hz
  //Interupt Service Routine and timer setup
  //We use Timer 1 b/c it's the only 16 bit timer
  TCCR1A = B00000000;//Register A all 0's since we're not toggling any pins
  // TCCR1B clock prescalers
  // 0 0 1 clkI/O /1 (No prescaling)
  // 0 1 0 clkI/O /8 (From prescaler)
  // 0 1 1 clkI/O /64 (From prescaler)
  // 1 0 0 clkI/O /256 (From prescaler)
  // 1 0 1 clkI/O /1024 (From prescaler)
  TCCR1B = B00001100;//bit 3 set for CTC mode, will call interrupt on counter match, bit 2 set to divide clock by 256, so 16MHz/256=62.5KHz
  TIMSK1 = B00000010;//bit 1 set to call the interrupt on an OCR1A match
  OCR1A  = (unsigned long)((62500UL / frequency) - 1UL);//our clock runs at 62.5kHz, which is 1/62.5kHz = 16us
  interrupts();//restart interrupts
  //while (!SerialUSB.available());
  
  ice.z.pwm = 255;
  ice.x0.pwm = 255;
  ice.x1.pwm = 255;
  ice.y.pwm = 255;
}
volatile int seconds = 0;
void loop() {
  ice.inputControl();

 //print Temp input for testing
Serial.println(ice.heatTemp.readFahrenheit());
 delay(1000);


}



ISR(TIMER1_COMPA_vect) {
  //Interrupt Service Routine, Timer/Counter1 Compare Match A
  seconds++;
  if (seconds >= 10) { //set to however many seconds you want
    // Serial.println("10");           // This code is what happens
    seconds = 0;                        // after 'x' seconds
    digitalWrite(53, !digitalRead(53)); //
  }
}
/*
  tempCel = temp.readCelsius();

  delay(1000);
  ice.z.dir = 0;
  ice.z.dirChange();
  ice.z.spin();
  ice.z.pwm = 127;
  ice.z.dir = 1;
  ice.z.enable = 1;
  ice.z.enableDisable();
  ice.z.dirChange();
  ice.Z.spin();
  delay(1000);
  ice.z.dir = 0;
  ice.z.dirChange();
  ice.z.spin();

*/
