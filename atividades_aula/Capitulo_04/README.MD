# Capítulo 4: Temporizadores

Este capítulo explora o uso essencial de **temporizadores (timers)** em microcontroladores para gerenciar o tempo, criar atrasos precisos e agendar eventos. Abordamos diferentes tipos de timers e suas aplicações práticas na **BitDogLab (Raspberry Pi Pico W)** e no simulador **Wokwi**.

---

## Tópicos Abordados

* **Fundamentos de Timers**: Entendimento de como os timers funcionam e sua importância.
* **Tipos de Temporizadores**:
    * **Temporizadores Repetitivos (Periódicos)**: Para tarefas que precisam ser executadas em intervalos regulares.
    * **Temporizadores One-Shot**: Para eventos que ocorrem uma única vez após um atraso.
* **Timers de Sistema e Hardware**: Diferenças e aplicação prática de ambos.
* **Timers como Contadores**: Utilização de timers para contar eventos externos.

---

## 🛠️ Atividades e Experimentos Práticos (Wokwi / BitDogLab)

Os experimentos abaixo demonstram a aplicação prática de temporizadores:

* **Blink Sem Timer**:
    * Demonstração de tarefas simultâneas no loop infinito **sem usar timers**, evidenciando limitações.
* **Blink Com Timer**:
    * Demonstração do uso de **timers** para tratar eventos fora do laço infinito, liberando a CPU.
* **Temporizador Repetitivo**:
    * Funcionamento de um temporizador periódico fora do Loop Infinito, liberando a CPU.
* **Temporizador One Shot 1 e 2**:
    * Funcionamento de temporizadores não-repetitivos (One Shot) fora do Loop Infinito, para eventos únicos com atraso.
* **Temporizador de Sistema 1**:
    * Uso de um Timer de Sistema com funções de tempo absoluto (`time_reached()`) para agendamento de eventos.
* **Temporizador de Hardware 1**:
    * Uso de um temporizador de hardware repetitivo para acionar uma função (`repeating_timer_callback()`) periodicamente.
* **Temporizador de Sistema 2**:
    * Controla um LED, ligando-o por um evento externo (botão) e desligando-o automaticamente após um tempo definido por um alarme.
* **Temporizador de Hardware 2**:
    * Similar ao Timer de Sistema 2, mas utilizando funções da biblioteca `hardware/timer.h` para controle de LED.
* **Contador**:
    * Uso do Timer como um “Contador” para eventos externos, como pulsos de um sensor ou acionamento de um botão.

---

## 📚 Conceitos-Chave

* **Timer**: Um periférico ou recurso de software que gera atrasos ou eventos em intervalos de tempo específicos.
* **Temporizador Repetitivo (Periódico)**: Ativa uma função ou evento repetidamente em intervalos de tempo fixos.
* **Temporizador One-Shot**: Ativa uma função ou evento uma única vez após um período de tempo definido.
* **Timer de Sistema**: Abstração de software que utiliza um timer de hardware para fornecer funcionalidades de temporização.
* **Timer de Hardware**: Um componente físico no microcontrolador dedicado à contagem de tempo, operando de forma independente da CPU.
* **Callback**: Uma função que é passada como argumento para outra função e é executada quando um evento ocorre (ex: timer expira).

---

## 📝 Atividades de Avaliação

* **Questionário do Capítulo 4 - Temporizadores no AVA**.
* **Entrega da Atividade de envio do Capítulo 4**: "Temporizadores - Semáforo de Trânsito Interativo no AVA".

---