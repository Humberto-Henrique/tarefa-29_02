#include "pico/stdlib.h"
#include "hardware/timer.h"
#include <stdio.h>

#define LED_VERMELHO 13 // LED vermelho
#define LED_AMARELO 12  // LED amarelo
#define LED_VERDE 11    // LED verde

// Funções para acender os LEDs
void acende_vermelho() {
    gpio_put(LED_VERMELHO, true);
    gpio_put(LED_AMARELO, false);
    gpio_put(LED_VERDE, false);
}

void acende_amarelo() {
    gpio_put(LED_VERMELHO, false);
    gpio_put(LED_AMARELO, true);
    gpio_put(LED_VERDE, false);
}

void acende_verde() {
    gpio_put(LED_VERMELHO, false);
    gpio_put(LED_AMARELO, false);
    gpio_put(LED_VERDE, true);
}

bool repeating_timer_callback(struct repeating_timer *t) {
    static int estado = 1;

    switch (estado) {
        case 0:
            acende_vermelho();
            estado = 1;
            break;
        case 1:
            acende_amarelo();
            estado = 2;
            break;
        case 2:
            acende_verde();
            estado = 0;
            break;
    }
    return true;
}

int main() {
    stdio_init_all();

    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    
    acende_vermelho();

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Semáforo ativo\n");
        sleep_ms(1000);
    }

    return 0;
}
