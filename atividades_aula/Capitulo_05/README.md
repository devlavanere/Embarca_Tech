# Capítulo 5: DMA (Direct Memory Access)

Este capítulo aborda o **DMA (Direct Memory Access)**, um controlador que permite a transferência de dados entre a memória e periféricos (ou entre diferentes regiões da memória) sem a intervenção direta da CPU. Exploramos como o DMA otimiza o desempenho de sistemas embarcados na **BitDogLab (Raspberry Pi Pico W)**.

---

## Tópicos Abordados

* **Conceito de DMA**: Entendimento do que é DMA e como ele funciona para otimizar o desempenho do sistema.
* **Vantagens do DMA**: Redução da carga da CPU, aumento da eficiência e velocidade de transferência de dados.
* **Configuração de Canais DMA**: Como programar os canais DMA para diferentes tipos de transferências (memória para memória, periférico para memória, etc.).
* **Recursos Avançados do DMA**: Exploração de funcionalidades como *control blocks* dinâmicos e o recurso "sniffer" para cálculo de CRC.

---

## 🛠️ Atividades e Experimentos Práticos na BitDogLab

Os experimentos abaixo foram realizados na BitDogLab, demonstrando a aplicação prática do DMA:

* **Experimento: `hello_dma2`**:
    * **Objetivo**: Demonstrar o uso básico do DMA para copiar dados de um buffer de origem (`src`) para um buffer de destino (`dst`) sem utilizar a CPU.
* **Experimento: `DMA_MEMO`**:
    * **Objetivo**: Copiar palavras digitadas pelo terminal automaticamente via DMA do buffer `src` para `dst`, com limpeza dos buffers.
* **Experimento: `DMA_PWM`**:
    * **Objetivo**: Controlar o brilho de um LED conectado à GPIO 12 utilizando Modulação por Largura de Pulso (PWM) e DMA.
* **Experimento: `DMA_ADC_TEMP`**:
    * **Objetivo**: Realizar a leitura da temperatura interna do RP2040 utilizando o ADC e transferir os dados para um buffer usando DMA, permitindo leituras rápidas e eficientes.
    * **Funcionamento**: Calcula a média de 100 amostras e imprime a temperatura em °C a cada segundo.
* **Experimento: `Control_blocks3`**:
    * **Objetivo**: Demonstrar o uso de dois canais DMA no RP2040 para realizar uma transmissão sequencial de palavras via UART, sem intervenção da CPU, utilizando *control blocks* dinâmicos.
* **Experimento: `sniff_src`**:
    * **Objetivo**: Demonstrar o uso do recurso "sniffer" do DMA do RP2040 para calcular automaticamente o CRC32 de um buffer de dados.
    * **Funcionamento**: O DMA calcula o CRC internamente enquanto transfere os dados, sendo útil para validar a integridade de blocos de memória.

---

## 📚 Conceitos-Chave

* **DMA (Direct Memory Access)**: Controlador que permite transferências de dados diretamente entre a memória e periféricos (ou entre regiões da memória) sem a sobrecarga da CPU.
* **Canais DMA**: Unidades independentes dentro do controlador DMA que podem ser configuradas para realizar transferências específicas.
* **Control Blocks**: Estruturas de dados que contêm todas as informações necessárias para que um canal DMA execute uma transferência (origem, destino, tamanho, modo).
* **Sniffer DMA**: Um recurso específico do RP2040 que permite calcular somas de verificação (como CRC) durante a transferência de dados via DMA.
* **Eficiência da CPU**: O principal benefício do DMA é liberar a CPU para executar outras tarefas enquanto as transferências de dados ocorrem em segundo plano.

---

## 📝 Atividades de Avaliação

* **Questionário do Capítulo 5 - DMA no AVA**.
* **Entrega da Atividade de envio do Capítulo 5**: "Aplicação DMA - Sistema de Aquisição de Temperatura com DMA e Interface I2C em Microcontrolador RP2040".

---