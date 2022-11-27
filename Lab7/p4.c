#include <stdio.h>
#include <ctype.h>

void printBase32(unsigned n)
{
    unsigned index = 0;

    char result[101];

    while(n)
    {
        int remainder = n % 32;

        if(remainder < 10)
        {
            remainder += '0';
        }
        else
        {
            remainder += ('A' - 10);
        }

        result[index ++] = (char)remainder;

        n /= 32;
    }

    result[index] = '\n';

    for(int i = index - 1; i >= 0; -- i)
    {
        putchar(result[i]);
    }
    
    putchar('\n');
}

int main()
{
    printBase32(1234);

    return 0;
}
