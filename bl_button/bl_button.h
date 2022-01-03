/*
 * bl_button.h (biblioteca para  buttons) -- resolver o problema de debounce
 * Autor: Pedro Henrique Pereira da Silva
 * 31 de deze,bro de 2021
 * 
 */
#ifndef bl_button
#define bl_button

#include <Arduino.h>

class bl_but{

  public:
    bl_but(int pin);
    void clique(void f());
    int getStateButton();
    
  private:
    int _pin;
    int button;
    int lastStateButton = 1;
    unsigned long del;
    unsigned long debounce = 300;
    
};

class but_main{
  public:
  but_main(int pin);
  byte mult_func(const int temp);
  

  private:
  int _pin;
};

#endif
