#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

#define BUZZER 21  // Pino do buzzer ligado na porta 21

void inicialize(uint pin, bool is_input) {
    gpio_init(pin);
    gpio_set_dir(pin, !is_input); // false = saída, true = entrada
    if (is_input) {
        gpio_pull_up(pin); // Ativa pull-up para o botão
    }
}

void init_buzzer() {
    inicialize(BUZZER, false);    // Configura o pino do buzzer como saída
    gpio_put(BUZZER, 0);         // Desliga o buzzer inicialmente
}

void control_buzzer_pwm(bool state, float freq) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    uint chan_num = pwm_gpio_to_channel(BUZZER);

    if (state) {
        gpio_set_function(BUZZER, GPIO_FUNC_PWM); // Configura o pino para função PWM

        uint32_t clk_div = 4; // Divisor de clock padrão
        uint32_t top = (125000000 / (clk_div * freq)) - 1;

        pwm_set_wrap(slice_num, top);   // Configura o valor de TOP para o PWM
        pwm_set_clkdiv(slice_num, (float)clk_div); // Ajusta o divisor de clock
        pwm_set_gpio_level(BUZZER, top / 2); // Define o ciclo de trabalho (50%)
        pwm_set_enabled(slice_num, true);  // Liga o PWM
    } else {
        pwm_set_enabled(slice_num, false); // Desliga o PWM
        gpio_set_function(BUZZER, GPIO_FUNC_SIO); // Volta o pino para GPIO normal
        gpio_put(BUZZER, 0); // Garante que o pino está desligado
    }
}

void buzz() {
    init_buzzer(); // Inicializa o buzzer
    control_buzzer_pwm(true, 700.0f); // Liga o buzzer com frequência de 700 Hz
    sleep_ms(1000); // Mantém o buzzer ligado por 2,5 segundos
    control_buzzer_pwm(false, 700.0f); // Desliga o buzzer
}
