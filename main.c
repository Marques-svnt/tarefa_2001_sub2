#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pico/cyw43_arch.h"
#include "ani_01.h"
#include "ani_02.h"
#include "ani_03.h"
#include "ani_04.h"
#include "ani_05.h"
#include "ani_05.h"
#include "ani_06.h"
#include "ani_07.h"
#include "ani_asterisco.h"
#include "teclado.h"
#include "buzzer.h"
#include "ani_tecla_c.h"
#include "ani_tecla_b.h"
#include "bot_d.h"
#include "tecla_hashtag.h"
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
        if (key == '1')
        {
            ani_01();
            sleep_ms(500);
        }
        else if (key == '2')
        {
            ani_02();
            sleep_ms(500);
        }
        else if (key == '3')
        {
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
        else if (key == '7') {
            ani_07();  
            sleep_ms(500);
        }
        else if (key == 'A')
        {
            bot_A();
        }
        else if (key == 'B')
        {
            ani_tecla_b();
        }
        else if (key == 'C')
        {
            ani_tecla_c();
        }
        else if (key == 'D')
        {
            bot_d();
        }
        else if (key == '#')
        {
            tecla_hashtag();
        }
        else if (key == '*')
        {
            ani_asterisco(); // Chama a funcionalidade da tecla '*'
        }
    }
}