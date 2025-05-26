/**
 * ------------------------------------------------------------
 * Arquivo: main.c
 * Projeto: TempCycleDMA
 * ------------------------------------------------------------
 * Descrição:
 * Ciclo principal do sistema embarcado, utilizando timers repetitivos
 * para gerenciar tarefas de forma assíncrona, sincronizadas pela
 * leitura de temperatura (Tarefa 1).
 *
 * Tarefa 1 - Leitura da temperatura via DMA.
 * Tarefa 2 - Análise da tendência da temperatura.
 * Tarefa 3 - Exibição da temperatura e tendência no OLED.
 * Tarefa 4 - Controle da matriz NeoPixel principal por tendência.
 * Tarefa 5 - Alerta de NeoPixel (pisca branco se temp < 1°C).
 *
 * O sistema utiliza watchdog para segurança, terminal USB
 * para monitoramento e display OLED para visualização direta.
 *
 * Data: 25/05/2025
 * ------------------------------------------------------------
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"

#include "setup.h"
#include "tarefa1_temp.h"
#include "tarefa2_display.h"
#include "tarefa3_tendencia.h"
#include "tarefa4_controla_neopixel.h"
#include "neopixel_driver.h"
#include "testes_cores.h"
#include "pico/stdio_usb.h"

// --- Variáveis Globais ---
float media;
tendencia_t t;

// Timestamps para medição de performance das tarefas
absolute_time_t ini_tarefa1, fim_tarefa1;
absolute_time_t ini_tarefa2_display, fim_tarefa2_display; // Mede a exibição no OLED
absolute_time_t ini_tarefa3_tendencia, fim_tarefa3_tendencia; // Mede a análise de tendência
absolute_time_t ini_tarefa4_neopixel_main, fim_tarefa4_neopixel_main; // Mede o controle do NeoPixel principal

// Flags voláteis para sincronização entre as callbacks do timer
volatile bool nova_leitura_temp_pronta = false;      // Sinaliza que a Tarefa 1 (Leitura) concluiu e 'media' está atualizada
volatile bool tendencia_calculada_pronta = false;    // Sinaliza que a Tarefa 2 (Tendência) calculou 't'
volatile bool neopixel_alerta_estado_ligado = false; // Para controle do pisca da Tarefa 5 (NeoPixel de Alerta)
absolute_time_t ultimo_pisca_tempo_alerta;           // Para controle de tempo da Tarefa 5

// --- Callbacks das Tarefas (chamadas pelos timers) ---

// Tarefa 1: Leitura de temperatura via DMA (Callback Principal)
// Esta callback é o ponto de partida para cada ciclo de dados.
bool tarefa1_callback_leitura(repeating_timer_t *rt) {
    ini_tarefa1 = get_absolute_time();
    media = tarefa1_obter_media_temp(&cfg_temp, DMA_TEMP_CHANNEL);
    fim_tarefa1 = get_absolute_time();

    // Sinaliza que a nova leitura de temperatura está pronta.
    nova_leitura_temp_pronta = true;
    // Reseta a flag de tendência para garantir que a Tarefa 2 (tendência) recalcule para os dados novos.
    tendencia_calculada_pronta = false;

    // DEBUG: Informa o estado da Tarefa 1
    printf("\n[T1] Leitura de Temperatura: %.2f C | Tempo: %.3f ms\n",
           media, absolute_time_diff_us(ini_tarefa1, fim_tarefa1) / 1000.0);
    printf("     Flags: temp_pronta=%d, tendencia_calc_pronta=%d\n", nova_leitura_temp_pronta, tendencia_calculada_pronta);

    return true; // Retorna true para que o timer continue chamando esta callback
}

// Tarefa 2: Análise da Tendência Térmica
// Depende da leitura da temperatura (Tarefa 1).
bool tarefa2_callback_tendencia(repeating_timer_t *rt) {
    // Só executa se houver nova leitura de temperatura E a tendência ainda não foi calculada para esta leitura.
    if (nova_leitura_temp_pronta && !tendencia_calculada_pronta) {
        ini_tarefa3_tendencia = get_absolute_time(); // Mede a "Tarefa 3"(Análise de Tendência)
        t = tarefa3_analisa_tendencia(media);
        fim_tarefa3_tendencia = get_absolute_time();
        tendencia_calculada_pronta = true; // Sinaliza que a tendência foi calculada

        // DEBUG: Informa o estado da Tarefa 2 (Tendência)
        printf("[T2] Analise de Tendencia: %s | Tempo: %.3f ms\n",
               tendencia_para_texto(t), absolute_time_diff_us(ini_tarefa3_tendencia, fim_tarefa3_tendencia) / 1000.0);
        printf("     Flags: temp_pronta=%d, tendencia_calc_pronta=%d\n", nova_leitura_temp_pronta, tendencia_calculada_pronta);
    } else {
        // DEBUG: Informa se a condição não foi atendida
        // printf("[T2] Nao executada (temp_pronta=%d, tendencia_calc_pronta=%d)\n", nova_leitura_temp_pronta, tendencia_calculada_pronta);
    }
    return true;
}

// Tarefa 3: Exibição no OLED
// Depende da leitura da temperatura (Tarefa 1) e da tendência (Tarefa 2).
bool tarefa3_callback_display(repeating_timer_t *rt) {
    // Só executa se houver nova leitura de temperatura E a tendência já foi calculada.
    if (nova_leitura_temp_pronta && tendencia_calculada_pronta) {
        ini_tarefa2_display = get_absolute_time(); // Mede a "Tarefa 2" do seu original (Exibição no OLED)
        tarefa2_exibir_oled(media, t);
        fim_tarefa2_display = get_absolute_time();

        // DEBUG: Informa o estado da Tarefa 3 (Display)
        printf("[T3] Exibicao OLED (Media: %.2f, Tendencia: %s) | Tempo: %.3f ms\n",
               media, tendencia_para_texto(t), absolute_time_diff_us(ini_tarefa2_display, fim_tarefa2_display) / 1000.0);
    } else {
        // DEBUG: Informa se a condição não foi atendida
        // printf("[T3] Nao executada (temp_pronta=%d, tendencia_calc_pronta=%d)\n", nova_leitura_temp_pronta, tendencia_calculada_pronta);
    }
    return true;
}

// Tarefa 4: Controle da Matriz NeoPixel Principal por Tendência
// Depende da tendência (Tarefa 2).
bool tarefa4_callback_neopixel_main(repeating_timer_t *rt) {
    // Só executa se houver nova leitura de temperatura E a tendência já foi calculada.
    if (nova_leitura_temp_pronta && tendencia_calculada_pronta) {
        ini_tarefa4_neopixel_main = get_absolute_time(); // Mede a "Tarefa 4" do seu original (Controle NeoPixel)
        tarefa4_matriz_cor_por_tendencia(t); // Esta função deve chamar npWrite()!
        fim_tarefa4_neopixel_main = get_absolute_time();

        // DEBUG: Informa o estado da Tarefa 4 (NeoPixel Principal)
        printf("[T4] Controle NeoPixel Principal (Tendencia: %s) | Tempo: %.3f ms\n",
               tendencia_para_texto(t), absolute_time_diff_us(ini_tarefa4_neopixel_main, fim_tarefa4_neopixel_main) / 1000.0);
    } else {
        // DEBUG: Informa se a condição não foi atendida
        // printf("[T4] Nao executada (temp_pronta=%d, tendencia_calc_pronta=%d)\n", nova_leitura_temp_pronta, tendencia_calculada_pronta);
    }
    return true;
}

// Tarefa 5: Alerta de NeoPixel (pisca branco se temperatura < 1°C) - NÃO BLOQUEANTE
// Esta tarefa usa a 'media' diretamente e tem sua própria lógica de temporização para o pisca.
bool tarefa5_callback_alerta_neopixel(repeating_timer_t *rt) {
    // Só processa se houver nova leitura de temperatura para o ciclo atual
    if (nova_leitura_temp_pronta) {
        if (media < 1.0f) {
            absolute_time_t tempo_atual = get_absolute_time();
            // Verifica se já passou tempo suficiente para alternar o estado do LED (500ms = 500000 us)
            if (absolute_time_diff_us(ultimo_pisca_tempo_alerta, tempo_atual) >= 500000) {
                if (neopixel_alerta_estado_ligado) {
                    npClear(); // Desliga todos os NeoPixels
                } else {
                    npSetAll(COR_BRANCA); // Liga todos os NeoPixels na cor branca
                }
                npWrite(); // Envia os dados para os NeoPixels
                neopixel_alerta_estado_ligado = !neopixel_alerta_estado_ligado; // Inverte o estado
                ultimo_pisca_tempo_alerta = tempo_atual; // Atualiza o tempo do último pisca

                // DEBUG: Informa o estado do NeoPixel de Alerta
                printf("[T5] Alerta NeoPixel: Condicao (media < 1.0f) ATENDIDA! Media=%.2fC. NeoPixel %s\n",
                       media, neopixel_alerta_estado_ligado ? "LIGADO" : "DESLIGADO");
            }
        } else {
            // Se a condição (media < 1.0f) não for mais verdadeira, garante que o NeoPixel esteja desligado por esta tarefa.
            if (neopixel_alerta_estado_ligado) { // Verifica se estava ligado por esta tarefa antes de desligar
                npClear();
                npWrite();
                neopixel_alerta_estado_ligado = false; // Reseta o estado
                // DEBUG:
                printf("[T5] Alerta NeoPixel: Condicao media < 1.0f NAO ATENDIDA. NeoPixel DESLIGADO.\n");
            }
        }
    } else {
        // DEBUG: Informa se a condição não foi atendida
        // printf("[T5] Nao executada (temp_pronta=%d)\n", nova_leitura_temp_pronta);
    }
    return true;
}


// --- Função Principal ---
int main() {
    setup(); // Inicializa todos os componentes de hardware (ADC, DMA, PIO para NeoPixel, OLED, etc.)

    // Ativa o watchdog com timeout de 2 segundos.
    // O '1' no segundo parâmetro permite que o watchdog pause durante a depuração.
    watchdog_enable(2000, 1);
    watchdog_update(); // "Alimenta" o watchdog pela primeira vez

    // Inicializa o tempo para o controle do pisca da Tarefa 5.
    ultimo_pisca_tempo_alerta = get_absolute_time();

    // Declaração dos objetos repeating_timer_t para cada tarefa
    repeating_timer_t timer_leitura_temp;
    repeating_timer_t timer_analise_tendencia;
    repeating_timer_t timer_exibicao_display;
    repeating_timer_t timer_controle_neopixel_main;
    repeating_timer_t timer_alerta_neopixel;

    // --- Configuração dos Timers Repetitivos ---
    // Todos os timers são configurados para rodar a cada 1000ms (1 segundo).
    // A ordem de 'add_repeating_timer_ms' NÃO garante a ordem de execução das callbacks!
    // A SINCRONIZAÇÃO É FEITA PELAS FLAGS DENTRO DE CADA CALLBACK, garantindo as dependências.

    // Tarefa 1 (Leitura de Temp): Primária, inicia o ciclo de dados.
    add_repeating_timer_ms(1000, tarefa1_callback_leitura, NULL, &timer_leitura_temp);

    // Tarefa 5 (NeoPixel Alerta): Usa 'media', não precisa da 'tendencia'.
    add_repeating_timer_ms(1000, tarefa5_callback_alerta_neopixel, NULL, &timer_alerta_neopixel);

    // Tarefa 2 (Análise de Tendência): Depende da 'media' de T1.
    add_repeating_timer_ms(1000, tarefa2_callback_tendencia, NULL, &timer_analise_tendencia);

    // Tarefa 3 (Display OLED): Depende de 'media' e 'tendencia'.
    add_repeating_timer_ms(1000, tarefa3_callback_display, NULL, &timer_exibicao_display);

    // Tarefa 4 (NeoPixel Principal): Depende de 'tendencia'.
    add_repeating_timer_ms(1000, tarefa4_callback_neopixel_main, NULL, &timer_controle_neopixel_main);


    // --- Loop Principal (Muito leve, apenas alimenta watchdog e pode imprimir resultados finais) ---
    while (true) {
        // Alimenta o watchdog regularmente para evitar reset do sistema.
        watchdog_update();

        // O loop principal agora só espera e permite que as callbacks façam o trabalho.
        // A impressão dos resultados completos é feita dentro das callbacks ou,
        // neste exemplo, um resumo pode ser feito aqui se todas as flags estiverem prontas.
        // A lógica de impressão dos tempos de execução foi movida para as próprias callbacks

        tight_loop_contents(); // Reduz o consumo de energia quando não há nada a fazer.
    }

    return 0;
}