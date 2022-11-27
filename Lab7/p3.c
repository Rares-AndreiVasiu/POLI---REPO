#include <stdio.h>
#include <stdlib.h>



u_int16_t EveryOrderBit(u_int32_t n)
{
    u_int16_t newNumber = 0;

    for(int i = 0; i < 32; i += 2)
    {
        printf("pos:%d,  bit: %d\n", i, ((n & (1u << i)) >> i));

        newNumber = newNumber ^ (((n & (1u << i)) >> i) << (i / 2));
    }

    return newNumber;
}

//1000 0001 1110 1111 1110 0001 1111 0111
//
int main()
{
    u_int32_t n = 2179981815;

    u_int16_t x = EveryOrderBit(n);

    printf("%d", x); 
}
/*
pos:0,  bit: 1
pos:2,  bit: 1
pos:4,  bit: 1
pos:6,  bit: 1

pos:8,  bit: 1
pos:10,  bit: 0
pos:12,  bit: 0
pos:14,  bit: 1

pos:16,  bit: 1
pos:18,  bit: 1
pos:20,  bit: 0
pos:22,  bit: 1

pos:24,  bit: 1
pos:26,  bit: 0
pos:28,  bit: 0
pos:30,  bit: 0

=>0001 1011 1001 1111

*/
