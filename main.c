#include <stdio.h>
#include "led.h"

int main() 
{
    int n, m;
    int i, j;
    struct LED *leds;

    printf("Enter number of LEDs: ");
    scanf("%d", &n);

    printf("Enter number of times to toggle: ");
    scanf("%d", &m);

    leds = initialise(n);

    for (i = 0; i < n; i++)
     {
        if (i % 2 == 0)
         {
            reset(&leds[i]);
        } else 
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

    deallocate(leds, n);

    return 0;
}