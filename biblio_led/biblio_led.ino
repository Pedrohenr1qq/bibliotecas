/*
 * bl_led (bliblioteca para leds)
 * 
 * autor: Pedro Henrique P. S.
 * 
 * novembro, 2021
 * 
 */
#include <bl_led.h>

bl_l led(7);

void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  led.desligar();
}

int tempo = 5000;

void loop() {
  // put your main code here, to run repeatedly:
  led.ligar();
  delay(tempo);
  led.desligar();
  delay(tempo);
  led.p(tempo/5,5);
}
