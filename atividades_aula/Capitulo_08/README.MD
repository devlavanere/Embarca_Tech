# Capítulo 8: Ethernet/WiFi

Este capítulo explora a **conectividade Ethernet e Wi-Fi** em sistemas embarcados, com foco no módulo Wi-Fi CYW43439 presente no **Raspberry Pi Pico W**. Abordamos desde a varredura de redes até a configuração de servidores web e pontos de acesso (Access Points).

---

## 🚀 Tópicos Abordados

* **Inicialização do Módulo Wi-Fi**: Configuração básica do hardware de comunicação.
* **Varredura de Redes Wi-Fi**: Descoberta de redes disponíveis (SSID, RSSI, canal, etc.).
* **Conexão a Redes Wi-Fi**: Processo de autenticação e obtenção de endereço IP.
* **Servidor HTTP Embarcado**: Implementação de um servidor web para controle remoto de dispositivos.
* **Modo Access Point (AP)**: Configuração do Raspberry Pi Pico W como um ponto de acesso, com serviços DHCP e DNS.

---

## 🛠️ Atividades e Experimentos Práticos na BitDogLab

Os experimentos abaixo foram realizados na BitDogLab, demonstrando a aplicação prática da conectividade Wi-Fi:

* **Experimento: `picow_blink`**:
    * **Objetivo**: Demonstrar a inicialização do módulo Wi-Fi CYW43439 e utilizar o LED interno controlado por esse módulo para piscar em intervalos regulares.
* **Experimento: `pico_scan`**:
    * **Objetivo**: Realizar varreduras periódicas por redes Wi-Fi disponíveis.
    * **Funcionamento**: A cada 10 segundos, escaneia redes próximas e imprime informações como SSID, força do sinal (RSSI), canal, MAC address e tipo de segurança.
* **Experimento: `pico_w_conect_ip`**:
    * **Objetivo**: Conectar o Raspberry Pi Pico W a uma rede Wi-Fi utilizando o módulo CYW43439 e exibir o endereço IP atribuído.
* **Experimento: `pico_w_led`**:
    * **Objetivo**: Conectar o Raspberry Pi Pico W a uma rede Wi-Fi, iniciar um servidor HTTP na porta 80 e permitir o controle de um LED por meio de comandos recebidos via navegador web.
    * **Funcionamento**: Exibe o nome da rede conectada e o endereço IP atribuído dinamicamente.
* **Experimento: `picow_access_point`**:
    * **Objetivo**: Configurar o Raspberry Pi Pico W como um ponto de acesso (Access Point) Wi-Fi.
    * **Funcionamento**: Inicia servidores DHCP e DNS locais para permitir a conexão de dispositivos clientes. Cria um servidor HTTP embarcado que disponibiliza uma página HTML de controle e permite o controle remoto de um LED conectado ao GPIO 0 através de comandos HTTP.

---

## 📚 Conceitos-Chave

* **Wi-Fi**: Tecnologia de rede sem fio para conexão de dispositivos à internet.
* **Raspberry Pi Pico W**: Versão do Raspberry Pi Pico com conectividade Wi-Fi e Bluetooth.
* **CYW43439**: Chip combinado de Wi-Fi e Bluetooth utilizado no Pico W.
* **SSID (Service Set Identifier)**: Nome de uma rede Wi-Fi.
* **RSSI (Received Signal Strength Indicator)**: Medida da força do sinal Wi-Fi.
* **Modo Estação (Station Mode)**: O dispositivo se conecta a um ponto de acesso existente.
* **Modo Access Point (AP Mode)**: O dispositivo atua como um ponto de acesso, permitindo que outros dispositivos se conectem a ele.
* **DHCP (Dynamic Host Configuration Protocol)**: Protocolo que atribui endereços IP automaticamente.
* **DNS (Domain Name System)**: Traduz nomes de domínio em endereços IP.
* **Servidor HTTP**: Software que hospeda páginas web e responde a requisições HTTP.

---

## 📝 Atividades de Avaliação

* **Questionário do Capítulo 4 - Temporizadores no AVA** (entrega em 14/05/2025).

---