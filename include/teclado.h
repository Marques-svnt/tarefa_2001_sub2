#ifndef TECLADO_H
#define TECLADO_H

//Declaração das funções do teclado
void pico_keypad_init(uint columns[4], uint rows[4], char matrix_values[16]);
char pico_keypad_get_key(void);
void teclado();

#endif