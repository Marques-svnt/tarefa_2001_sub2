#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "leds.h"

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 7

// Cor azul
#define AZUL 0, 0, 255

#define FRAME_DELAY (1000 / FPS)
#define FPS 15

// Animação de onda (5 frames)
void ani_wave_5frames()
{
  for (int frame = 0; frame < 5; ++frame)
  {
    npClear();
    int led_index = (LED_COUNT / 5) * frame; // Divide LEDs em 5 partes
    npSetLED(led_index, AZUL);
    npWrite();
    sleep_ms(FRAME_DELAY);
  }
}

// Animação de cobra (5 frames)
void ani_snake_5frames()
{
  for (int frame = 0; frame < 5; ++frame)
  {
    npClear();
    for (int trail = 0; trail < 5; ++trail)
    {
      int pos = (LED_COUNT / 5) * frame - trail;
      if (pos >= 0 && pos < LED_COUNT)
      {
        npSetLED(pos, AZUL);
      }
    }
    npWrite();
    sleep_ms(FRAME_DELAY);
  }
}

// Animação de fade (5 frames)
void ani_fade_5frames()
{
  int intensity_steps = 255 / 5; // Divide intensidade em 5 passos
  for (int frame = 0; frame < 5; ++frame)
  {
    int intensity = intensity_steps * (frame + 1);
    npClear();
    for (int i = 0; i < LED_COUNT; ++i)
    {
      npSetLED(i, 0, 0, intensity);
    }
    npWrite();
    sleep_ms(FRAME_DELAY);
  }
  for (int frame = 4; frame >= 0; --frame)
  { // Reverso para apagar
    int intensity = intensity_steps * (frame + 1);
    npClear();
    for (int i = 0; i < LED_COUNT; ++i)
    {
      npSetLED(i, 0, 0, intensity);
    }
    npWrite();
    sleep_ms(FRAME_DELAY);
  }
}

  void ani_02()
  {
    ani_wave_5frames();  // Animação de onda (5 frames)
    ani_snake_5frames(); // Animação de cobra (5 frames)
    ani_fade_5frames();  // Animação de fade (5 frames)
    npClear();
    npWrite();
  }
