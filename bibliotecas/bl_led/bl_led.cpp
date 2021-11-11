/*
 * bl_led.cpp (bliblioteca para leds)
 * 
 * autor: Pedro Henrique P. S.
 * 
 * novembro, 2021
 * 
 */

#include "bl_led.h"
#include "Arduino.h"

bl_l::bl_l(int pin){
  this-> _p = pin;
}

void bl_l::ligar(){
  digitalWrite(_p,HIGH);
}

void bl_l::desligar(){
  digitalWrite(_p,LOW);
}

void bl_l::acender_t(int t){
  ligar();
  delay(t);
  desligar();
}

void bl_l::apagar_t(int t){
  desligar();
  delay(t);
  ligar();
}

void bl_l::p(int t, int i){
  for(int n = 0; n <= i; n++){
    ligar();
    delay(t);
    desligar();
    delay(t);
  }
}
