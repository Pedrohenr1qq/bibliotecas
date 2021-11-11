/*
 * c_ultra.cpp (usar o sensor de distancia ultrassonico)
 * 
 * autor: Pedro Henrique P. S.
 * 
 * novembro,2021
 */

#include "c_ultra.h"

ultra::ultra(int echo, int trig){
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  _echo = echo;
  _trig = trig;
  digitalWrite(trig,LOW);
}


unsigned long ultra::c_distance(){
  digitalWrite(_trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig,LOW);
  tempo = pulseIn(_echo,HIGH);
  return tempo;
}

void ultra::distancia_cm(){
  distance = c_distance()/58.82;
  Serial.println(distance);
  return distance;

}
void ultra::distancia_mm(){
  distance = c_distance()/5.882;
  Serial.println(distance);
}

void ultra::distancia_pl(){
  distance = c_distance()/149.40;
  Serial.println(distance);
}

void ultra::distancia_ps(){
  distance = c_distance()/1792.83;
  Serial.println(distance);
}
