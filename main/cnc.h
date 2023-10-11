#ifndef CNC_H
#define CNC_H

#include <Arduino.h>
#include <List.hpp>

#include "axle.h"
#include "drill.h"


class CNC{
private:
  axle X, Y, Z;
  drill pcb_drill;
  List<List<float>> coordinates;
  float current_x, current_y;
public:
  CNC();
  void main_menu();
  float coordinate_input();
  void insert_coordinate_menu();
  void start_drill();
  void go_drill(float x, float y);
  void go_origin_first();
  void go_origin();
  void return_start_point();
};


#endif