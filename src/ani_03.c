#include "ani_03.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "ws2812.h"

// Definindo a quantidade de LEDs na matriz 5x5
#define NUM_LEDS 25
ws2812_t leds[NUM_LEDS];

// Função para inicializar o pino de controle do WS2812 (matriz de LEDs)
void npInit(uint pin) {
    // Inicializa o pino que controla os LEDs (não está implementado no código fornecido, você precisará ajustar conforme seu hardware)
}

// Função para acender um LED específico na cor (r, g, b)
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    if (index < NUM_LEDS) {
        leds[index].r = r;
        leds[index].g = g;
        leds[index].b = b;
    }
}

// Função para limpar todos os LEDs
void npClear() {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i].r = 0;
        leds[i].g = 0;
        leds[i].b = 0;
    }
}

// Função para enviar os dados para a matriz de LEDs
void npWrite() {
    ws2812_show(leds, NUM_LEDS);
}

// Função da animação para o botão 3
void ani_03() {
    // Exemplificando uma animação simples: os LEDs vão acender um a um, criando um efeito de "movimento"
    
    for (int i = 0; i < NUM_LEDS; i++) {
        // Definindo a cor do LED para azul (pode ajustar a cor e os valores conforme necessário)
        npSetLED(i, 0, 0, 255);  // Azul
        npWrite();
        sleep_ms(100);  // Atraso para dar o efeito de animação (100ms de intervalo)
    }
    
    // Limpa a matriz de LEDs ao final da animação
    npClear();
    npWrite();
    sleep_ms(500);  // Espera antes de reiniciar a animação
}

// Função para lidar com a leitura do teclado matricial e acionar animações
void handle_keypad_input() {
    char key = keypad_get_key();  // Função hipotética para pegar a tecla pressionada

    if (key == '3') {
        ani_03();  // Aciona a animação quando a tecla 3 é pressionada
    }
    
    // Adicione outras condições para outros botões, como A, B, etc.
}

int main() {
    stdio_init_all();
    
    // Inicializa os LEDs e o teclado
    ws2812_init();
    keypad_init();
    
    while (true) {
        handle_keypad_input();  // Verifica a entrada do teclado
        sleep_ms(100);  // Pausa para evitar alta carga de processamento
    }

    return 0;
}
