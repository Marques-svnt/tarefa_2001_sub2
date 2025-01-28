#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "leds.h"

// Definindo a quantidade de LEDs na matriz 5x5
#define NUM_LEDS 25

// Função da animação para o botão 3
void ani_03() {
    for (int i = 0; i < NUM_LEDS; i++) {
        npSetLED(i, 0, 0, 255);  // Azul
        npWrite();
        sleep_ms(100); 
    }
    npClear();
    npWrite();
    sleep_ms(500); 
}
