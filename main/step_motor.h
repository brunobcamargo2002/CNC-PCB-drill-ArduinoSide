#ifndef STEP_MOTOR_H
#define STEP_MOTOR_H

#include <Arduino.h>

//Step Pins
#define stepPinX 2
#define stepPinY 3
#define stepPinZ 4

//Dir Pins
#define dirPinX 5 
#define dirPinY 6
#define dirPinZ 7

#define milimetersPerStep 0.04 //1 revolution: 200 steps and moves 8mm(tr8) 8mm/200steps

class stepMotor{
  private:
    int stepPin;
    int dirPin;
  
  public:
    stepMotor(int stepPIN, int dirPIN);
    void setDir(bool positive);
    void step();
    void steps(int numSteps, bool positive);
    void move(float milimeters);
};
#endif