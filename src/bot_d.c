#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"

// Definição da cor verde com 50% de intensidade (255 *0.5 = 127.5)
#define VERDE 0, 128, 0

// Definição do número de LEDs e pino.
#define LED_COUNT 25

void bot_d()
{
    int i = 0;
    for (i = 0; i < LED_COUNT; i++)
    {
        npSetLED(i, VERDE);
    }
    npWrite();
}