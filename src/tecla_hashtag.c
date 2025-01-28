#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"


// Definição da cor branca com 20% de intensidade (255 *0.2 = 51), vamos usar 48 devido ao wokwi não interpretar corretamente o 51
#define BRANCO 48, 48, 48

// Definição do número de LEDs e pino.
#define LED_COUNT 25

void tecla_hashtag()
{
    int i = 0;
    for (i = 0; i < LED_COUNT; i++)
    {
        npSetLED(i, BRANCO);
    }
    npWrite();
}