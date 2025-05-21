#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_PIN     12
#define BUTTON_PIN  5

volatile bool alternar_led = false;
bool estado_led = false;
uint32_t periodo_ms = 1000;  // começa com 1 segundo
bool botao_anterior = true;

int64_t temporizador_callback(alarm_id_t id, void *user_data) {
    alternar_led = true;
    return periodo_ms;
}

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    add_alarm_in_ms(periodo_ms, temporizador_callback, NULL, true);

    while (true) {
        bool botao_atual = gpio_get(BUTTON_PIN);

        // Borda de descida do botão
        if (botao_anterior && !botao_atual) {
            periodo_ms = (periodo_ms == 1000) ? 500 : 1000;
            printf("Novo período: %u ms\n", periodo_ms);
        }
        botao_anterior = botao_atual;

        if (alternar_led) {
            estado_led = !estado_led;
            gpio_put(LED_PIN, estado_led);
            printf("LED = %d\n", estado_led);
            sleep_ms(periodo_ms / 4); // tempo perceptível de transição
            alternar_led = false;
        }

        tight_loop_contents();
    }
}
