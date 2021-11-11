/*
 * c_ultra.h (usar o sensor de distancia ultrassonico)
 * 
 * autor: Pedro Henrique P. S.
 * 
 * novembro,2021
 */

#ifndef c_ultra.h
#define c_ultra.h

#include "Arduino.h"

class ultra{
 public:
    ultra(int echo,int trig);
    void distancia_cm();
    void distancia_mm();
    void distancia_pl();
    void distancia_ps();
    double distance;
    
  private:
    int _echo,_trig;
    unsigned long tempo;
    unsigned long c_distance();
};

#endif
