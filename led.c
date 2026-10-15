#include <stdio.h>
#include <stdlib.h>
#include "led.h"

struct LED* initialise(int n)
{
    int i;
    struct LED *leds;

    leds = (struct LED *)malloc(n * sizeof(struct LED));

    for (i = 0; i < n; i++)
     {
        leds[i].led_no = i + 1;
        leds[i].status = (int *)malloc(sizeof(int));
        *(leds[i].status) = OFF;
    }

    return leds;
}

void set(struct LED *led) 
{
    *(led->status) = ON;
}

void reset(struct LED *led) 
{
    *(led->status) = OFF;
}

void toggle(struct LED *led) 
{
    if (*(led->status) == ON) 
    {
        *(led->status) = OFF;
    } else 
    {
        *(led->status) = ON;
    }
}

void display(struct LED *leds, int n) 
{
    int i;
    for (i = 0; i < n; i++)
        if (*(leds[i].status) == ON)
        {
            printf("[LED %d: ON] ", leds[i].led_no);
        } else 
        {
            printf("[LED %d: OFF] ", leds[i].led_no);
        }
    }
    printf("\n");
}

void deallocate(struct LED *leds, int n)
{
    int i;

    for (i = 0; i < n; i++) 
    {
        free(leds[i].status);
    }

    free(leds);
}