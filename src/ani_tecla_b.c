#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"

//Cor azul na intensidade de 100%
#define Azul 0, 0, 255

// Definição do número de LEDs e pino.
#define LED_COUNT 25

void ani_tecla_b() {
    int i = 0;
    for (i=0; i < LED_COUNT; i++){
        npSetLED(i, Azul);
    }
    npWrite();
}