#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"

// Definição da cor do led (azul)
#define AZUL_INTENSO 0, 0, 255

// Delay de controle da animação
#define DELAY_MS 250

// Endereço dos LEDs que serão acesos na animação de cada  letra
const uint8_t leds_B[] = {0, 1, 2, 3, 4, 5, 9, 11, 12, 14, 15, 19, 20, 21, 22, 23, 24};
const uint8_t leds_R[] = {0, 4, 5, 8, 10, 11, 12, 14, 15, 19, 20, 21, 22, 23, 24};
const uint8_t leds_U[] = {0, 1, 2, 3, 4, 5, 9, 10, 14, 15, 19, 20, 24};
const uint8_t leds_N[] = {0, 4, 5, 8, 9, 10, 12, 14, 15, 16, 19, 20, 24};
const uint8_t leds_A[] = {0, 4, 5, 9, 10, 11, 12, 13, 14, 15, 19, 20, 21, 22, 23, 24};

void light_up_leds(const uint8_t *led_positions, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        npSetLED(led_positions[i], AZUL_INTENSO);
    }
    npWrite();
    sleep_ms(DELAY_MS);
    npClear();
    npWrite();
}

void ani_B()
{
    light_up_leds(leds_B, sizeof(leds_B) / sizeof(leds_B[0]));
}

void ani_R()
{
    light_up_leds(leds_R, sizeof(leds_R) / sizeof(leds_R[0]));
}

void ani_U()
{
    light_up_leds(leds_U, sizeof(leds_U) / sizeof(leds_U[0]));
}

void ani_N()
{
    light_up_leds(leds_N, sizeof(leds_N) / sizeof(leds_N[0]));
}

void ani_A()
{
    light_up_leds(leds_A, sizeof(leds_A) / sizeof(leds_A[0]));
}

// Função que realiza a animação das letras B, R, U, N, A nos LEDs (pisca-pisca)
void ani_05()
{
    ani_B();
    sleep_ms(DELAY_MS);
    ani_R();
    sleep_ms(DELAY_MS);
    ani_U();
    sleep_ms(DELAY_MS);
    ani_N();
    sleep_ms(DELAY_MS);
    ani_A();
    sleep_ms(DELAY_MS);
}
