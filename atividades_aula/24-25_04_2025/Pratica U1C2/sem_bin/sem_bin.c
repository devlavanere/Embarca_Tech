#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_BOTAO 5
#define PIN_LED   11

volatile bool flag_semaforo = false;

// Interrupção do botão
void isr_botao() {
    flag_semaforo = true;
}

int main() {
    stdio_init_all();
    sleep_ms(2000);  // Aguarda conexão via USB

    // Inicializa botão
    gpio_init(PIN_BOTAO);
    gpio_set_dir(PIN_BOTAO, GPIO_IN);
    gpio_pull_up(PIN_BOTAO);
    gpio_set_irq_enabled_with_callback(PIN_BOTAO, GPIO_IRQ_EDGE_FALL, true, &isr_botao);

    // Inicializa LED
    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED, GPIO_OUT);
    gpio_put(PIN_LED, 0); // Desliga LED

    while (true) {
        if (flag_semaforo) {
            flag_semaforo = false; // Consome o semáforo

            // Ação: piscar LED
            gpio_put(PIN_LED, 1);
            sleep_ms(200);
            gpio_put(PIN_LED, 0);
            printf("Sinal recebido! LED piscou.\n");
        }
        sleep_ms(10); // Evita uso excessivo da CPU
    }
}
