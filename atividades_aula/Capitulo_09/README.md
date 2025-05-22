# Capítulo 9: Executor Cíclico

Este capítulo explora uma estratégia avançada de organização de software em sistemas embarcados: o **Executor Cíclico**. Focamos na implementação de um sistema robusto e eficiente, utilizando a **BitDogLab (Raspberry Pi Pico W)** para demonstrar como garantir a periodicidade e a organização das tarefas.

---

## Tópicos Abordados

* **Executor Cíclico**: Modelo de execução de tarefas baseado em um ciclo de tempo fixo ou adaptativo.
* **Organização de Tarefas**: Como estruturar o código para garantir a execução periódica e ordenada de rotinas.
* **Otimização do Loop Principal**: Técnicas para evitar bloqueios e garantir a responsividade do sistema.
* **Integração de Periféricos**: Exemplos de como incorporar sensores (temperatura), displays (OLED) e atuadores (NeoPixel) em um sistema cíclico.
* **Uso de Watchdog para Segurança**: Implementação de mecanismos de watchdog para recuperação de travamentos do sistema.

---

## 🛠️ Atividades e Experimentos Práticos na BitDogLab

Os experimentos abaixo demonstram a aplicação prática do Executor Cíclico:

### 1. Executor Cíclico

* **Projeto 1 - `TempCycleDMA`**:
    * **Objetivo**: Analisar um código que realiza um ciclo contínuo de tarefas, como medição de temperatura, exibição em display OLED, análise de tendência térmica e controle de uma matriz NeoPixel.
    * **Observação**: Demonstra como a mudança na ordem das tarefas no loop principal pode alterar significativamente o comportamento e a prioridade das rotinas.
* **Projeto 2 - `TrendWatch`**:
    * **Objetivo**: Implementar um sistema de monitoramento de temperatura em tempo real, exibir tendências em um display OLED, controlar LEDs (NeoPixel/GPIO) e utilizar um watchdog para garantir a segurança e a recuperação do sistema.
    * **Vantagens Observadas**: Recuperação automática de travamentos (graças ao Watchdog), monitoramento via USB dos tempos de execução das tarefas e boa separação das responsabilidades entre as tarefas.
    * **Pontos de Melhoria**: A necessidade de remover *shadowing* de variáveis em `tarefa_4()`, reintroduzir `sleep_ms()` ou usar um timer fixo para controle do ciclo, e verificar se `tarefa_5()` respeita os *deadlines* em cenários de alta carga.

---

## 📚 Conceitos-Chave

* **Executor Cíclico**: Um padrão de design de software em que as tarefas são executadas em uma sequência predefinida e repetida dentro de um ciclo de tempo, geralmente controlada por um timer ou um atraso fixo.
* **Periodicidade**: A garantia de que uma tarefa será executada em intervalos de tempo regulares.
* **Responsividade**: A capacidade do sistema de reagir a eventos e entradas em tempo hábil.
* **Watchdog Timer**: Um periférico de hardware que ajuda a recuperar o sistema de travamentos de software. Ele exige que o software o "alimente" periodicamente; caso contrário, reinicia o microcontrolador.
* **OLED (Organic Light Emitting Diode)**: Um tipo de display que oferece alto contraste e baixo consumo de energia.
* **NeoPixel (WS2812B)**: LEDs RGB endereçáveis individualmente, controlados por um único pino de dados, ideais para efeitos de iluminação complexos.

---