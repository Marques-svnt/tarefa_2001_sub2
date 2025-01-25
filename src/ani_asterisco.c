#include <stdio.h>
#include "hardware/watchdog.h"

// Função que executa a ação ao pressionar a tecla '*'
void ani_asterisco() {
    printf("Modo de gravação habilitado. Reiniciando...\n");
    watchdog_reboot(0, 0, 0);  // Reinicia o Raspberry Pi Pico
}
