#include <stdio.h>
#include <stdlib.h>
#include "led.h"

struct LED *initialise(int n)
{
    int i;
    struct LED *leds;

    if (n <= 0)
    {
        return NULL;
    }

    leds = (struct LED *)malloc(n * sizeof(struct LED));
    if (leds == NULL)
    {
        return NULL;
    }

    for (i = 0; i < n; i++)
    {
        leds[i].led_no = i + 1;
        leds[i].status = OFF;
    }

    return leds;
}

void set(struct LED *led)
{
    if (led != NULL)
    {
        led->status = ON;
    }
}

void reset(struct LED *led)
{
    if (led != NULL)
    {
        led->status = OFF;
    }
}

void toggle(struct LED *led)
{
    if (led != NULL)
    {
        led->status = (led->status == ON) ? OFF : ON;
    }
}

void display(struct LED *leds, int n)
{
    int i;
    if (leds == NULL || n <= 0)
    {
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (leds[i].status == ON)
        {
            printf("[LED %d: ON] ", leds[i].led_no);
        }
        else
        {
            printf("[LED %d: OFF] ", leds[i].led_no);
        }
    }

    printf("\n");
}

void deallocate(struct LED *leds, int n)
{
    (void)n;
    free(leds);
}