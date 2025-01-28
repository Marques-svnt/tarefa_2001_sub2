#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"

// Definição das cores:
#define BRANCO 200, 200, 200

// Delay de controle da animação
#define DELAY_MS 250

// Endereço dos LEDs que serão acesos na animação de cada  letra
const uint8_t leds_L[] = {0, 1, 2, 3, 4, 5, 14, 15, 24};
const uint8_t leds_U[] = {0, 1, 2, 3, 4, 5, 9, 10, 14, 15, 19, 20, 24};
const uint8_t leds_C[] = {0, 1, 2, 3 4, 5, 14, 15, 20, 21, 22, 23, 24};
const uint8_t leds_A[] = {0, 4, 5, 9, 10, 11, 12, 13, 14, 15, 19, 20, 21, 22, 23, 24};
const uint8_t leds_S[] = {0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15, 19, 20, 21, 22, 23, 24};

const uint8_t leds_CORACAO[] = {2, 6, 8, 10, 14, 15, 17, 19, 21, 23}

void light_up_leds(const uint8_t *led_positions, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        npSetLED(led_positions[i], BRANCO);
    }
    npWrite();
    sleep_ms(DELAY_MS);
    npClear();
    npWrite();
}

void ani_L()
{
    light_up_leds(leds_L, sizeof(leds_L) / sizeof(leds_L[0]));
}

void ani_U()
{
    light_up_leds(leds_U, sizeof(leds_U) / sizeof(leds_U[0]));
}

void ani_C()
{
    light_up_leds(leds_C, sizeof(leds_C) / sizeof(leds_C[0]));
}

void ani_A()
{
    light_up_leds(leds_A, sizeof(leds_A) / sizeof(leds_A[0]));
}

void ani_S()
{
    light_up_leds(leds_S, sizeof(leds_S) / sizeof(leds_S[0]));
}

void ani_CORACAO()
{
    light_up_leds(leds_CORACAO, sizeof(leds_CORACAO) / sizeof(leds_CORACAO[0]));
}

void ani_06()
{
    ani_L();
    sleep_ms(DELAY_MS);
    ani_U();
    sleep_ms(DELAY_MS);
    ani_C();
    sleep_ms(DELAY_MS);
    ani_A();
    sleep_ms(DELAY_MS);
    ani_S();
    sleep_ms(DELAY_MS);
    ani_CORACAO();
    sleep_ms(DELAY_MS);
}
