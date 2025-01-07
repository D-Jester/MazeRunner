#include <Arduino.h>
#include <global_header.h>
#include <bits/stdc++.h>

void setup()
{
  // setting up serial monitor
  Serial.begin(BAUD_RATE);
  initIRArray();
  initColour();
  initMotorDefault();
  initMotorPID(0);
}

void loop()
{
  readIRArray();
  if(!checkStopMotors()){
    if (leftDominant()) {
    runRight(0,true);
    runLeft(0,false);
  }else if (rightDominant()){
    runRight(0,false);
    runLeft(0,true);
  }else{
    runRight(0,true);
    runLeft(0,true);
  }
  }else{
    stopMotors();
  }
  delay(50);
}
