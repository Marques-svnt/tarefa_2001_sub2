#include <stdio.h>
#include "pico/bootrom.h"

// Função que executa a ação ao pressionar a tecla '*'
void ani_asterisco() {
    printf("Entrando no modo BOOTSEL...\n");
    reset_usb_boot(0, 0);
}
