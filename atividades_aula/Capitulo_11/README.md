# Capítulo 9: Protocolos de Comunicação (IEEE 802.15.4, Bluetooth, Zigbee)

Este capítulo explora diversos **protocolos de comunicação sem fio** de curto alcance essenciais para sistemas embarcados e IoT. Focamos em **IEEE 802.15.4, Bluetooth e Zigbee**, com uma aplicação prática de descoberta de dispositivos Bluetooth na **Raspberry Pi Pico W**.

---

## Tópicos Abordados

* **IEEE 802.15.4**: Padrão para redes sem fio de baixa taxa de dados e baixo consumo de energia.
* **Bluetooth**: Tecnologia de comunicação sem fio de curto alcance para troca de dados entre dispositivos.
* **Bluetooth Low Energy (BLE)**: Versão otimizada do Bluetooth para baixo consumo de energia, ideal para dispositivos IoT.
* **Zigbee**: Protocolo de comunicação baseado em IEEE 802.15.4, focado em redes mesh e automação residencial/industrial.
* **Visibilidade e Descoberta de Dispositivos Bluetooth**: Como um dispositivo pode ser encontrado e como identificar outros dispositivos Bluetooth próximos.

---

## 🛠️ Atividades e Experimentos Práticos na BitDogLab

* **Experimento: `picow_ble_temp_sensor_with_wifi` - Visibilidade e Descoberta de Dispositivos Bluetooth**:
    * **Objetivo**: Visualizar o endereço Bluetooth da placa Raspberry Pi Pico W e outras redes visíveis.
    * **Ferramenta Utilizada**: Aplicativo **nRF Connect**, que permite escanear e analisar dispositivos Bluetooth próximos.
    * **Funcionamento**: O Pico W pode atuar como um beacon ou dispositivo GATT (Generic Attribute Profile) e ser descoberto por outros dispositivos Bluetooth.

---

## 📚 Conceitos-Chave

* **IEEE 802.15.4**: Base para protocolos como Zigbee e 6LoWPAN.
* **Bluetooth**: Protocolo de comunicação sem fio para dispositivos como fones de ouvido, teclados, etc.
* **Bluetooth Low Energy (BLE)**: Subconjunto do Bluetooth otimizado para aplicações de baixo consumo e baixa largura de banda.
* **Zigbee**: Protocolo de rede mesh sem fio para aplicações de automação.
* **Rede Mesh**: Topologia de rede onde cada nó pode retransmitir dados para outros nós, estendendo o alcance e a robustez.
* **MAC Address (Media Access Control Address)**: Identificador único de hardware para interfaces de rede.
* **Beacon**: Dispositivo Bluetooth que transmite pacotes de dados periodicamente para outros dispositivos.
* **GATT (Generic Attribute Profile)**: Estrutura de dados e procedimentos usados pelo BLE para organizar e trocar dados.

---

## 📝 Atividades de Avaliação

* **Nenhuma atividade de avaliação específica listada para este capítulo no cronograma fornecido.** O foco é no entendimento dos protocolos e suas aplicações.

---