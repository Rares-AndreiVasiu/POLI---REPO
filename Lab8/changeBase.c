#include <stdio.h>
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

int getNiblle(unsigned n, unsigned k)
{
    return ((n & (0xF << k)) >> k);
}

int decToHex(unsigned n, unsigned newNumber, unsigned base, unsigned pos, unsigned nNib)
{
    if(pos == nNib)
    {
        return newNumber;
    }
    else
    {
        unsigned nib = getNiblle(n, pos * 4);

        printBits(nib);

        printf("pos = %d\n", pos);

        return decToHex(n, newNumber + base * nib, base * 16, pos + 1, nNib);
    }
}

int decToHexWrapper(unsigned n)
{
    unsigned nNib = sizeof(n) * 2;

    return decToHex(n, 0, 1, 0, nNib);
}

int main()
{
    unsigned n = 0x312;

    printBits(n);

    printf("%d", decToHexWrapper(n));
}

// 0000000000000000 0011 0001 0010 1111
