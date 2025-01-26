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

// Cor azul
#define AZUL 0, 0, 255

#define FRAME_DELAY (1000 / FPS)
#define FPS 15

typedef struct {
  uint8_t G, R, B;
} pixel_t;
pixel_t leds[LED_COUNT];
PIO np_pio;
uint sm;

void npInit(uint pin);
void npSetLED(uint index, uint8_t r, uint8_t g, uint8_t b);
void npClear();
void npWrite();

// Funções de animação
void ani_wave_5frames();
void ani_snake_5frames();
void ani_fade_5frames();

int main() {
  stdio_init_all();
  npInit(LED_PIN);

  while (1) {
    ani_wave_5frames();    // Animação de onda (5 frames)
    ani_snake_5frames();   // Animação de cobra (5 frames)
    ani_fade_5frames();    // Animação de fade (5 frames)
  }
}

// Inicialização da máquina PIO
void npInit(uint pin) {
  uint offset = pio_add_program(pio0, &ws2818b_program);
  np_pio = pio0;
  sm = pio_claim_unused_sm(np_pio, false);
  ws2818b_program_init(np_pio, sm, offset, pin, 800000.0);

  npClear();
  npWrite();
}

// Define a cor de um LED
void npSetLED(uint index, uint8_t r, uint8_t g, uint8_t b) {
  leds[index].R = r;
  leds[index].G = g;
  leds[index].B = b;
}

// Limpa todos os LEDs
void npClear() {
  for (uint i = 0; i < LED_COUNT; ++i) {
    npSetLED(i, 0, 0, 0);
  }
}

// Atualiza os LEDs
void npWrite() {
  for (uint i = 0; i < LED_COUNT; ++i) {
    pio_sm_put_blocking(np_pio, sm, leds[i].G);
    pio_sm_put_blocking(np_pio, sm, leds[i].R);
    pio_sm_put_blocking(np_pio, sm, leds[i].B);
  }
  sleep_us(100); // Reset
}

// Animação de onda (5 frames)
void ani_wave_5frames() {
  for (int frame = 0; frame < 5; ++frame) {
    npClear();
    int led_index = (LED_COUNT / 5) * frame; // Divide LEDs em 5 partes
    npSetLED(led_index, AZUL);
    npWrite();
    sleep_ms(FRAME_DELAY);
  }
}

// Animação de cobra (5 frames)
void ani_snake_5frames() {
  for (int frame = 0; frame < 5; ++frame) {
    npClear();
    for (int trail = 0; trail < 5; ++trail) {
      int pos = (LED_COUNT / 5) * frame - trail;
      if (pos >= 0 && pos < LED_COUNT) {
        npSetLED(pos, AZUL);
      }
    }
    npWrite();
    sleep_ms(FRAME_DELAY);
  }
}

// Animação de fade (5 frames)
void ani_fade_5frames() {
  int intensity_steps = 255 / 5; // Divide intensidade em 5 passos
  for (int frame = 0; frame < 5; ++frame) {
    int intensity = intensity_steps * (frame + 1);
    npClear();
    for (int i = 0; i < LED_COUNT; ++i) {
      npSetLED(i, 0, 0, intensity);
    }
    npWrite();
    sleep_ms(FRAME_DELAY);
  }
  for (int frame = 4; frame >= 0; --frame) { // Reverso para apagar
    int intensity = intensity_steps * (frame + 1);
    npClear();
    for (int i = 0; i < LED_COUNT; ++i) {
      npSetLED(i, 0, 0, intensity);
    }
    npWrite();
    sleep_ms(FRAME_DELAY);
  }
}