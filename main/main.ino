
#include "cnc.h"
#include "axle.h"


#define enabledPin 8

CNC* cnc;

void setup() {
 // Definindo ambos os pinos acima como saída
  
  cnc = new CNC();
  //delay(500);
  pinMode(enabledPin, OUTPUT);
  digitalWrite(enabledPin, LOW);
 }

 void loop() {
   cnc->go_origin_first();
   cnc->main_menu();
 }
  