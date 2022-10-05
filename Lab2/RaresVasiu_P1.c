#include <stdio.h>

void ErrorLog(int x)
{
    printf("Number %d is divisible by 10 can't have its least significant digit swaped with its most significant digit\n", x);
}

int swapLMD(unsigned x)
{
    unsigned mostSignificantDigit = x / 100;
    unsigned leastSignificantDigit = x % 10;

    if (leastSignificantDigit != 0)
    {
        x = leastSignificantDigit * 100 + ((x / 10) % 10) * 10 + mostSignificantDigit;

        return x;
    }

    return -1;
}

int main()
{
    unsigned x, output;

    x = 102;

    output = swapLMD(x);

    if (output != -1)
    {
        printf("%d\n", output);
    }
    else
    {
        ErrorLog(x);
    }

    x = 100;

    output = swapLMD(x);

    if (output != -1)
    {
        printf("%d\n", output);
    }
    else
    {
        ErrorLog(x);
    }
}