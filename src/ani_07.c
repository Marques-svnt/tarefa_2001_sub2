#include <stdio.h>
#include "pico/stdlib.h"
#include "leds.h"
#include "buzzer.h"

// Definição das cores
#define VERMELHO 255, 0, 0
#define VERDE 0, 255, 0
#define AZUL 0, 0, 255

// Configuração de tempo entre frames
#define FRAME_DELAY 300

void ani_07() {
    // Inicializa o buzzer e os LEDs
    buzzer_init();
    npClear();

    // Frame 1: Acende LEDs nos cantos e buzzer
    npSetLED(0, VERMELHO); // LED canto superior esquerdo
    npSetLED(4, VERDE);    // LED canto superior direito
    npSetLED(20, AZUL);    // LED canto inferior esquerdo
    npSetLED(24, VERMELHO); // LED canto inferior direito
    npWrite();
    buzz(500, 200); // Frequência de 500Hz por 200ms
    sleep_ms(FRAME_DELAY);

    // Frame 2: Acende LEDs intermediários
    npClear();
    npSetLED(1, VERDE);
    npSetLED(3, VERDE);
    npSetLED(21, AZUL);
    npSetLED(23, AZUL);
    npWrite();
    buzz(600, 200); // Frequência de 600Hz por 200ms
    sleep_ms(FRAME_DELAY);

    // Frame 3: Acende LEDs centrais
    npClear();
    npSetLED(2, AZUL);   // LED central superior
    npSetLED(12, VERDE); // LED central
    npSetLED(22, VERMELHO); // LED central inferior
    npWrite();
    buzz(700, 200); // Frequência de 700Hz por 200ms
    sleep_ms(FRAME_DELAY);

    // Frame 4: Todos os LEDs acendem juntos
    npClear();
    for (int i = 0; i < 25; i++) {
        npSetLED(i, VERMELHO); // Todos os LEDs em vermelho
    }
    npWrite();
    buzz(800, 300); // Frequência de 800Hz por 300ms
    sleep_ms(FRAME_DELAY);

    // Limpa LEDs e desliga o buzzer
    npClear();
    npWrite();
    buzzer_stop();
}
