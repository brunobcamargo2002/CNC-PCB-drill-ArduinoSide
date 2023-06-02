
#include "axle.h"
#include "drill.h"

#define enabledPin 8

axle* X;
void setup() {
 // Definindo ambos os pinos acima como saída
  Serial.begin(9600);

  X = new axle(stepPinX, dirPinX, limitX);

  pinMode(enabledPin, OUTPUT);
  digitalWrite(enabledPin, LOW);
 }

int a =1;
 void loop() {
while(a){
   X->move(50, DOWN);
   //X->move(50,DOWN);
   a=0;
   }

 }
  