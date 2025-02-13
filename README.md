# Semáforo com Temporizador Periódico no Raspberry Pi Pico

Este projeto implementa um semáforo simples utilizando o microcontrolador **Raspberry Pi Pico W** e LEDs para simular os sinais de trânsito: vermelho, amarelo e verde. O semáforo altera os sinais a cada 3 segundos com um temporizador periódico que alterna os LEDs com base no tempo.

## Objetivo

O objetivo deste projeto é implementar um semáforo com LEDs (vermelho, amarelo e verde) utilizando a função `add_repeating_timer_ms()` do **Pico SDK**, que permite realizar a troca periódica de sinais a cada 3 segundos. O projeto também envia mensagens para a porta serial a cada 1 segundo, permitindo o acompanhamento do funcionamento do semáforo.

## Requisitos

### Hardware

- **Microcontrolador**: Raspberry Pi Pico W
- **LEDs**: 3 LEDs (vermelho, amarelo e verde)
- **Resistores**: 3 resistores de 330 Ω

### Software

- **Pico SDK** (com suporte para funções de temporizador)
- **Ambiente de desenvolvimento** com suporte ao C e ao Pico SDK
- **Ferramenta Educacional BitDogLab** para experimentação com o LED RGB (GPIOs 11, 12, 13)

## Fluxograma de Atuação

A operação do semáforo segue o fluxograma simplificado abaixo:

1. O semáforo inicia com a luz **vermelha** acesa.
2. Após 3 segundos, a luz **amarela** é acesa.
3. Após mais 3 segundos, a luz **verde** é acesa.
4. A sequência se repete indefinidamente.

## Funcionalidade do Temporizador

- **Tempo de Alteração de Sinal**: A troca de LEDs ocorre a cada 3 segundos (3000ms).
- **Função de Call-Back**: A troca de estado dos LEDs é gerenciada por uma função de call-back que é executada a cada 3 segundos pelo temporizador.

## Configuração do Hardware

O código utiliza os pinos GPIO 11, 12 e 13 do Raspberry Pi Pico para controlar os LEDs:

- **LED Vermelho**: GPIO 13
- **LED Amarelo**: GPIO 12
- **LED Verde**: GPIO 11

## Fluxo do Código

1. **Inicialização dos LEDs**: Inicializamos os pinos dos LEDs como saídas.
2. **Temporizador Repetitivo**: Usamos a função `add_repeating_timer_ms()` para executar a função de troca de LEDs a cada 3 segundos.
3. **Sequência de LEDs**: A cada execução do temporizador, alternamos entre os LEDs vermelho, amarelo e verde, de acordo com o fluxograma.
4. **Impressão na Porta Serial**: A cada 1 segundo (1000ms), uma mensagem é enviada pela porta serial para monitoramento.
