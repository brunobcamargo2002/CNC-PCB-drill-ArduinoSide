#include "step_motor.h"

stepMotor::stepMotor(int stepPIN, int dirPIN):stepPin(stepPIN), dirPin(dirPIN){
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}


void stepMotor::setDir(bool positive){
  if(positive) 
    digitalWrite(dirPin, LOW); 
  else 
    digitalWrite(dirPin, HIGH);
}

void stepMotor::step(){
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(1000); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(1000);
    }

void stepMotor::steps(int numSteps, bool positive){
  setDir(positive);
  for(int x = 0; x < numSteps; x++)
    step();
}

void stepMotor::move(float milimeters){
  int numSteps = int(milimeters/milimetersPerStep);
  bool positive = true;
  if(milimeters<0){
    numSteps*=-1;
    positive = false;
  }
  steps(numSteps, positive);
  delay(1000);            
}