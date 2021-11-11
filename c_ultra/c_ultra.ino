/*
 * c_ultra (usar o sensor de distancia ultrassonico)
 * 
 * autor: Pedro Henrique P. S.
 * 
 * novembro,2021
 */

#include <c_ultra.h>
#include <bl_led.h>

bl_l led(6);

ultra s(7,8);

void setup(){
  Serial.begin(9600);
  led.desligar();
}

void loop(){
  s.distancia_cm();
  if(s.distance >= 30){
    delay(300);
    led.ligar();
  }
  else if(s.distance <30 && s.distance >= 10){
    led.p(500,1);
  }
  else{
    led.p(100,1);
  }
}
