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
  List<List<int>> coordinates;
  int current_x, current_y;
public:
  CNC();
  void main_menu();
  int coordinate_input();
  void insert_coordinate_menu();
  void start_drill();
  void go_drill(int x, int y);
  void return_origin();

  
  void printCoord();
};


#endif