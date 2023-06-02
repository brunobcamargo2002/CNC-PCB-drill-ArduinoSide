#ifndef AXLE_H
#define AXLE_H

#include <Arduino.h>

#include "step_motor.h"
#include <ezButton.h>
//Limit Pins
#define limitX 9
#define limitY 10
#define limitZ 11

#define UP 0
#define DOWN 1
#define LEFT 1 
#define RIGHT 0

class axle{
  private:
    stepMotor motor;
    ezButton limitSwitch;
  public:
    axle(int stepPIN, int dirPIN, int limitPIN);
    bool returnOrigen();
    void move(float milimeters, bool clockwise);
};

#endif