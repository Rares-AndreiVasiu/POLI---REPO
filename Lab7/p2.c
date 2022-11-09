#include <stdio.h>
#include <stdlib.h>

unsigned consecutiveBits(unsigned n)
{
    int segments = 1; //we start from 1 since there is guaranteed one segment

    unsigned nBits = sizeof(n) * 8;

    for(int i = 0; i < nBits - 1; ++ i)
    {
        unsigned m1 = (n & (1u << i));

        unsigned m2 = (n & (1u << (i + 1)));

        if(m2 != (m1 << 1))
        {
            segments ++;
        }
    }

    return segments;
}

int main()
{
    printf("%d\n", consecutiveBits(000100));

    printf("%d\n", consecutiveBits(000000));

    printf("%d\n", consecutiveBits(0101));
}
/*
00 0100 = n

00 0001 = m1
00 0010 = m2

00 0010 = m1
00 0100 = m2
*/
