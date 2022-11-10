#include <stdio.h>
#include <stdlib.h>

u_int32_t getBit(u_int32_t n, unsigned k)
{
    return ((n & (1u << k)) >> k);
}

u_int16_t inserBit(u_int16_t x, unsigned k, unsigned bit)
{
    return (x | (1u << k));
}

u_int16_t bitEvenLeftRight(u_int32_t n)
{
    u_int16_t result = 0;

    unsigned nBits = sizeof(n) * 8;

    for(int k = nBits - 2; k >= 0; k -=2)
    {
        if(((n & (1u << k))) == 0)
        {
            result ^= (0 << (k / 2));
        }
        else
        {
            result ^= (1 << (k / 2));
        }
    }

    return result;
}

u_int16_t bitEvenRightLeft(u_int32_t n)
{
    unsigned nBits = sizeof(n) * 8;

    u_int16_t newNumber = 0;

    for(unsigned k = 0; k <= nBits; k += 2)
    {
        unsigned bit = getBit(n, k);

        newNumber = inserBit(newNumber, k / 2, bit);
    }

    return newNumber;
}

int main()
{
    printf("%X\n", bitEvenRightLeft(0x0A12C301));

    return 0;
}
