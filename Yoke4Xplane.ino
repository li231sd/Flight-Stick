#include <Joystick.h>

const int PIN_X_AXIS = A0; 
const int PIN_Y_AXIS = A1; 
const int PIN_JS_BTN = 5;  

const int PIN_R_RGHT = 2;  
const int PIN_R_CNTR = 3; 
const int PIN_R_LEFT = 4;  

Joystick_ Joystick(0x03, JOYSTICK_TYPE_JOYSTICK, 
  4, 0,                  
  true, true, false,     
  false, false, false,   
  false, false, false, false, false);

void setup() {
  pinMode(PIN_R_RGHT, INPUT_PULLUP);
  pinMode(PIN_R_CNTR, INPUT_PULLUP);
  pinMode(PIN_R_LEFT, INPUT_PULLUP);
  pinMode(PIN_JS_BTN, INPUT_PULLUP); 

  Joystick.begin();
  
  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(0, 1023);
}

void loop() {
  Joystick.setXAxis(analogRead(PIN_X_AXIS));
  Joystick.setYAxis(analogRead(PIN_Y_AXIS));
  Joystick.setButton(0, !digitalRead(PIN_R_RGHT));
  Joystick.setButton(1, !digitalRead(PIN_R_CNTR));
  Joystick.setButton(2, !digitalRead(PIN_R_LEFT));
  Joystick.setButton(3, !digitalRead(PIN_JS_BTN)); 

  delay(10); 
}