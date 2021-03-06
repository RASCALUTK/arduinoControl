
#include "system.h"
//USBHost usb;
void setup() {
  noInterrupts();// kill interrupts until everybody is set up
  Serial.begin (9600);
  Serial.println("hello");
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
  pinMode(53, OUTPUT);
  //while (!SerialUSB.available());
}

volatile int seconds = 0;
project ice;

void loop() {
  if (Serial.available() > 0) {
    String in = Serial.readString();
    //ice.inputControl(in);
  }
  //analogWrite(4,2);
  ice.x0.pwm = 5;
  ice.x0.enable = 1;
  ice.x0.enableDisable();
  ice.x0.dir = 1;
  ice.x0.dirChange();
  ice.x0.spin();
  delay(3000);
  ice.x0.stopM();
  delay(1000);
  ice.x0.dir = 0;
  ice.x0.dirChange();
  ice.x0.spin();
  delay(3000);
}

ISR(TIMER1_COMPA_vect) {
  //Interrupt Service Routine, Timer/Counter1 Compare Match A
  seconds++;
  if (seconds >= 10) { //set to however many seconds you want
    Serial.println("10");           // This code is what happens
    seconds = 0;                        // after 'x' seconds
    digitalWrite(53, !digitalRead(53)); //
  }
}
