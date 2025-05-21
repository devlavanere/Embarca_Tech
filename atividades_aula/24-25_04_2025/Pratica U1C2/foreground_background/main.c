#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PRINCIPAL 12
#define LED_ALARME    11
#define BOTAO         5

volatile bool alarme_ativo = false;

void gpio_callback(uint gpio, uint32_t events) {
    if (gpio == BOTAO && (events & GPIO_IRQ_EDGE_FALL)) {
        alarme_ativo = true;
    }
}

int main() {
    stdio_init_all();

    gpio_init(LED_PRINCIPAL);
    gpio_set_dir(LED_PRINCIPAL, GPIO_OUT);

    gpio_init(LED_ALARME);
    gpio_set_dir(LED_ALARME, GPIO_OUT);

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true) {
        // Tarefa de fundo: piscar LED principal
        gpio_put(LED_PRINCIPAL, 1);
        sleep_ms(500);
        gpio_put(LED_PRINCIPAL, 0);
        sleep_ms(500);

        // Tarefa rápida ativada pela interrupção
        if (alarme_ativo) {
            gpio_put(LED_ALARME, 1);
            sleep_ms(200);
            gpio_put(LED_ALARME, 0);
            alarme_ativo = false;
        }
    }
}
