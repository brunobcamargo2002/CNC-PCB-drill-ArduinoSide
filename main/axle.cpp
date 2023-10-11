#include "axle.h"

axle::axle(int stepPIN, int dirPIN, int limitPIN):motor(stepPIN, dirPIN), limitSwitch(limitPIN){
  limitSwitch.setDebounceTime(50);
};

bool axle::returnOrigin(){
  int state;
  motor.setDir(false);
  while(1){
    limitSwitch.loop();
    state = limitSwitch.getState();
    if(state == HIGH)
        motor.step();
    else
      return true;
  }
}

void axle::move(float milimeters){
  motor.move(milimeters);            
}