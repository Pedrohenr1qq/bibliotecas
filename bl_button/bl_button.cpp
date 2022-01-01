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
