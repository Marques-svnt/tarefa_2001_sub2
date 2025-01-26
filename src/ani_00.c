#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "buzzer.h"

// Biblioteca gerada pelo arquivo .pio durante compilação.
#include "ws2818b.pio.h"

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 7

// Definição das cores:
#define BRANCO 200, 200, 200
#define AZUL  0, 0, 200
#define AMARELO 200, 200, 0
#define LARANJA 220, 80, 0

// Definição do delay
#define delay 1000/4 

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

  // Inicializa o Buzzer
  gpio_set_function(21, GPIO_FUNC_PWM);

  // Inicializa matriz de LEDs NeoPixel.
  npInit(LED_PIN);
  npClear();
    //frame 1
    npSetLED(1, BRANCO);
    npWrite();
    sleep_ms(delay);
    npClear();

    //frame 2
    npSetLED(2, BRANCO);
    npSetLED(8, BRANCO);
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 3
    npSetLED(1, AZUL);
    npSetLED(2, AZUL);
    npSetLED(3, AZUL);
    npSetLED(7, BRANCO);
    npSetLED(11, BRANCO);
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 4
    npSetLED(0, AZUL);
    npSetLED(1, AZUL);
    npSetLED(2, AZUL);
    npSetLED(3, AZUL);
    npSetLED(4, AZUL);
    npSetLED(6, AZUL);
    npSetLED(7, AZUL);
    npSetLED(8, AZUL);
    npSetLED(12, BRANCO);
    npSetLED(18, BRANCO);
    npWrite(); 
    sleep_ms(delay);
    npClear();
    
    //frame 5
    npSetLED(0, AZUL);
    npSetLED(1, AZUL);
    npSetLED(2, AZUL);
    npSetLED(3, AZUL);
    npSetLED(4, AZUL);
    npSetLED(5, AZUL);
    npSetLED(6, AZUL);
    npSetLED(7, AZUL);
    npSetLED(8, AZUL);
    npSetLED(9, AZUL);
    npSetLED(11, AZUL);
    npSetLED(12, AZUL);
    npSetLED(13, AZUL);
    npSetLED(17, BRANCO);
    npSetLED(21, BRANCO);
    npWrite(); 
    sleep_ms(delay);
    npClear();
    
    //frame 6
    npSetLED(0, AZUL);
    npSetLED(1, AZUL);
    npSetLED(2, AZUL);
    npSetLED(3, AZUL);
    npSetLED(4, AZUL);
    npSetLED(5, AZUL);
    npSetLED(6, AZUL);
    npSetLED(7, AZUL);
    npSetLED(8, AZUL);
    npSetLED(9, AZUL);
    npSetLED(11, AZUL);
    npSetLED(12, AZUL);
    npSetLED(13, AZUL);
    npSetLED(17, BRANCO);
    npSetLED(18, AMARELO);
    npSetLED(20, AMARELO); 
    npSetLED(21, LARANJA); 
    npSetLED(22, AMARELO);
    npWrite(); 
    sleep_ms(delay);
    npClear();
    
    //frame 7
    npSetLED(0, AZUL);
    npSetLED(1, AZUL);
    npSetLED(2, AZUL);
    npSetLED(3, AZUL);
    npSetLED(4, AZUL);
    npSetLED(5, AZUL);
    npSetLED(6, AZUL);
    npSetLED(7, AZUL);
    npSetLED(8, AZUL);
    npSetLED(9, AZUL);
    npSetLED(11, AZUL);
    npSetLED(12, AMARELO);
    npSetLED(13, AZUL);
    npSetLED(16, AMARELO);
    npSetLED(17, LARANJA);
    npSetLED(18, AMARELO);
    npSetLED(22, AMARELO);
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 8
    npSetLED(0, AZUL);
    npSetLED(1, AZUL);
    npSetLED(2, AZUL);
    npSetLED(3, AZUL);
    npSetLED(4, AZUL);
    npSetLED(5, AZUL);
    npSetLED(6, AZUL);
    npSetLED(7, AMARELO);
    npSetLED(8, AZUL);
    npSetLED(9, AZUL);
    npSetLED(11, AMARELO);
    npSetLED(12, LARANJA);
    npSetLED(13, AMARELO);
    npSetLED(17, AMARELO);
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 9
    buzz(300,500);
    buzz(250,500);
    buzz(100,250);
    npSetLED(0, AMARELO);
    npSetLED(1, AMARELO);
    npSetLED(2, AMARELO);
    npSetLED(3, AMARELO);
    npSetLED(4, AMARELO);
    npSetLED(5, AMARELO);
    npSetLED(6, AMARELO);
    npSetLED(7, LARANJA);
    npSetLED(8, AMARELO);
    npSetLED(9, AMARELO);
    npSetLED(10, AMARELO);
    npSetLED(11, LARANJA);
    npSetLED(12, LARANJA);
    npSetLED(13, LARANJA);
    npSetLED(14, AMARELO);
    npSetLED(15, AMARELO);
    npSetLED(16, AMARELO);
    npSetLED(17, LARANJA);
    npSetLED(18, AMARELO);
    npSetLED(19, AMARELO);
    npSetLED(20, AMARELO);
    npSetLED(21, AMARELO);
    npSetLED(22, AMARELO);
    npSetLED(23, AMARELO);
    npSetLED(24, AMARELO);
    npWrite(); 
    sleep_ms(delay);
    npClear();
    
    //frame 10
    npSetLED(0, AMARELO);
    npSetLED(1, AMARELO);
    npSetLED(2, LARANJA);
    npSetLED(3, AMARELO);
    npSetLED(4, AMARELO);
    npSetLED(5, AMARELO);
    npSetLED(6, LARANJA);
    npSetLED(7, LARANJA);
    npSetLED(8, LARANJA);
    npSetLED(9, AMARELO);
    npSetLED(10, LARANJA);
    npSetLED(11, LARANJA);
    npSetLED(13, LARANJA);
    npSetLED(14, LARANJA);
    npSetLED(15, AMARELO);
    npSetLED(16, LARANJA);
    npSetLED(17, LARANJA);
    npSetLED(18, LARANJA);
    npSetLED(19, AMARELO);
    npSetLED(20, AMARELO);
    npSetLED(21, AMARELO);
    npSetLED(22, LARANJA);
    npSetLED(23, AMARELO);
    npSetLED(24, AMARELO);
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 11
    npSetLED(0, LARANJA);
    npSetLED(1, LARANJA);
    npSetLED(2, LARANJA);
    npSetLED(3, LARANJA);
    npSetLED(4, LARANJA);
    npSetLED(5, LARANJA);
    npSetLED(6, LARANJA);
    npSetLED(8, LARANJA);
    npSetLED(9, LARANJA);
    npSetLED(10, LARANJA);
    npSetLED(14, LARANJA);
    npSetLED(15, LARANJA);
    npSetLED(16, LARANJA);
    npSetLED(18, LARANJA);
    npSetLED(19, LARANJA);
    npSetLED(20, LARANJA);
    npSetLED(21, LARANJA);
    npSetLED(22, LARANJA);
    npSetLED(23, LARANJA);
    npSetLED(24, LARANJA);
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 12
    npClear();
    npWrite(); 
    sleep_ms(delay);
}