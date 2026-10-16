#include <stdio.h>
#include <stdlib.h>
#include "led.h"
#include <conio.h>

int main(void)
{
    int n, m;
    int i, j;
    struct LED *leds;

    printf("Enter number of LEDs: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        fprintf(stderr, "Error: Invalid number of LEDs.\n");
        return 1;
    }

    printf("Enter number of times to toggle: ");
    if (scanf("%d", &m) != 1 || m < 0)
    {
        fprintf(stderr, "Error: Invalid number of toggle cycles.\n");
        return 1;
    }

    leds = initialise(n);
    if (leds == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            reset(&leds[i]);
        }
        else
        {
            set(&leds[i]);
        }
    }

    printf("\nInitial States:\n");
    display(leds, n);

    for (j = 1; j <= m; j++)
    {
        for (i = 0; i < n; i++)
        {
            toggle(&leds[i]);
        }
        printf("Cycle %d: ", j);
        display(leds, n);
    }

    getch();

    deallocate(leds, n);

    return 0;
}