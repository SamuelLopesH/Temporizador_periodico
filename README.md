# Semaforo com Raspberry Pi Pico

Este projeto implementa um semáforo simples utilizando um Raspberry Pi Pico. O código controla três LEDs (Vermelho, Azul e Verde) que alternam em intervalos de tempo definidos, simulando o funcionamento de um semáforo.

## Componentes Necessários

- Raspberry Pi Pico
- 1 LED Vermelho
- 1 LED Azul
- 1 LED Verde
- Resistores (220Ω recomendado para cada LED)
- Protoboard e jumpers

## Esquema de Conexão

- **LED Vermelho**: Conectado ao pino GP13
- **LED Azul**: Conectado ao pino GP12
- **LED Verde**: Conectado ao pino GP11
- **GND**: Todos os LEDs devem ser conectados ao GND através de resistores.

## Funcionamento

O código utiliza um timer periódico para alternar entre os estados do semáforo a cada 3 segundos. A sequência de estados é:

1. **Vermelho**: LED Vermelho ligado, Azul e Verde desligados.
2. **Azul**: LED Azul ligado, Vermelho e Verde desligados.
3. **Verde**: LED Verde ligado, Vermelho e Azul desligados.

Após o estado Verde, o ciclo reinicia no estado Vermelho.

## Como Executar

1. Conecte os componentes conforme o esquema de conexão.
2. Compile e carregue o código no Raspberry Pi Pico.
3. O semáforo começará a funcionar automaticamente, alternando entre os LEDs.

## Links Úteis

- **Simulação no Wokwi**: [Clique aqui para acessar a simulação](https://wokwi.com/projects/422011343762927617)
- **Repositório no GitHub**: [Clique aqui para acessar o repositório](https://github.com/SamuelLopesH/Temporizador_periodico)

## Código

O código está disponível no arquivo `main.c` deste repositório.

