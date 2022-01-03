/*
 * bl_button.cpp (biblioteca para  buttons) -- resolver o problema de debounce
 * Autor: Pedro Henrique Pereira da Silva
 * 31 de deze,bro de 2021
 * 
 */

 #include <Arduino.h>
 #include <bl_button.h>

 bl_but::bl_but(int pin){
    _pin = pin;
    pinMode(pin,INPUT_PULLUP);
 }

 int bl_but::getStateButton(){
  button = digitalRead(this->_pin);
  int b = button;
  return b;
 }
  
 
 void bl_but::clique(void f()){
    button = digitalRead(_pin);
    if( (button == 0) && (lastStateButton == 1)){
      lastStateButton = 0;
      del = millis();
    }

    if( (millis() - del > debounce) && (lastStateButton == 0)){
      lastStateButton = 1;
      f();
    }
 }

 // but_main
but_main::but_main(int pin){
  _pin = pin;
  pinMode(pin,INPUT_PULLUP);
}

byte but_main::mult_func(const int temp){
  #define debounce 50
  const int temp_reset = temp;
  
  static bool lastStateButton;
  static unsigned long delay_btt =0;
  static unsigned long bttPressed;
  static byte acion = 0;

  bool stateButton;
  byte currentFunc;

  currentFunc = 0;

  if(millis() - delay_btt > debounce){
    stateButton = digitalRead(_pin);
    if(!stateButton && (stateButton != lastStateButton)){
      delay_btt = millis();
      bttPressed = millis();
      acion = 1;
    }

    if((acion == 1) && ((millis() - bttPressed) > temp_reset)){
      acion = 0;
      currentFunc = 2;
    }

    if(stateButton && (stateButton != lastStateButton)){
      delay_btt = millis();
      if(acion == 1){
        currentFunc = 1;
      }
      acion = 0;
    }

    lastStateButton = stateButton;
    
  }

  return currentFunc;
  
}
  
 
