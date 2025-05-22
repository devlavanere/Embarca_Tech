# Capítulo 3: Tratamento de Interrupções

Este capítulo aborda o **tratamento de interrupções**, um mecanismo crucial em sistemas embarcados para responder a eventos de forma imediata e eficiente. Exploramos diversas fontes de interrupção e suas aplicações práticas na **BitDogLab (Raspberry Pi Pico W)**.

---

## Tópicos Abordados

* **Interrupções de GPIO**: Resposta a mudanças de estado em pinos digitais.
* **Interrupções de Comunicação (UART)**: Gerenciamento de recebimento de dados seriais.
* **Interrupções de ADC (Conversor Analógico-Digital)**: Notificação de conclusão de conversões analógicas.
* **Watchdog Timer (WDT)**: Detecção e recuperação de travamentos do sistema.
* **Interrupções de Timer**: Geração de eventos temporizados e periódicos.
* **Interrupções de DMA (Direct Memory Access)**: Notificação sobre a conclusão de transferências de dados.
* **Interrupções de PWM (Pulse Width Modulation)**: Disparo de eventos relacionados ao controle de PWM.

---

## 🛠️ Atividades e Experimentos Práticos na BitDogLab

Os experimentos abaixo foram realizados na BitDogLab, demonstrando a aplicação prática de interrupções:

* **Controle de LED via Interrupções com Dois Botões** (`isr_botao_bitdoglab`):
    * Ligar/desligar LEDs acionados por interrupções de GPIO.
* **Recepção de Dados via UART USB e Controle de LED** (`isr_uart_bitdoglab`):
    * Controlar um LED com base em dados recebidos via UART, utilizando interrupções.
* **Leitura Periódica de Joystick usando ADC e Interrupção** (`isr_adc_irq_bitdoglab`):
    * Leitura eficiente do valor analógico de um joystick, disparando interrupções ao final da conversão ADC.
* **Detecção de Travamentos com Watchdog Timer** (`isr_wdt_reset_bitdoglab`):
    * Demonstração do WDT para reiniciar o microcontrolador em caso de travamento.
* **Alimentação Periódica do Watchdog Timer** (`isr_wdt1_bitdoglab`):
    * Implementação da alimentação do WDT para prevenir reinicializações indesejadas.
* **Disparo de Alarme Temporizado via Timer e Interrupção** (`isr_timer_bitdoglab`):
    * Uso de um timer para gerar interrupções em intervalos definidos.
* **Transferência de Dados usando DMA e Interrupção** (`isr_dma_bitdoglab`):
    * Transferência de dados via DMA com interrupção ao final da operação para notificar a CPU.
* **Controle de um Buzzer via PWM e Interrupção** (`isr_pwm_bitdoglab`):
    * Geração de tons ou controle de buzzer usando PWM, com interrupções para gerenciar o sinal.

---

## 📚 Conceitos-Chave

* **Interrupção**: Sinal de hardware ou software que suspende a execução normal do programa para executar uma rotina específica (ISR).
* **ISR (Interrupt Service Routine)**: Função de tratamento de interrupção.
* **Watchdog Timer (WDT)**: Periférico que reinicia o sistema se o software não o "alimentar" periodicamente, prevenindo travamentos.
* **DMA (Direct Memory Access)**: Mecanismo para transferência de dados entre memória e periféricos sem intervenção da CPU, liberando o processador.

---

## 📝 Atividades de Avaliação

* **Questionário Interrupções no AVA**.
* **Entrega da Atividade de envio do Capítulo 3**: "Aplicação Tratamento de Interrupções - Sistema para Monitoramento de Som com Interrupção de Timer".

---