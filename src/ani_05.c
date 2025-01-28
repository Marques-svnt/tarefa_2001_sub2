#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"

// Definição da cor do led (azul)
#define AZUL_INTENSO 0, 0, 255

// Delay de controle da animação
#define DELAY_MS 250

// Endereço dos LEDs que serão acesos
const uint8_t led_indices[] = {
    24, 15, 14, 5, 4, 23, 22, 21, 20, 19, 11, 12, 9, 0, 1, 2, 3};

// Qtd total de LEDs na lista
#define LED_COUNT (sizeof(led_indices) / sizeof(led_indices[0]))

// Função que realiza a animação dos LEDs piscando (pisca-pisca)
void ani_05()
{
    for (int cycle = 0; cycle < 10; cycle++) // Com o loop os LEDs piscam 10 vezes
    {
        // Acende os LEDsa lista com a cor azul intenso
        for (int led_index = 0; led_index < LED_COUNT; led_index++)
        {
            npSetLED(led_indices[led_index], AZUL_INTENSO);
        }
        npWrite();
        sleep_ms(DELAY_MS);

        // Apaga todos os LEDs
        npClear();
        npWrite();
        sleep_ms(DELAY_MS);
    }
}