# Capítulo 10: Foreground/Background

Este capítulo se dedica ao modelo de software **Foreground/Background**, uma arquitetura fundamental em sistemas embarcados que combina a execução contínua de tarefas de baixa prioridade (background) com a resposta imediata a eventos de alta prioridade (foreground) via interrupções. Exploramos a implementação, otimização e a transição do *polling* para interrupções na **Raspberry Pi Pico W**.

---

## Tópicos Abordados

* **Revisão do Modelo Foreground/Background**: Entendimento aprofundado da arquitetura.
* **Polling vs. Interrupções**: Comparação de técnicas para detecção de eventos e suas implicações em eficiência e responsividade.
* **Interrupções Seguras**: Uso da palavra-chave `volatile` e estratégias para garantir a integridade dos dados compartilhados.
* **Debounce de Botões**: Implementação de técnicas para evitar múltiplos registros de um único pressionamento.
* **Multicore com Filas Circulares**: Aplicação de múltiplos núcleos e filas para paralelismo e comunicação eficiente.
* **Controle de LEDs WS2812B (NeoPixel)**: Integração e controle de fitas de LEDs endereçáveis em um ambiente multitarefa.

---

## 🛠️ Atividades e Experimentos Práticos

As seguintes atividades práticas foram realizadas, demonstrando os conceitos do modelo Foreground/Background e suas otimizações:

### 1. Controle de LEDs com Botões (Raspberry Pi Pico) - Via Polling

* **Objetivo**: Implementar um sistema simples de controle de três LEDs utilizando três botões através da técnica de *polling* (verificação contínua).
* **Discussão**: Análise das **vantagens** (código simples e direto) e **desvantagens** (ineficiência energética, perda de eventos rápidos, dificuldade em gerenciar múltiplos eventos) do *polling*. Foi explorada também a diferença entre as funções `tight_loop_contents()` e `__wfi()` para otimização de loops e economia de energia.

### 2. Controle de LEDs com Interrupções no Raspberry Pi Pico - Refatoração

* **Objetivo**: Refatorar o projeto da Atividade 1 para o uso de **interrupções** em vez de *polling*.
* **Conceito**: Demonstra o uso da arquitetura Foreground/Background, onde o tratamento de eventos ocorre em duas camadas. Foi observada a importância da palavra-chave `volatile` para a compilação adequada do código quando há variáveis compartilhadas com interrupções.

### 3. Interrupções com Verificação de Estado e Debounce Seguro

* **Objetivo**: Aprimorar o controle de três LEDs com três botões físicos (A, B e o botão do joystick) usando uma lógica de interrupções mais robusta.
* **Funcionalidade**: Testes de funcionamento demonstraram que os LEDs reagem corretamente, alternando o estado apenas quando o botão correspondente é realmente pressionado, graças à efetividade do *debounce* e da verificação adicional do botão no loop principal.
* **Alteração Chave**: A função `gpio_callback` (ISR) foi modificada para apenas sinalizar o evento e desativar a interrupção do botão, delegando o tratamento completo e seguro para o loop principal. Isso exemplifica uma separação clara entre detecção e processamento.

### 4. Fila Circular com Multicore e LED RGB no Raspberry Pi Pico

* **Objetivo**: Utilizar os dois núcleos (cores) do microcontrolador RP2040 para implementar uma fila circular manipulada por pressões dos botões A e B.
* **Funcionamento**: O botão A insere um elemento na fila, e o botão B remove. O estado da fila é visualizado por um **LED RGB**: **Azul** (fila vazia), **Verde** (fila parcialmente preenchida) e **Vermelho** (fila cheia).
* **Conceito**: Demonstra como a utilização de dois núcleos permite que o processamento da fila ocorra separadamente do controle de interrupções, evidenciando o paralelismo entre as tarefas.

### 5. Controle de Fita NeoPixel com Multicore e Fila Circular

* **Objetivo**: Implementar o controle de LEDs WS2812B (NeoPixel) em uma matriz 5x5, utilizando dois núcleos (multicore) para distribuir as tarefas e uma fila circular para armazenar as ações.
* **Recursos**: Geração de cores aleatórias para acendimento dos LEDs, uso de *debounce* e verificação de pressão real dos botões, e sinalização visual por LEDs RGB externos indicando o estado da fila.

---

## 📚 Conceitos-Chave

* **Foreground/Background**: Modelo de arquitetura de software onde tarefas de alta prioridade (foreground, geralmente ISRs) interrompem tarefas de baixa prioridade (background, o loop principal).
* **Polling**: A técnica de verificar repetidamente o estado de um dispositivo ou entrada até que uma condição seja atendida.
* **Interrupção**: Um sinal assíncrono que suspende a execução normal do programa e desvia o controle para uma rotina de serviço de interrupção (ISR).
* **`volatile`**: Um qualificador de variável que instrui o compilador a não otimizar acessos a variáveis que podem ser modificadas por interrupções ou hardware externo.
* **Debounce**: Um processo de filtragem de ruídos em entradas digitais (como botões) para evitar que um único pressionamento seja interpretado como múltiplos.
* **Multicore**: Uma arquitetura de processador com dois ou mais núcleos de CPU, permitindo a execução paralela verdadeira de tarefas.
* **Fila Circular**: Uma estrutura de dados eficiente para comunicação assíncrona entre diferentes partes do código ou entre múltiplos núcleos.
* **WS2812B (NeoPixel)**: Um tipo de LED RGB endereçável individualmente, popular em projetos de iluminação e displays.

---