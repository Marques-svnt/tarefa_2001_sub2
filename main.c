#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pico/cyw43_arch.h"
#include "ani_00.h"
#include "ani_02.h"
#include "ani_03.h"
#include "ani_04.h"
#include "ani_05.h"
#include "ani_asterisco.h"
#include "tecla_hashtag.h"
#include "teclado.h"
#include "buzzer.h"
#include "ani_tecla_c.h"
#include "leds.h"

#define LED_PIN 7

// Função principal
int main()
{
    // Inicializar todos os perifericos
    stdio_init_all();
    teclado();
    gpio_set_function(21, GPIO_FUNC_PWM);
    npInit(LED_PIN);
    npClear();

    while (true)
    {
        char key = pico_keypad_get_key();

        // Controle baseado em teclas específicas
        if (key == '0')
        {
            ani_00();
            sleep_ms(500);
        }
        else if (key == '1')
        {
            // Animação da tecla 1
        }
        else if (key == '2')
        {
            ani_02();
            sleep_ms(500);
        }
        else if (key == '3')
        {
          // Animação da tecla 3
          ani_03();  
          sleep_ms(500);  
        }
        else if (key == '4')
        {
            ani_04();
            sleep_ms(500);
        }
        else if (key == '5')
        {
            ani_05();
            sleep_ms(500);
        }
        else if (key == '6')
        {
            // Animação da tecla 6
            ani_06();  
            sleep_ms(500); 
        }
        else if (key == '7')
        {
            // Animação da tecla 7
        }
        else if (key == 'A')
        {
            bot_A();
        }
        else if (key == 'B')
        {
            // Animação da tecla B
        }
        else if (key == 'C')
        {
            // Animação da tecla C
        }
        else if (key == 'D')
        {
            // Animação da tecla D
        }
        else if (key == '#')
        {
            // Animação da tecla #
        }
        else if (key == '*')
        {
            ani_asterisco(); // Chama a funcionalidade da tecla '*'
        }
        else
            printf("Essa tecla não possui animação");
        }
    }
}
