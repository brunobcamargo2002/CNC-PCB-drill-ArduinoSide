
#include "cnc.h"


#define enabledPin 8

CNC* cnc;
void setup() {
 // Definindo ambos os pinos acima como saída
  Serial.begin(9600);

  cnc = new cnc();

  pinMode(enabledPin, OUTPUT);
  digitalWrite(enabledPin, LOW);
 }

 void loop() {

 }
  