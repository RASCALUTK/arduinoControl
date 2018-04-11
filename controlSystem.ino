
#include "control.h"
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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

void setup() {
  noInterrupts();// kill interrupts until everybody is set up
  //lcd.begin(16, 2);
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
  pinMode(13, OUTPUT);
  
  //while (!SerialUSB.available());
}


volatile int seconds = 0;
MAX6675 thermo = MAX6675(8,9,10);
//linAct lA = linAct(42, 43, A0);
//stepperMotor xAxis = stepperMotor(6, 10, 8, 48, 47);

void loop() {
for (int i=0; i <10; i++){
  Serial.print("sec: ");
  Serial.println(i);
  delay(1000);
}



/*
  if (SerialUSB.available()) {
    int inByte = SerialUSB.read();
    Serial.write(inByte);
   SerialUSB.println("hello from arduino");
  }
  // read from port 0, send to port 1:
  */
}

ISR(TIMER1_COMPA_vect){ 
  //Interrupt Service Routine, Timer/Counter1 Compare Match A
  seconds++;
  if(seconds >= 10) { //set to however many seconds you want
    Serial.println(micros());           // This code is what happens
    seconds = 0;                        // after 'x' seconds
    digitalWrite(13, !digitalRead(13)); //
  }
}
