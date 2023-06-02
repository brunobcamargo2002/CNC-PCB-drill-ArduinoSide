#include "step_motor.h"

stepMotor::stepMotor(int stepPIN, int dirPIN):stepPin(stepPIN), dirPin(dirPIN){
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}


void stepMotor::setDir(bool clockwise){
  if(clockwise) 
    digitalWrite(dirPin, HIGH); 
  else 
    digitalWrite(dirPin, LOW);
}

void stepMotor::step(){
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(1000); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(1000);
    }

void stepMotor::steps(int numSteps, bool clockwise){
  setDir(clockwise);
  for(int x = 0; x < numSteps; x++)
    step();
}

void stepMotor::move(float milimeters, bool clockwise){
  int numSteps = int(milimeters/milimetersPerStep);
  steps(numSteps, clockwise);
  delay(1000);            
}