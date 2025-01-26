#ifndef ANI_02_H
#define ANI_02_H

//Declaração das funções da animação
void ani_02();
void npInit(uint pin);
void npSetLED(uint index, uint8_t r, uint8_t g, uint8_t b);
void npClear();
void npWrite();
void ani_wave_5frames();
void ani_snake_5frames();
void ani_fade_5frames();

#endif