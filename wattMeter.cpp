#include "sensors.h"

wattMeter::wattMeter(int pinA, bool type) {
  sensorOut = pinA;
  mVperAmp = 185;
  ac = type;
  pinMode(sensorOut, INPUT);
  voltage = 0;
  vRMS = 0;
  ampsRMS = 0;

}

void wattMeter::readCurrent() {
  voltage = getVPP();
  vRMS = (voltage / 2.0) * 0.707;
  ampsRMS = (vRMS * 1000) / mVperAmp;
}

void wattMeter::calculatePower() {

}
/*

  voltage = getVPP();
  vRMS = (voltage / 2.0) * 0.707;
  vmpsRMS = (vRMS * 1000) / mVperAmp;
  Serial.print(AmpsRMS);
  Serial.println(" Amps RMS");
*/


float wattMeter::getVPP() {
  float result;

  int readValue;             //value read from the sensor
  int maxValue = 0;          // store max value here
  int minValue = 1024;          // store min value here

  uint32_t start_time = millis();
  while ((millis() - start_time) < 1000) //sample for 1 Sec
  {
    readValue = analogRead(sensorOut);
    // see if you have a new maxValue
    if (readValue > maxValue)
    {
      //record the maximum sensor value
      maxValue = readValue;
    }
    if (readValue < minValue)
    {
      //record the maximum sensor value
      minValue = readValue;
    }
  }

  // Subtract min from max
  result = ((maxValue - minValue) * 5.0) / 1024.0;

  return result;
}


