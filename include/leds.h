#ifndef leds_H
#define leds_H

#include "pico/stdlib.h" 

//Declaração das funções dos leds
void npInit(uint pin);
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);
void npClear();
void npWrite();

#endif