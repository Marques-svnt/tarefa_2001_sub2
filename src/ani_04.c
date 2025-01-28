#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 7

// Definição das cores:
#define BRANCO 200, 200, 200
#define AZUL 0, 0, 200

// Definição do delay
#define delay 1000 / 4

/// animação 4 caso seja apertado a tecla 4
void ani_04()
{
  // Inicializa entradas e saídas.
  stdio_init_all();

  // Inicializa matriz de LEDs NeoPixel.
  npInit(LED_PIN);
  npClear();
  // frame 1
  npSetLED(1, AZUL);
  npSetLED(3, AZUL);
  npSetLED(6, AZUL);
  npSetLED(7, AZUL);
  npSetLED(8, AZUL);
  npSetLED(12, AZUL);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 2
  npSetLED(1, AZUL);
  npSetLED(3, AZUL);
  npSetLED(6, AZUL);
  npSetLED(7, AZUL);
  npSetLED(8, AZUL);
  npSetLED(12, AZUL);
  npSetLED(17, BRANCO);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 3
  npSetLED(1, AZUL);
  npSetLED(3, AZUL);
  npSetLED(6, AZUL);
  npSetLED(7, AZUL);
  npSetLED(8, AZUL);
  npSetLED(12, AZUL);
  npSetLED(22, BRANCO);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 4
  npSetLED(1, AZUL);
  npSetLED(3, AZUL);
  npSetLED(6, AZUL);
  npSetLED(7, AZUL);
  npSetLED(8, AZUL);
  npSetLED(12, AZUL);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 5
  npSetLED(0, AZUL);
  npSetLED(2, AZUL);
  npSetLED(7, AZUL);
  npSetLED(8, AZUL);
  npSetLED(9, AZUL);
  npSetLED(11, AZUL);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 6
  npSetLED(0, AZUL);
  npSetLED(2, AZUL);
  npSetLED(7, AZUL);
  npSetLED(8, AZUL);
  npSetLED(9, AZUL);
  npSetLED(11, AZUL);
  npSetLED(18, BRANCO);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 7
  npSetLED(0, AZUL);
  npSetLED(2, AZUL);
  npSetLED(7, AZUL);
  npSetLED(8, AZUL);
  npSetLED(9, AZUL);
  npSetLED(11, AZUL);
  npSetLED(21, BRANCO);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 8
  npSetLED(1, AZUL);
  npSetLED(3, AZUL);
  npSetLED(6, AZUL);
  npSetLED(7, AZUL);
  npSetLED(8, AZUL);
  npSetLED(12, AZUL);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 9
  npClear();
  npWrite();
  sleep_ms(delay);
}
// caso seja apertado a tecla A todos os leds serão desligados
void bot_A()
{
  npClear();
  npWrite();
  sleep_ms(delay);
}
