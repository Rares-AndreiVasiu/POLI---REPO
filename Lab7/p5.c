#include <stdio.h>
#include <stdlib.h>

unsigned bitwiseAddition(unsigned a, unsigned b)
{
    unsigned carrier = 0;

    // b will hold the left-shifted carry
    // we loop untill there is no more carry to compute <=> b != 0
    while(b != 0)
    {
        // Step 1: we perform the bitwise & to find the position of carries
        carrier = a & b;     

        // Step 2: we do the "actual addition" with XOR
        // we want to have "a" the addition result
        a = (a ^ b);
        
        // Step 3: we don't add the raw carry, but one position to the left
        b = (carrier << 1);
    }

    return a;
}

int main()
{
    unsigned a = 1, b = 3;

    printf("%d\n", bitwiseAddition(a, b));
}
