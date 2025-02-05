#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define Led_Vermelho 13
#define Led_Azul 12
#define Led_Verde 11

int semaforo = 0;

bool sinalizacao(struct repeating_timer *t)
{
    semaforo = (semaforo + 1);
    if (semaforo > 2)
    {
        semaforo = 0;
    }
    switch (semaforo)
    {
    case 0:
        // led Vermelho ligado
        gpio_put(Led_Vermelho, 1);
        gpio_put(Led_Azul, 0);
        gpio_put(Led_Verde, 0);
        break;

    case 1:
        // Led Azul ligado
        gpio_put(Led_Vermelho, 0);
        gpio_put(Led_Azul, 1);
        gpio_put(Led_Verde, 0);
        break;

    case 2:
        // Led Verde ligado
        gpio_put(Led_Vermelho, 0);
        gpio_put(Led_Azul, 0);
        gpio_put(Led_Verde, 1);
    }
}

int main()
{

    stdio_init_all();

    gpio_init(Led_Vermelho);
    gpio_set_dir(Led_Vermelho, GPIO_OUT);

    gpio_init(Led_Azul);
    gpio_set_dir(Led_Azul, GPIO_OUT);

    gpio_init(Led_Verde);
    gpio_set_dir(Led_Verde, GPIO_OUT);

    gpio_put(Led_Vermelho, 1);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, sinalizacao, NULL, &timer);

    while (true)
    {
        printf("Se beber, não dirija!\n");
        sleep_ms(1000);
    }

    return 0;
}
