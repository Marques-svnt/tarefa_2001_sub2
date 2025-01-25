#ifndef ANI_00_H
#define ANI_00_H

//Declaração das funções da animação
void ani_00();
void npInit(uint pin);
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);
void npClear();
void npWrite();

#endif