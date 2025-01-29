/*24,23,22,21,20
15,16,17,18,19
14,13,12,11,10
05,06,07,08,09
04,03,02,01,00*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"

// Definição de cores
#define MARROM_ESCURO 80, 134, 168
#define AMARELO_ESCURO 139, 139, 0
#define MARROM_CLARO 55, 130, 218
#define AZUL_MEDIO 0, 0, 245

// Delay da animação
#define DELAY_MS 500

// Frames da animação
uint8_t frames[10][4][10] = {
    {{4, 3, 2, 1, 0, 5, 6, 7, 8, 9}, {14}, {}, {}},
    {{4, 3, 2, 1, 0, 6, 7, 8, 9}, {5, 14, 13}, {}, {15, 24}},
    {{4, 3, 2, 1, 0, 7, 8, 9}, {5, 6, 14, 13, 12}, {15, 24}, {16, 23}},
    {{4, 3, 2, 1, 0, 8, 9}, {5, 6, 7, 14, 13, 12, 11}, {15, 16, 23}, {17, 22}},
    {{4, 3, 2, 1, 0, 5, 9}, {6, 7, 8, 14, 13, 12, 11, 10}, {16, 17, 22}, {18, 21}},
    {{4, 3, 2, 1, 0, 5, 6}, {7, 8, 9, 13, 12, 11, 10}, {17, 18, 21}, {19, 20}},
    {{4, 3, 2, 1, 0, 5, 6, 7}, {8, 9, 12, 11, 10}, {18, 19, 20}, {}},
    {{4, 3, 2, 1, 0, 5, 6, 7, 8}, {9, 11, 10}, {19}, {}},
    {{4, 3, 2, 1, 0, 5, 6, 7, 8, 9}, {10}, {}, {}},
    {{4, 3, 2, 1, 0, 5, 6, 7, 8, 9}, {}, {}, {}}};

static void light_up_leds(const uint8_t *led_positions, size_t count, uint8_t r, uint8_t g, uint8_t b)
{
    for (size_t i = 0; i < count; i++)
    {
        npSetLED(led_positions[i], r, g, b);
    }
    npWrite();
}

void desenha_barco()
{
    for (int i = 0; i < 5; i++) // Repetir a animação 5x
    {
        for (int f = 0; f < 10; f++) // Percorrer todos os frames
        {
            npClear();
            light_up_leds(frames[f][1], 10, MARROM_ESCURO);  // Base do barco
            light_up_leds(frames[f][2], 10, AMARELO_ESCURO); // Vela
            light_up_leds(frames[f][3], 10, MARROM_CLARO);   // Suporte da vela
            light_up_leds(frames[f][0], 10, AZUL_MEDIO);     // Água
            sleep_ms(DELAY_MS);
        }
    }
    npClear();
    npWrite();
}
