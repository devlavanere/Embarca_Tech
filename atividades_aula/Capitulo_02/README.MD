# Capítulo 2: Modelos Multitarefa em Aplicações em Sistemas Embarcados

Este capítulo aprofunda os modelos multitarefa, abordando desde as estruturas mais simples até técnicas avançadas de comunicação e sincronização em sistemas embarcados. Exploramos o **Superloop**, **Foreground/Background** e a utilização de **múltiplos núcleos (Multicore)** na **BitDogLab (Raspberry Pi Pico W)**.

---

## Tópicos Abordados

* **Modelos Multitarefa Fundamentais**:
    * **Superloop**: Estrutura básica onde as tarefas são executadas em sequência contínua.
    * **Foreground/Background**: Modelo que utiliza interrupções para tratar eventos assíncronos, enquanto o laço principal executa tarefas rotineiras.
* **Sincronização e Comunicação**:
    * Uso de **variáveis globais** entre ISRs e o loop principal.
    * Implementação de **filas circulares** para comunicação Produtor/Consumidor.
* **Concorrência e Exclusão Mútua**:
    * Utilização de **spinlocks** no RP2040 para proteger seções críticas.
* **Multicore no RP2040**:
    * Execução de **tarefas simultâneas em dois núcleos**.
    * **Comunicação entre núcleos** via FIFO (First-In, First-Out).

---

## 🛠️ Atividades e Experimentos Práticos na BitDogLab

### 1. Implementação de Modelos Multitarefa Básicos

* **Superloop - Piscar LED e Ler Botão**:
    * **Objetivo**: Demonstrar a estrutura de um sistema com superloop.
    * **Funcionamento**: Tarefas executadas em sequência fixa e contínua, sem interrupções nem temporizadores.
* **Foreground/Background - Interrupção por Botão**:
    * **Objetivo**: Implementar o modelo Foreground/Background.
    * **Funcionamento**: Tarefas rotineiras no laço principal e eventos assíncronos tratados por interrupções para respostas imediatas.

### 2. Exploração de Exemplos Avançados de Multitarefa

* **Cooperativo - Temporizador com `add_alarm_in_ms()`**:
    * Demonstração de temporizador cooperativo baseado em callback, controlando o piscar de um LED.
* **Variavel\_global\_entre\_ISR\_loop - Comunicação por Variável Global**:
    * Uso de uma variável global para comunicação entre uma rotina de interrupção (ISR) e o laço principal.
* **Fila\_circular - Simulação de Fila Circular (produtor/consumidor)**:
    * Simulação de uma fila circular em C para o padrão produtor-consumidor sem RTOS, operando cooperativamente.
* **Led\_dinamico\_btn - Controle de Tempo com Botão (LED dinâmico)**:
    * Permite alterar o tempo de piscar do LED dinamicamente usando um botão.
* **Mutex\_spinlock\_rp2040 - Exclusão Mútua com Spinlock**:
    * Utilização de spinlocks no RP2040 para proteger seções críticas em ambientes concorrentes.
* **Multitask\_2core - Multitarefa com Dois Núcleos**:
    * Uso dos dois núcleos do RP2040 para tarefas simultâneas (Core 0 controla LED, Core 1 imprime mensagens).
* **Multicore\_fifo\_troca - Multitarefa com Dois Núcleos (FIFO)**:
    * Comunicação entre os dois núcleos do RP2040 usando a FIFO interna para troca de valores sincronizada.

---

## 📚 Conceitos-Chave

* **Superloop**: Estrutura simples, sequencial e contínua.
* **Foreground/Background**: Modelo com interrupções para eventos rápidos e loop principal para rotinas.
* **Interrupção (ISR)**: Rotina de serviço de interrupção que responde a eventos assíncronos.
* **Variável Global**: Meio de comunicação entre diferentes partes do código, incluindo ISRs.
* **Fila Circular**: Estrutura de dados para comunicação eficiente entre processos ou tarefas.
* **Exclusão Mútua**: Mecanismo para garantir acesso exclusivo a recursos compartilhados.
* **Spinlock**: Um tipo de mecanismo de exclusão mútua em ambientes multicore.
* **Multicore**: Arquitetura com múltiplos núcleos de processamento, permitindo paralelismo real.
* **FIFO (First-In, First-Out)**: Estrutura de dados para comunicação ordenada, utilizada entre os núcleos do RP2040.

---

## 📝 Atividades de Avaliação

* **Questionário do Capítulo 2 no AVA**.
* **Entrega da Atividade Capítulo 2 no AVA**: "Aplicação Multitarefa - Criação de uma Estação de Monitoramento Interativo".

---