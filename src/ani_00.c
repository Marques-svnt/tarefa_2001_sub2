#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

// Biblioteca gerada pelo arquivo .pio durante compilação.
#include "ws2818b.pio.h"

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 9

// Definição do delay
#define delay 500 

// Definição de pixel GRB
struct pixel_t {
  uint8_t G, R, B; // Três valores de 8-bits compõem um pixel.
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t; // Mudança de nome de "struct pixel_t" para "npLED_t" por clareza.

// Declaração do buffer de pixels que formam a matriz.
npLED_t leds[LED_COUNT];

// Variáveis para uso da máquina PIO.
PIO np_pio;
uint sm;

/**
 * Inicializa a máquina PIO para controle da matriz de LEDs.
 */
void npInit(uint pin) {

  // Cria programa PIO.
  uint offset = pio_add_program(pio0, &ws2818b_program);
  np_pio = pio0;

  // Toma posse de uma máquina PIO.
  sm = pio_claim_unused_sm(np_pio, false);
  if (sm < 0) {
    np_pio = pio1;
    sm = pio_claim_unused_sm(np_pio, true); // Se nenhuma máquina estiver livre, panic!
  }

  // Inicia programa na máquina PIO obtida.
  ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

  // Limpa buffer de pixels.
  for (uint i = 0; i < LED_COUNT; ++i) {
    leds[i].R = 0;
    leds[i].G = 0;
    leds[i].B = 0;
  }
}

/**
 * Atribui uma cor RGB a um LED.
 */
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
  leds[index].R = r;
  leds[index].G = g;
  leds[index].B = b;
}

/**
 * Limpa o buffer de pixels.
 */
void npClear() {
  for (uint i = 0; i < LED_COUNT; ++i)
    npSetLED(i, 0, 0, 0);
}

/**
 * Escreve os dados do buffer nos LEDs.
 */
void npWrite() {
  // Escreve cada dado de 8-bits dos pixels em sequência no buffer da máquina PIO.
  for (uint i = 0; i < LED_COUNT; ++i) {
    pio_sm_put_blocking(np_pio, sm, leds[i].G);
    pio_sm_put_blocking(np_pio, sm, leds[i].R);
    pio_sm_put_blocking(np_pio, sm, leds[i].B);
  }
  sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}

void ani_00() {

  // Inicializa entradas e saídas.
  stdio_init_all();

  // Inicializa matriz de LEDs NeoPixel.
  npInit(LED_PIN);
  npClear();
  while (true) {
  //frame 1
  npSetLED(1, 200, 200, 200); // branco
  npWrite(); // Escreve os dados nos LEDs.
  sleep_ms(delay);
  npClear();

  //frame 2
  npSetLED(2, 200, 200, 200);
  npSetLED(8, 200, 200, 200);
  npWrite(); 
  sleep_ms(delay);
  npClear();

  //frame 3
  npSetLED(1, 0, 0, 200); //azul
  npSetLED(2, 0, 0, 200);
  npSetLED(3, 0, 0, 200);
  npSetLED(7, 200, 200, 200);
  npSetLED(11, 200, 200, 200);
  npWrite(); 
  sleep_ms(delay);
  npClear();

  //frame 4
  npSetLED(0, 0, 0, 200);
  npSetLED(1, 0, 0, 200);
  npSetLED(2, 0, 0, 200);
  npSetLED(3, 0, 0, 200);
  npSetLED(4, 0, 0, 200);
  npSetLED(6, 0, 0, 200);
  npSetLED(7, 0, 0, 200);
  npSetLED(8, 0, 0, 200);
  npSetLED(12, 200, 200, 200);
  npSetLED(18, 200, 200, 200);
  npWrite(); 
  sleep_ms(delay);
  npClear();
  
  //frame 5
  npSetLED(0, 0, 0, 200);
  npSetLED(1, 0, 0, 200);
  npSetLED(2, 0, 0, 200);
  npSetLED(3, 0, 0, 200);
  npSetLED(4, 0, 0, 200);
  npSetLED(5, 0, 0, 200);
  npSetLED(6, 0, 0, 200);
  npSetLED(7, 0, 0, 200);
  npSetLED(8, 0, 0, 200);
  npSetLED(9, 0, 0, 200);
  npSetLED(11, 0, 0, 200);
  npSetLED(12, 0, 0, 200);
  npSetLED(13, 0, 0, 200);
  npSetLED(17, 200, 200, 200);
  npSetLED(21, 200, 200, 200);
  npWrite(); 
  sleep_ms(delay);
  npClear();
  
  //frame 6
  npSetLED(0, 0, 0, 200);
  npSetLED(1, 0, 0, 200);
  npSetLED(2, 0, 0, 200);
  npSetLED(3, 0, 0, 200);
  npSetLED(4, 0, 0, 200);
  npSetLED(5, 0, 0, 200);
  npSetLED(6, 0, 0, 200);
  npSetLED(7, 0, 0, 200);
  npSetLED(8, 0, 0, 200);
  npSetLED(9, 0, 0, 200);
  npSetLED(11, 0, 0, 200);
  npSetLED(12, 0, 0, 200);
  npSetLED(13, 0, 0, 200);
  npSetLED(17, 200, 200, 200);
  npSetLED(18, 200, 200, 0);
  npSetLED(20, 200, 200, 0); //amarelo
  npSetLED(21, 220, 80, 0); //laranja
  npSetLED(22, 200, 200, 0);
  npWrite(); 
  sleep_ms(delay);
  npClear();
  
  //frame 7
  npSetLED(0, 0, 0, 200);
  npSetLED(1, 0, 0, 200);
  npSetLED(2, 0, 0, 200);
  npSetLED(3, 0, 0, 200);
  npSetLED(4, 0, 0, 200);
  npSetLED(5, 0, 0, 200);
  npSetLED(6, 0, 0, 200);
  npSetLED(7, 0, 0, 200);
  npSetLED(8, 0, 0, 200);
  npSetLED(9, 0, 0, 200);
  npSetLED(11, 0, 0, 200);
  npSetLED(12, 200, 200, 0);
  npSetLED(13, 0, 0, 200);
  npSetLED(16, 200, 200, 0);
  npSetLED(17, 220, 80, 0);
  npSetLED(18, 200, 200, 0);
  npSetLED(22, 200, 200, 0);
  npWrite(); 
  sleep_ms(delay);
  npClear();

  //frame 8
  npSetLED(0, 0, 0, 200);
  npSetLED(1, 0, 0, 200);
  npSetLED(2, 0, 0, 200);
  npSetLED(3, 0, 0, 200);
  npSetLED(4, 0, 0, 200);
  npSetLED(5, 0, 0, 200);
  npSetLED(6, 0, 0, 200);
  npSetLED(7, 200, 200, 0);
  npSetLED(8, 0, 0, 200);
  npSetLED(9, 0, 0, 200);
  npSetLED(11, 200, 200, 0);
  npSetLED(12, 220, 80, 0);
  npSetLED(13, 200, 200, 0);
  npSetLED(17, 200, 200, 0);
  npWrite(); 
  sleep_ms(delay);
  npClear();

  //frame 9
  npSetLED(0, 200, 200, 0);
  npSetLED(1, 200, 200, 0);
  npSetLED(2, 200, 200, 0);
  npSetLED(3, 200, 200, 0);
  npSetLED(4, 200, 200, 0);
  npSetLED(5, 200, 200, 0);
  npSetLED(6, 200, 200, 0);
  npSetLED(7, 220, 80, 0);
  npSetLED(8, 200, 200, 0);
  npSetLED(9, 200, 200, 0);
  npSetLED(10, 200, 200, 0);
  npSetLED(11, 220, 80, 0);
  npSetLED(12, 220, 80, 0);
  npSetLED(13, 220, 80, 0);
  npSetLED(14, 200, 200, 0);
  npSetLED(15, 200, 200, 0);
  npSetLED(16, 200, 200, 0);
  npSetLED(17, 220, 80, 0);
  npSetLED(18, 200, 200, 0);
  npSetLED(19, 200, 200, 0);
  npSetLED(20, 200, 200, 0);
  npSetLED(21, 200, 200, 0);
  npSetLED(22, 200, 200, 0);
  npSetLED(23, 200, 200, 0);
  npSetLED(24, 200, 200, 0);
  npWrite(); 
  sleep_ms(delay);
  npClear();
  
  //frame 10
  npSetLED(0, 200, 200, 0);
  npSetLED(1, 200, 200, 0);
  npSetLED(2, 220, 80, 0);
  npSetLED(3, 200, 200, 0);
  npSetLED(4, 200, 200, 0);
  npSetLED(5, 200, 200, 0);
  npSetLED(6, 220, 80, 0);
  npSetLED(7, 220, 80, 0);
  npSetLED(8, 220, 80, 0);
  npSetLED(9, 200, 200, 0);
  npSetLED(10, 220, 80, 0);
  npSetLED(11, 220, 80, 0);
  npSetLED(13, 220, 80, 0);
  npSetLED(14, 220, 80, 0);
  npSetLED(15, 200, 200, 0);
  npSetLED(16, 220, 80, 0);
  npSetLED(17, 220, 80, 0);
  npSetLED(18, 220, 80, 0);
  npSetLED(19, 200, 200, 0);
  npSetLED(20, 200, 200, 0);
  npSetLED(21, 200, 200, 0);
  npSetLED(22, 220, 80, 0);
  npSetLED(23, 200, 200, 0);
  npSetLED(24, 200, 200, 0);
  npWrite(); 
  sleep_ms(delay);
  npClear();

  //frame 11
  npSetLED(0, 220, 80, 0);
  npSetLED(1, 220, 80, 0);
  npSetLED(2, 220, 80, 0);
  npSetLED(3, 220, 80, 0);
  npSetLED(4, 220, 80, 0);
  npSetLED(5, 220, 80, 0);
  npSetLED(6, 220, 80, 0);
  npSetLED(8, 220, 80, 0);
  npSetLED(9, 220, 80, 0);
  npSetLED(10, 220, 80, 0);
  npSetLED(14, 220, 80, 0);
  npSetLED(15, 220, 80, 0);
  npSetLED(16, 220, 80, 0);
  npSetLED(18, 220, 80, 0);
  npSetLED(19, 220, 80, 0);
  npSetLED(20, 220, 80, 0);
  npSetLED(21, 220, 80, 0);
  npSetLED(22, 220, 80, 0);
  npSetLED(23, 220, 80, 0);
  npSetLED(24, 220, 80, 0);
  npWrite(); 
  sleep_ms(delay);
  npClear();

  //frame 12
  npClear();
  npWrite(); 
  sleep_ms(delay);

  }

}