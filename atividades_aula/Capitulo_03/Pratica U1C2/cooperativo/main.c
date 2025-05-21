#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_PIN 12

volatile bool alternar_led = false;
bool estado_led = false;

// Callback chamado a cada 1000 ms
int64_t temporizador_callback(alarm_id_t id, void *user_data) {
    alternar_led = true;
    return 1000; // repete o callback a cada 1000 ms
}

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Inicia o temporizador cooperativo
    add_alarm_in_ms(1000, temporizador_callback, NULL, true);

    while (true) {
        if (alternar_led) {
            estado_led = !estado_led;
            gpio_put(LED_PIN, estado_led);
            printf("LED = %d\n", estado_led);

            // Permite visualização do piscar
            sleep_ms(1000);

            alternar_led = false;
        }

        tight_loop_contents(); // cooperação sem bloqueio
    }
}
