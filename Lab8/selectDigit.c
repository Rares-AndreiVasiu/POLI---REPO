#include <stdio.h>

// we construct a number with digits on even pos in n

unsigned selectDigits(unsigned n, unsigned number, unsigned pos, unsigned power)
{
    if(n == 0)
    {
        return number;
    }
    else
    {
        if(!(pos & 1u))
        {
            unsigned digit = n % 10;

            return selectDigits(n / 10, number + digit * power, pos + 1, power * 10);
        }
        else
        {
            return selectDigits(n / 10, number, pos + 1, power);
        }
    }
}

unsigned selectDigitsWrapper(unsigned n)
{
    return selectDigits(n, 0u, 1u, 1u);
}

int main()
{
    printf("%u\n", selectDigitsWrapper(2826124));
}

// 2 8 2 6 1 2 4
// 1 2 3 4 5 6 7
