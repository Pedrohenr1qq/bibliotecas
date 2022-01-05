/*
 * bl_music.cpp (biblioteca para buzzer)
 * Autor: Pedro Henrique P. Silva
 * Data: 05/01/2022
 * 
 */

 #include <bl_music.h>
 #include <Arduino.h>

 buz_music::buz_music(int pin){
  _pin = pin;
  pinMode(pin,OUTPUT);
 }

 void buz_music::play_freq(int freq,int temp){
  if(freq < 0){freq = 0;}
  if(freq > 3000) {freq = 3000;}
  if(temp < 150) {temp = 150;}

  tone(_pin,freq);
  delay(temp);
  noTone(_pin);
  
 }

 void buz_music::play_esc(){
    for(int i = 0; i < 7; i++){
      tone(_pin,_esc[i]);
      delay(300);
      noTone(_pin);
    }
 }

 void buz_music::play_note(int n, int temp ) {
    if(n < 0){n = 0;}
    if(n >= 7) {n = (7 -1);}
    if(temp < 150) {temp = 150;}

    tone(_pin,_esc[n]);
    delay(temp);
    noTone(_pin);
 }
