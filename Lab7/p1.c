#include <stdio.h>
#include <stdlib.h>

void printBits(unsigned n)
{
    int bits = sizeof(n) * 8;

    for(int i = bits - 1; i >= 0; -- i)
    {   
        if((n & (1u << i)) == 0)
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
unsigned getNibble(unsigned n, unsigned pos)
{
    return ((n & (0xF << pos)) >> pos);
}

//0001
//1000
unsigned reverseNibble(unsigned n)
{
    unsigned rev = 0;

    rev = rev ^ ((n & 1u) << 3);

    rev = rev ^ (((n & (1u << 1)) >> 1) << 2);

    rev = rev ^ (((n & (1u << 2)) >> 2) << 1);

    rev = rev ^ (((n & (1u << 3)) >> 3) << 0);

    return rev;
}

unsigned swapNibblesPos(unsigned n)
{
    unsigned nNib = sizeof(n) * 2;

    unsigned newNumber = 0;

    for(unsigned i = 0; i < nNib; ++ i)
    {
        unsigned nib = getNibble(n, i * 4u);

        newNumber = (newNumber << 4u) ^ nib;
    }

    return newNumber;
}

unsigned reverseBitsInsideNibble(unsigned n)
{  
    int nBits = sizeof(n) * 2;

    int newNumber = 0;

    for(int i = 0; i < nBits; ++ i)
    {
        int nibble = getNibble(n, i * 4);

        int reverseNib = reverseNibble(nibble);

        printf("reversed nibble: ");
        printBits(reverseNib);

        printf("\n");
    
        newNumber = newNumber ^ (reverseNib << (4 * i));
        
        printf("new number = ");
        printBits(newNumber);

        printf("\n");
        printf("\n");
    }

    return newNumber;
}

int main()
{
    printf("%d\n", swapNibblesPos(0xF1)); // F1 =    0000 0000 1111 0001

    printf("%d\n", swapNibblesPos(20480)); //20480 = 0101 0000 0000 0000
   
    printf("%d\n", swapNibblesPos(1024)); // 1024 =  0000 0100 0000 0000

    printf("%d\n", reverseBitsInsideNibble(2003)); // =>1110 1011 1100
    
    return 0;   
}
