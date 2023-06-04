#ifndef CNC_H
#define CNC_H

#include <Arduino.h>

#include "axle.h"
#include "drill.h"

class CNC{
private:
  axle X, Y, Z;
  drill pcb_drill;
public:
  CNC();
  void coordinate_input();
  void go_drill(int X, int Y);
};


#endif