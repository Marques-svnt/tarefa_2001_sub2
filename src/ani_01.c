#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "buzzer.h"
#include "leds.h"

// Definição das cores:
#define BRANCO 255, 255, 255
#define AZUL 0, 0, 255
#define AMARELO 255, 255, 0
#define LARANJA 255, 150, 0

// Definição do delay
#define delay 1000 / 4

void ani_01()
{
  buzzer_init();

  // frame 1
  npSetLED(1, BRANCO);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 2
  npSetLED(2, BRANCO);
  npSetLED(8, BRANCO);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 3
  npSetLED(1, AZUL);
  npSetLED(2, AZUL);
  npSetLED(3, AZUL);
  npSetLED(7, BRANCO);
  npSetLED(11, BRANCO);
  npWrite();
  sleep_ms(delay);
  npClear();

  // frame 4
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

  // frame 5
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

  // frame 6
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

  // frame 7
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

  // frame 8
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

  // frame 9
  buzz(300, 500); //som da bomba
  buzz(250, 500);
  buzz(100, 250);
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

  // frame 10
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

  // frame 11
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

  // frame 12
  npClear();
  npWrite();
  buzzer_stop();
  sleep_ms(1000);
}