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

void onReset()
{
    relay_Relay1(1);
    fase_activa = /* unsupported parameter type: emic-literal-boolean */;
    setTime1(60000, 'T');
}


void etOut1()
{
    if (fase_activa)
    {
        relay_Relay1(0);
        fase_activa = /* unsupported parameter type: emic-literal-boolean */;
        setTime1(60000, 'T');
    }
    else
    {
        relay_Relay1(1);
        fase_activa = /* unsupported parameter type: emic-literal-boolean */;
        setTime1(60000, 'T');
    }
}



