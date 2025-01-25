#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pico/cyw43_arch.h"
#include "ani_00.h"
#include "ani_asterisco.h"
#include "teclado.h"
#include "buzzer.h"

// Função principal
int main() {
    stdio_init_all();
    teclado();

    while (true) {
        char key = pico_keypad_get_key();

        // Controle baseado em teclas específicas
        if (key == '0') {
            ani_00();
        } else if (key == '1') {
            //Animação da tecla 1
        } else if (key == '2') {
            //Animação da tecla 2
        } else if (key == '3') {
            //Animação da tecla 3
        } else if (key == '4') {
            ani_04();
        } else if (key == '5') {
            //Animação da tecla 5
        } else if (key == '6') {
            //Animação da tecla 6
        } else if (key == '7') {
            //Animação da tecla 7
        } else if (key == 'A') {
            //Animação da tecla A
        } else if (key == 'B') {
            //Animação da tecla B
        } else if (key == 'C') {
            //Animação da tecla C
        } else if (key == 'D') {
            //Animação da tecla D
        } else if (key == '#') {
            //Animação da tecla #
        } else if (key == '*') {
            ani_asterisco();  // Chama a funcionalidade da tecla '*'
        } else {
            printf("Essa tecla não possui animação");
        }
    }
    return 0;
}
