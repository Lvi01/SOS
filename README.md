Descrição do Algoritmo:

Este algoritmo é implementado para um microcontrolador Raspberry Pi Pico e utiliza a biblioteca pico/stdlib.h para controlar um LED conectado ao pino GPIO 11. O objetivo do algoritmo é enviar o sinal SOS em código Morse repetidamente. O sinal SOS é composto por três pontos, três traços e três pontos, com intervalos específicos entre cada sinal.

Funcionalidades Principais:
- Inicialização dos Componentes: A função init_components() configura o pino GPIO 11 como saída.
- Envio do Sinal SOS: A função sos() envia a sequência de sinais em código Morse correspondente ao SOS.
- Envio de Pontos e Traços: As funções ponto() e barra() enviam pontos e traços em código Morse, respectivamente, controlando o estado do LED (ligado/desligado) e os intervalos de tempo apropriados.
- Estrutura do Código

Inicialização:

init_components(): Configura o pino GPIO 11 como saída.

Loop Principal:

A função sos() é chamada repetidamente a cada 3 segundos para enviar o sinal SOS.

Funções Auxiliares:

ponto(): Envia um ponto (.) em código Morse.
barra(): Envia um traço (-) em código Morse.

O algoritmo foi simulado no Wokwi através do link: https://wokwi.com/projects/419552104397774849
