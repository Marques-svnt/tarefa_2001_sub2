#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"

// Definição da cor vermelha em 80% do brilho (255 * 0.8 = 204).
#define VERMELHO 204, 0, 0

// Definição do número de LEDs e pino.
#define LED_COUNT 25

void ani_tecla_c() {

    int j = 0;
    for (j = 0; j < LED_COUNT; j++) {
        npSetLED(j, VERMELHO);
    }
    npWrite();
}
