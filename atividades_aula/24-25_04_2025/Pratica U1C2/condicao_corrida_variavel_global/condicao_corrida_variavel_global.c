#include <stdio.h>
#include "pico/stdlib.h"

#define BOTAO 5

volatile int contador = 0;

void gpio_callback(uint gpio, uint32_t events) {
    if (gpio == BOTAO && (events & GPIO_IRQ_EDGE_FALL)) {
        contador++;  // incrementa ao pressionar botão
    }
}

int main() {
    stdio_init_all();
    sleep_ms(2000); // espera a USB estabilizar

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true) {
        // também incrementa contador no loop principal
        contador++;
        printf("Contador: %d\n", contador);
        sleep_ms(200);
    }
}
