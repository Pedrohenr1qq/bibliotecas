/*
 * bl_music.h (biblioteca para buzzer)
 * Autor: Pedro Henrique P. Silva
 * Data: 05/01/2022
 * 
 */

#ifndef bl_music
#define bl_music

#include <Arduino.h>

class buz_music{
  public:
    buz_music(int pin);
    void play_freq(int freq,int temp = 500);
    void play_esc();
    void play_note(int n, int temp = 500);
    const int c = 261;
    const int d = 293;
    const int e = 329;
    const int f = 349;
    const int g = 392;
    const int a = 440;
    const int b = 494;

  private:
    int _pin;
    int _esc[7] = {c,d,e,f,g,a,b};
};


#endif
