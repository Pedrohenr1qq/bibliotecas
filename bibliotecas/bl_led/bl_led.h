/*
 * bl_led.h (bliblioteca para leds)
 * 
 * autor: Pedro Henrique P. S.
 * 
 * novembro, 2021
 * 
 */

#ifndef bl_led
#define bl_led
#include "Arduino.h"


class bl_l{
 public:
   bl_l(int pin);
   void ligar();
   void desligar();
   void acender_t(int t);
   void apagar_t(int t);
   void p(int t, int i);
   
 private:
   int _p;
};


 #endif
