#include <stdio.h>
#include <stdlib.h>

void printBits(u_int32_t n)
{
    int nBits = sizeof(n) * 8;

    for(int k = nBits - 1; k >= 0; k--)
    {
        if((n & (1 << k)) == 0)
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

unsigned getBit(u_int32_t n, unsigned k)
{
    return ((n & (1 << k)) >> k);
}

u_int16_t insertBit(u_int16_t n, int k, unsigned bit)
{
    return (n | (bit << k));
}

u_int16_t evenBitLeftRight(u_int32_t n)
{
    u_int16_t newNumber = 0;

    unsigned nBits = sizeof(n) * 8;

    for(int k = nBits - 2; k >= 0; k -= 2)
    {
        unsigned bit = getBit(n, k);
        
        newNumber = insertBit(newNumber, k / 2, bit);

        printBits(newNumber);
    }

    return newNumber;
}

u_int16_t evenBitRightLeft(u_int32_t n)
{
    u_int16_t newNumber = 0;

    unsigned nBits = sizeof(n) * 8;

    for(int k = nBits - 2; k >= 0; k -= 2)
    {
        unsigned bit = getBit(n, k);
        
        newNumber = insertBit(newNumber, k / 2, bit);

        printBits(newNumber);
    }

    //perform reversing of newNumber

    u_int16_t result = 0;

    while(newNumber)
    {
        result <<= 1;

        if((newNumber & 1) == 1)
        {
            result ^= 1;
        }

        newNumber >>= 1;
    }

    return result;
}

int main()
{
    printf("%X\n", evenBitLeftRight(0xFABAFFFF));

    printf("%X\n", evenBitRightLeft(0xFABAFFFF));

    return 0;
}

/*
n = FABA FFFF
1111 1010 1011 1010 1111 1111 1111 1111
31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0
1  1   1  1  1  0 1  0  1  0  1  1  1  0  1  0  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1
I => 1100010011111111
 
II => 1111111100100011
      1111111100100011
*/
