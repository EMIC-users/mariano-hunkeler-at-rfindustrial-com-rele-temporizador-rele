#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_LED1.h"
#include "inc/led_LED2.h"
#include "inc/led_LED3.h"
#include "inc/relay_Relay1.h"
#include "inc/relay_Relay2.h"
#include "inc/timer_api1.h"
#include "inc/EMICBus.h"

/* User Variables */
bool fase_activa = true;
uint16_t contador_minutos = 0;

void onReset()
{
    relay_Relay1(1);
    fase_activa = 1;
    contador_minutos = 0;
    setTime1(60000, 'A');
}


void etOut1()
{
    contador_minutos = contador_minutos + 1;
    if (fase_activa)
    {
        if (contador_minutos >= 10)
        {
            relay_Relay1(0);
            fase_activa = 0;
            contador_minutos = 0;
        }
    }
    else
    {
        if (contador_minutos >= 60)
        {
            relay_Relay1(1);
            fase_activa = 1;
            contador_minutos = 0;
        }
    }
}



