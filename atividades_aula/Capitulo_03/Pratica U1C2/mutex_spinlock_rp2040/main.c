#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/sync.h"  // já suficiente

#define BOTAO 5

volatile int contador = 0;
spin_lock_t *lock;

void gpio_callback(uint gpio, uint32_t events) {
    if (gpio == BOTAO && (events & GPIO_IRQ_EDGE_FALL)) {
        uint32_t flags = spin_lock_blocking(lock);
        contador++;
        printf("[ISR]  Contador: %d\n", contador);
        spin_unlock(lock, flags);
    }
}

int main() {
    stdio_init_all();
    sleep_ms(2000);

    lock = spin_lock_instance(31); // ou use SPINLOCK_ID_USER0 se seu SDK permitir

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true) {
        uint32_t flags = spin_lock_blocking(lock);
        contador++;
        printf("[MAIN] Contador: %d\n", contador);
        spin_unlock(lock, flags);
        sleep_ms(1000);
    }
}
