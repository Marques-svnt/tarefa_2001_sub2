#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pico/cyw43_arch.h"


// Definição dos pinos do teclado
uint columns[4] = {4, 3, 2, 28}; // Pinos das colunas
uint rows[4] = {8, 9, 6, 5};     // Pinos das linhas

// Mapeamento do teclado
char KEY_MAP[16] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'
};

// Variáveis auxiliares para o teclado
uint _columns[4];
uint _rows[4];
char _matrix_values[16];
uint all_columns_mask = 0x0;
uint column_mask[4];

// Inicializa o teclado matricial
void pico_keypad_init(uint columns[4], uint rows[4], char matrix_values[16]) {
    for (int i = 0; i < 16; i++) {
        _matrix_values[i] = matrix_values[i];
    }

    for (int i = 0; i < 4; i++) {
        _columns[i] = columns[i];
        _rows[i] = rows[i];

        gpio_init(_columns[i]);
        gpio_init(_rows[i]);

        gpio_set_dir(_columns[i], GPIO_IN);
        gpio_set_dir(_rows[i], GPIO_OUT);

        gpio_put(_rows[i], 1);

        all_columns_mask = all_columns_mask + (1 << _columns[i]);
        column_mask[i] = 1 << _columns[i];
    }
}

// Lê o botão pressionado no teclado
char pico_keypad_get_key(void) {
    int row;
    uint32_t cols;

    // Lê as colunas
    cols = gpio_get_all();
    cols = cols & all_columns_mask;

    if (cols == 0x0) {
        return 0; // Nenhum botão pressionado
    }

    for (int j = 0; j < 4; j++) {
        gpio_put(_rows[j], 0);
    }

    for (row = 0; row < 4; row++) {
        gpio_put(_rows[row], 1);

        busy_wait_us(50000);

        cols = gpio_get_all();
        gpio_put(_rows[row], 0);
        cols = cols & all_columns_mask;

        if (cols != 0x0) {
            break;
        }
    }

    for (int i = 0; i < 4; i++) {
        gpio_put(_rows[i], 1);
    }

    if (cols == column_mask[0]) {
        return _matrix_values[row * 4 + 0];
    } else if (cols == column_mask[1]) {
        return _matrix_values[row * 4 + 1];
    } else if (cols == column_mask[2]) {
        return _matrix_values[row * 4 + 2];
    } else if (cols == column_mask[3]) {
        return _matrix_values[row * 4 + 3];
    } else {
        return 0;
    }
}

void teclado(){
    pico_keypad_init(columns, rows, KEY_MAP);
}