#include "pico/stdlib.h"

#define GPIO_LED_RED 11 // Pino GPIO 11

/**
 * @brief Inicializa os componentes necessários.
 * 
 * Inicializa o componente GPIO 11, que é um LED Vermelho, como saída.
 */
void init_components();


/**
 * @brief Envia o sinal SOS em código Morse.
 * 
 * O sinal SOS consiste em três pontos, três traços e três pontos.
 * Com um intervalo de 250 ms entre cada letra, 
 * e um intervalo de 125 ms entre cada ponto e traço.
 */
void sos();


/**
 * @brief Envia um ponto (.) em código Morse.
 * 
 * Um ponto é um sinal curto, com duração de 200 ms.
 * E intervalo de 125 ms entre cada ponto.
 */
void ponto();


/**
 * @brief Envia um traço (-) em código Morse.
 * 
 * Um traço é um sinal longo, com duração de 800 ms.
 * E intervalo de 125 ms entre cada traço.
 */
void barra();


/**
 * @brief Função principal do programa.
 * 
 * Inicializa todos os componentes e entra em um loop infinito
 * enviando o sinal SOS a cada 3 segundos.
 * 
 * @return int Retorna 0 ao finalizar o programa.
 */
int main(){
    init_components();
    while (true) {
        sos();
        sleep_ms(3000); // Intervalo de 3 segundos entre cada sinal SOS.
    }
    return 0;
}


void init_components() {
    gpio_init(GPIO_LED_RED);
    gpio_set_dir(GPIO_LED_RED, GPIO_OUT);
}

void sos() {
    ponto();
    sleep_ms(250); // Intervalo de 250 ms entre cada letra.

    barra();
    sleep_ms(250); // Intervalo de 250 ms entre cada letra.

    ponto();
    // A ultima letra não precisa de intervalo.
}

void ponto() {
    for(int i = 0; i < 2; i++) {
        gpio_put(11, 1);
        sleep_ms(200);
        gpio_put(11, 0);
        sleep_ms(125); // Intervalo entre cada ponto, onde o LED fica apagado.
    }
    // O ultimo ponto não precisa de intervalo. E é feito fora do loop para evitar uma condição extra.
    gpio_put(11, 1);
    sleep_ms(200);
    gpio_put(11, 0);
}

void barra() {
    for(int i = 0; i < 3; i++) {
        gpio_put(11, 1);
        sleep_ms(800);
        gpio_put(11, 0);
        sleep_ms(125); // Intervalo entre cada ponto, onde o LED fica apagado.
    }
    // O ultimo traço não precisa de intervalo. E é feito fora do loop para evitar uma condição extra.
    gpio_put(11, 1);
    sleep_ms(800);
    gpio_put(11, 0);
}