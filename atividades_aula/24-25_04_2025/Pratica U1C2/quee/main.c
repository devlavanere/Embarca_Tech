#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/util/queue.h"

#define LED_GPIO 11
#define BUTTON_GPIO 5

// Fila com capacidade para 10 inteiros
queue_t fila;

// Função que roda no Core 1
void core1_entry() {
    int valor;
    while (true) {
        if (queue_try_remove(&fila, &valor)) {
            if (valor == 1) {
                gpio_put(LED_GPIO, 1); // Liga LED
            } else {
                gpio_put(LED_GPIO, 0); // Desliga LED
            }
        }
    }
}

int main() {
    stdio_init_all();

    gpio_init(LED_GPIO);
    gpio_set_dir(LED_GPIO, GPIO_OUT);

    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    // Inicializa fila
    queue_init(&fila, sizeof(int), 10);

    // Inicia segundo núcleo
    multicore_launch_core1(core1_entry);

    while (true) {
        // Lê botão
        bool pressed = !gpio_get(BUTTON_GPIO); // botão com pull-up
        int valor = pressed ? 1 : 0;

        // Envia valor para o outro núcleo
        queue_try_add(&fila, &valor);

        sleep_ms(100); // debounce + redução de carga
    }

    return 0;
}
