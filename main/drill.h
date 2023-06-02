#ifndef DRILL_H
#define DRILL_H

#include <Arduino.h>

//Drill Pin
#define drillPin 12

class drill{
  private:
    int turnPin;
  public:
    drill(int turnPIN);
    void turnOn();
    void turnOff();
};

#endif

