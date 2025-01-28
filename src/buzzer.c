#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define BUZZER_PIN 21 // Porta associada ao Buzzer

// Inicializa o PWM para o buzzer
void buzzer_init() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_set_enabled(slice_num, false); // Garante que o PWM comece desligado
}

// Toca um tom no buzzer
void buzz(uint freq, uint tempo) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    uint channel = pwm_gpio_to_channel(BUZZER_PIN);

    // Configurando a frequência
    uint32_t clock_freq = 125000000; 
    uint32_t divider = clock_freq / freq / 65536 + 1; 
    uint32_t top = clock_freq / (divider * freq);

    pwm_set_clkdiv(slice_num, divider);
    pwm_set_wrap(slice_num, top - 1);
    pwm_set_chan_level(slice_num, channel, top / 2);
    pwm_set_enabled(slice_num, true);

    sleep_ms(tempo);

    // Opcional: Reduz o volume em vez de desligar totalmente
    pwm_set_chan_level(slice_num, channel, 0);
}

// Desativa o PWM do buzzer completamente
void buzzer_stop() {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_set_enabled(slice_num, false);
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_SIO);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0); // Garante que o pino esteja em LOW
}
