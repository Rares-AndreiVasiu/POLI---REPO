#include<stdio.h>
#include <stdlib.h>

void printBits(unsigned n)
{
    int nBits = sizeof(n) * 8;

    for(int k = nBits - 1; k >= 0; -- k)
    {
        if((n & (1u << k)) == 0)
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

unsigned getNibble(unsigned n, unsigned i)
{
    unsigned nibble = (n & (0xF << i)) >> i;

    return nibble;
}

unsigned reverseNibbles(unsigned n)
{
    unsigned nNib = sizeof(n) * 2;

    unsigned newNumber = 0;

    for(int i = 0; i < nNib; i ++)
    {
        unsigned nib = getNibble(n, i * 4);

        newNumber = (newNumber << 4) ^ nib;
    }

    return newNumber;
}

int main()
{
    printf("%d\n", reverseNibbles(167));
}
