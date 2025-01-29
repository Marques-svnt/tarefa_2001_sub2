
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

// Definindo as cores da casa
#define AZUL_CLARO 0, 0, 169  // Cor azul claro para a casa
#define AMARELO_ESCURO 139, 139, 0  // Cor amarelo escuro para o telhado
#define VERMELHO_MEDIO 139, 0, 0// Cor vermelho médio para a porta

// Delay de controle da animação
#define DELAY_MS 2000

// Posições dos LEDs para a casinha e o mato
const uint8_t casa_base[] = {3, 1, 6, 8}; // Base da casa
const uint8_t casa_telhado[] = {10, 11, 12, 13, 14, 18, 22, 16};  // Telhado da casa
const uint8_t casa_porta[] = {2, 7};  // Posições do mato

static void light_up_leds(const uint8_t *led_positions, size_t count, uint8_t r, uint8_t g, uint8_t b)
{
    for (size_t i = 0; i < count; i++)
    {
        npSetLED(led_positions[i], r, g, b);
    }
    npWrite();
    
}

void desenha_casa()
{
    // Desenha a base da casa com cor cinza escuro
    light_up_leds(casa_base, sizeof(casa_base) / sizeof(casa_base[0]), AZUL_CLARO);
    // Desenha o telhado com cor marrom médio
    light_up_leds(casa_telhado, sizeof(casa_telhado) / sizeof(casa_telhado[0]), AMARELO_ESCURO);
    // Desenha a porta com cor cinza escuro
    light_up_leds(casa_porta, sizeof(casa_porta) / sizeof(casa_porta[0]), VERMELHO_MEDIO);

    sleep_ms(DELAY_MS);
    npClear();
    npWrite();
}


