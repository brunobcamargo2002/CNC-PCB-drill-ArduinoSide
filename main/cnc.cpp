#include "cnc.h"

CNC::CNC():
X(stepPinX, dirPinX, limitX),
Y(stepPinY, dirPinY, limitY),
Z(stepPinZ, dirPinZ, limitZ),
pcb_drill(drillPin)
{}

void CNC::coordinate_input(){

}
void CNC::go_drill(int X, int Y){
  
}