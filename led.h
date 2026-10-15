#ifndef LED_H
#define LED_H

#define OFF 0
#define ON  1

struct LED 
{
    int led_no;
    int *status;
};

struct LED* initialise(int n);
void set(struct LED *led);
void reset(struct LED *led);
void toggle(struct LED *led);
void display(struct LED *leds, int n);
void deallocate(struct LED *leds, int n);

#endif