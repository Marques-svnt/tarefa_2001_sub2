#ifndef ANI_00_H
#define ANI_00_H

//Declaração das funções de buzzer
void ani_00();
void npWrite();
void npClear() ;
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);
void npInit(uint pin);

#endif