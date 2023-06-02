#include "drill.h"

drill::drill(int turnPIN): turnPin(turnPIN){
  pinMode(turnPin, OUTPUT);
}

void drill::turnOn(){
  digitalWrite(turnPin, HIGH);
}

void drill::turnOff(){
  digitalWrite(turnPin, LOW);
}
