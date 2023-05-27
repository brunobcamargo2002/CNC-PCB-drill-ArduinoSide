
#include <ezButton.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Step Pins
#define stepPinX 2
#define stepPinY 3
#define stepPinZ 4

//Dir Pins
#define dirPinX 5 
#define dirPinY 6
#define dirPinZ 7

//Limit Pins
#define limitX 9
#define limitY 10
#define limitZ 11

#define enabledPin 8
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class stepMotor{
  private:
    int stepPin;
    int dirPin;
  
  public:
    stepMotor(int stepPIN, int dirPIN):stepPin(stepPIN), dirPin(dirPIN){
      pinMode(stepPin, OUTPUT);
      pinMode(dirPin, OUTPUT);
    };
    void setDir(bool clockwise){if(clockwise) digitalWrite(dirPin, HIGH); else digitalWrite(dirPin, LOW);};
    void step(){
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(1000); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(1000);
    }
    void steps(int numSteps, bool clockwise){
      setDir(clockwise);
      for(int x = 0; x < numSteps; x++)
        step();
    }
    
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class axle{
  private:
    stepMotor motor;
    ezButton limitSwitch;
  public:
    axle(int stepPIN, int dirPIN, int limitPIN):motor(stepPIN, dirPIN), limitSwitch(limitPIN){
      limitSwitch.setDebounceTime(50);
    };
    bool returnOrigen(){
      int state;
      motor.setDir(HIGH);
      while(1){
        limitSwitch.loop();
        state = limitSwitch.getState();
        if(state == HIGH)
          motor.step();
        else
          return true;
      }
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

axle* X;
void setup() {
 // Definindo ambos os pinos acima como saída
  Serial.begin(9600);

  X = new axle(stepPinX, dirPinX, limitX);

  pinMode(enabledPin, OUTPUT);
  digitalWrite(enabledPin, LOW);
 }


 void loop() {
   X->returnOrigen();
 }
  