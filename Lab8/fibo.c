#include <stdio.h>

unsigned fiboRec(unsigned n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        if(n == 1)
        {
            return 1;
        }
        else
        {
            return fiboRec(n - 1) + fiboRec(n - 2);
        }
    }
}

int main()
{
    printf("%d", fiboRec(5));
}
