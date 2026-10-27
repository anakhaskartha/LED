#include <stdio.h>

int bitwise_add(int a, int b)
{
    while (b != 0)
    {
        unsigned int carry = (unsigned int)(a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int bitwise_subtract(int a, int b)
{
    int negative_b = bitwise_add(~b, 1);
    return bitwise_add(a, negative_b);
}

int bitwise_multiply(int a, int b)
{
    int result = 0;
    int is_negative = 0;

    if ((a < 0 && b > 0) || (a > 0 && b < 0))
    {
        is_negative = 1;
    }

    if (a < 0)
        a = bitwise_add(~a, 1);
    if (b < 0)
        b = bitwise_add(~b, 1);

    while (b > 0)
    {
        if (b & 1)
        {
            result = bitwise_add(result, a);
        }
        a = a << 1;
        b = b >> 1;
    }

    if (is_negative)
    {
        result = bitwise_add(~result, 1);
    }

    return result;
}

int main(void)
{
    int x, y;

    printf("Enter the value of x and y:\n");
    scanf("%d%d", &x, &y);

    printf("Addition:       %d + %d = %d\n", x, y, bitwise_add(x, y));
    printf("Subtraction:    %d - %d = %d\n", x, y, bitwise_subtract(x, y));
    printf("Multiplication: %d * %d = %d\n", x, y, bitwise_multiply(x, y));

    return 0;
}