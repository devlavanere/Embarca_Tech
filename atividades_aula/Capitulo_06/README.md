# Capítulo 6: USB (Universal Serial Bus)

Este capítulo explora o uso do periférico **USB (Universal Serial Bus)** em microcontroladores, com foco na sua aplicação no **Raspberry Pi Pico (RP2040)**. Abordamos a comunicação USB como um dispositivo, simulando diferentes perfis HID (Human Interface Device) e de comunicação serial (CDC).

---

## Tópicos Abordados

* **Fundamentos do USB**: Entendimento básico da comunicação USB.
* **USB como Dispositivo**: Como o microcontrolador se apresenta para um computador host.
* **Periférico USB no RP2040**: Utilização das capacidades USB do microcontrolador.
* **Biblioteca TinyUSB**: Uma biblioteca de código aberto para implementação de dispositivos USB.
* **Perfis USB Comuns**:
    * **CDC (Communication Device Class)**: Simulação de uma porta serial virtual (UART sobre USB).
    * **HID (Human Interface Device)**: Implementação de dispositivos como teclado, mouse, controle de consumidor e gamepad.

---

## 🛠️ Atividades e Experimentos Práticos (Wokwi / BitDogLab)

Os experimentos abaixo foram realizados, demonstrando a aplicação prática do USB:

* **Comandos**:
    * **Objetivo**: Demonstrar como o periférico USB no Raspberry Pi Pico pode receber comandos específicos originados do computador.
* **TinyUSB\_CDC**:
    * **Objetivo**: Utilizar o periférico USB do RP2040 em conjunto com a biblioteca TinyUSB para simular um dispositivo CDC.
    * **Funcionamento**: O dispositivo ecoa de volta as informações recebidas do computador, atuando como uma porta serial virtual.
* **Hid\_composite\_consumer\_control**:
    * **Objetivo**: Implementar um dispositivo USB HID customizado focado exclusivamente na funcionalidade de Consumer Control (controle de mídia, volume, etc.).
    * **Base**: Projeto modificado do `dev_hid_composite` original da biblioteca TinyUSB.
* **Hid\_composite**:
    * **Objetivo**: Implementar um dispositivo USB HID composto, suportando múltiplas funcionalidades simultaneamente.
    * **Funcionalidades Suportadas**: Teclado, mouse, controle de consumidor (Consumer Control) e gamepad.

---

## 📚 Conceitos-Chave

* **USB (Universal Serial Bus)**: Padrão de comunicação universal para conectar periféricos a um computador.
* **Host USB**: O computador que controla a comunicação USB (ex: PC).
* **Dispositivo USB**: O periférico que se conecta ao host (ex: Raspberry Pi Pico W).
* **TinyUSB**: Uma pilha USB de código aberto e leve, otimizada para microcontroladores.
* **CDC (Communication Device Class)**: Classe de dispositivo USB que permite ao dispositivo atuar como uma porta serial virtual.
* **HID (Human Interface Device)**: Classe de dispositivo USB para entrada de dados (teclados, mouses, gamepads, etc.).
* **HID Composto**: Um único dispositivo USB que implementa múltiplas funcionalidades HID simultaneamente.

---

## 📝 Atividades de Avaliação

* **Nenhuma atividade de avaliação específica listada para este capítulo no cronograma fornecido.** Os conceitos abordados aqui são fundamentais para o desenvolvimento de interfaces com o usuário e comunicação com sistemas host.

---