// #include "tecla_hashtag.h"
// #include "leds.h"
// #include <stdio.h>
// #include "pico/stdlib.h"
// #include <stdint.h>

// // Definição da cor azul com intensidade de 20% (20% de 255 = 51)
// #define AZUL_20 0, 0, 51

// // Lista de LEDs que serão controlados
// extern const uint8_t led_indices[];

// // Número total de LEDs
// #define LED_COUNT (sizeof(led_indices) / sizeof(led_indices[0]))

// // Lista de LEDs que serão controlados
// const uint8_t led_indices[] = {
//     0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

// // Função que é acionada ao pressionar a tecla #
// void tecla_hashtag() {
//     // Configura cada LED na cor azul com intensidade de 20%
//     for (int i = 0; i < LED_COUNT; i++) {
//         npSetLED(led_indices[i], AZUL_20); // Acende o LED com a cor azul 20% de intensidade
//     }

//     // Envia os dados para atualizar os LEDs
//     npWrite();

//     // Mensagem de confirmação
//     printf("Todos os LEDs configurados na cor azul com 20%% de intensidade.\n");
// }

// // Função para monitorar a tecla # pressionada
// void monitorar_tecla() {
//     tecla_hashtag(); // Apenas chama a função que acende os LEDs
// }
