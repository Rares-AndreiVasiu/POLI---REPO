#include <stdio.h>
#include <stdlib.h>

void printBits(u_int32_t n)
{
    int nBits = sizeof(n) * 8;

    for(int k = nBits - 1; k >= 0; k--)
    {
        if( (n & (1 << k)) == 0)
        {
            putchar('0');
        }
        else
        {
            putchar('1');
        }
    }

    printf("\n");
}

u_int32_t swapHalves(u_int32_t a)
{
    // printBits(((a & 0xFFFF0000) >> 16));

    // printBits(((a & 0xFFFF) << 16));

    return ((a & 0xFFFF0000) >> 16) | ((a & 0xFFFF) << 16);
}

u_int32_t rotswap(u_int32_t x)
{
    unsigned L = sizeof(x) * 8 - 4;

    // we extract the leftmost nibble
    u_int32_t leftMostNibble = (x & (0xF << L)) >> L;

    // we leftshift the number by 4 and inseret the leftmost in the righmost
    x = (x << 4) | (leftMostNibble);

    //we swap the 16-bit halves

    x = swapHalves(x);

    return x;
}

u_int32_t minRotSwap(u_int32_t n)
{
    u_int32_t minimum = 0xFFFFFFFF;

    unsigned nNib = sizeof(n) * 2;

    for(unsigned i = 1; i <= nNib; i ++ )
    {
        n = rotswap(n);

        printBits(n);

        if(n < minimum)
        {
            // printf("%u\n", minimum);

            minimum = n;
        }
    }

    return minimum;
}

int main()
{
    printf("%u", minRotSwap(1578));

    return 0;
}
