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
  //return_origin();
}

void CNC::main_menu(){
  String option="";
  while(1){
    while(Serial.available()==0){
    }
    delay(500);
    while(Serial.available()>0)
      option+=(char)Serial.read();
    switch(option.toInt()){
      case 1:{insert_coordinate_menu();}break;
      case 2:{
        if(!coordinates.isEmpty())
          start_drill();}break;
      case 3:{go_origin_first();}break;
    }
    option = "";
  }

}

void CNC::insert_coordinate_menu(){
  float x, y;
  Serial.write("1");
  coordinates.clear();
  while(1){
    x = coordinate_input();
    if(((int)x)==-1001){

      break;
    }
    else if(x<-XMAX || x>XMAX){
      Serial.write("0");
      coordinates.clear();
      break;
    }
    Serial.write("1");
    y = coordinate_input();
    if(y<-YMAX || y>YMAX){
      Serial.write("0");
      coordinates.clear();
      break;
    }
    Serial.write("1");
    List<float> * coord = new List<float>;
    coord->add(*(new float(x)));coord->add(*(new float(y)));
    coordinates.add(*coord);
  }
}

float CNC::coordinate_input(){
  String coordinate="";
  //Serial.println("1");
  while(1){
    while(Serial.available()==0){
    }
    delay(500);
    while(Serial.available()>0)
      coordinate+=(char)Serial.read();
    return coordinate.toFloat();
  }


}

void CNC::start_drill(){

  if(coordinates.isEmpty())
    Serial.println("There are no points to drill");
  else{
    
    for(int i=0 ; i<coordinates.getSize(); i++){
      List<float> aux = coordinates.getValue(i);
      go_drill(aux.getValue(0), aux.getValue(1));
    }
    go_origin();
  }

}


void CNC::go_drill(float x, float y){
  float move_x=x-current_x;
  float move_y=y-current_y;
  X.move(move_x);
  Y.move(move_y);
  current_x = x;
  current_y = y;
  pcb_drill.turnOn();
  delay(2000);
  Z.move(4);
  delay(500);
  Z.move(-4);
  pcb_drill.turnOff();
}


void CNC::go_origin_first(){
  return_start_point();
  X.move(XMAX);
  Y.move(YMAX);
  Z.move(31);
  current_x=0;
  current_y=0;
}

void CNC::go_origin(){
  X.move(-current_x);
  Y.move(-current_y);
  current_x=0;
  current_y=0;
}


void CNC::return_start_point(){
  X.returnOrigin();
  Y.returnOrigin();
  Z.returnOrigin();
}
/*
void CNC::remove_coordinate(){
  String numero="";
  int num=0;
  while(1){
    printCoord();
    Serial.println("Type the coordinate that you want to remove: ");
    while(Serial.available()==0){}
    while(Serial.available()>0){
      numero+=(char)Serial.read();
    }
    num = numero.toInt();
    if(num==-1)
      break;
    else if(num<0 && num>coordinates.getSize()){
      
    }

  }

}*/
