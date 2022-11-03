#include <stdio.h>

void printBits(unsigned n)
{
    int nrBits = sizeof(n) * 8;

    for(int k = nrBits - 1; k >= 0; --k)
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
}

void printHexNib(unsigned n)
{
    int nrNibHex = sizeof(n) * 2;

    for (int k = nrNibHex - 1; k >= 0; --k)
    {
        int nib = (n & (0xF << (k * 4))) >> (k * 4);

        putchar(nib < 10 ? '0' + nib: 'A' + nib - 10);
    }  
}

int main()
{
    // printBits(0xABCDEF);

    printHexNib(0xF);

    printf("\n");

     printHexNib(10);

    printf("\n");

     printHexNib(11);

    printf("\n");

     printHexNib(0xB0);
}
