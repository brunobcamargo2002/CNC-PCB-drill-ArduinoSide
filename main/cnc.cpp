#include "cnc.h"

CNC::CNC():
X(stepPinX, dirPinX, limitX),
Y(stepPinY, dirPinY, limitY),
Z(stepPinZ, dirPinZ, limitZ),
pcb_drill(drillPin),
current_x(0),
current_y(0),
coordinates(true){
  Serial.begin(9600);
}

void CNC::insert_coordinate_menu(){
  int x, y;
  while(1){
    Serial.println("Type -1 to stop the insertion.");
    Serial.println("Type -2 to cancel all the insertions.");
    Serial.println("\nInsert the X coordinate: ");
    x = coordinate_input();
    if(x==-1)
      break;
    else if(x==-2){
      for(int i=0 ; i<coordinates.getSize();i++)
        coordinates.getValue(i).clear();
      break;
    }
    else{
      if(x>XMAX){
        Serial.println("Out of range.");
        Serial.println("Type a valid number.");
        while(x<=0 && x>XMAX)
          x=coordinate_input();
      }
    }
    Serial.println("\n Insert the Y coordinate: ");
    y = coordinate_input();
    if(y==-1)
      break;
    else if(y==-2){
      coordinates.clear();
      break;
    }
    else{
      if(y>YMAX){
        Serial.println("Out of range.");
        Serial.println("Type a valid number.");
        while(x<=0 && y>YMAX)
          y=coordinate_input();
      }
    }
    List<int> * coord = new List<int>(true);
    coord->add(*(new int(x)));coord->add(*(new int(y)));
    coordinates.add(*coord);
  }
}

int CNC::coordinate_input(){
  String coordinate="";
  while(1){
    while(Serial.available()==0){
    }
    delay(500);
    while(Serial.available()>0)
      coordinate+=(char)Serial.read();
    return coordinate.toInt();
  }


}

void CNC::start_drill(){
  return_origin();
  if(coordinates.isEmpty())
    Serial.println("There are no points to drill");
  else{
    List<int> aux;
    for(int i=0 ; i<coordinates.getSize(); i++){
      aux = coordinates.getValue(i);
      go_drill(aux.getValue(0), aux.getValue(1));
    }
  }

}

void CNC::go_drill(int x, int y){
  int move_x=x-current_x;
  int move_y=y-current_y;
  X.move(move_x);
  Y.move(move_y);
}

void CNC::printCoord(){
  int x, y;
  for(int i=0; i<coordinates.getSize(); i++){
    List<int> aux =coordinates.getValue(i);
    String text = String("Coordinate ")+String(i+1)+String(":")+String(" x= ")+String(aux.getValue(0))+String(" y= ")+String(aux.getValue(1));
    Serial.println(text);
  }
}

void CNC::return_origin(){
  X.returnOrigin();
  Y.returnOrigin();
  Z.returnOrigin();
}
