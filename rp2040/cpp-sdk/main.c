/**
 ***********************************************************************************************
 *                Controlling R.Pi Pico or RP2040 through C++ Pico SDK                         *
 *                                           by AKM_Machine                                    *
 ***********************************************************************************************
*/

/*========Libraries=========*/
#include "pico/stdlib.h"
//Standard IO thru USB Serial
#include <stdio.h>

/*==============Macros===============*/
#define LED 25

/*============Prototypes=============*/
void io_init();

/*==============MAIN==============*/
int main()
{
    io_init();

    //begin serial communication (BAUD rate won't matter)
    stdio_init_all();

    // Super Loop
    for (;;)
    {
        printf("Hi\n");

        gpio_put(LED, true);
        // sleep_ms(1000);
        busy_wait_ms(5000);
        gpio_put(LED, false);
        sleep_ms(5000);
        // busy_wait_ms(1000);
    }
}


/*=========Function definitions============*/
void io_init()
{
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
}