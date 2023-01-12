#include <stdio.h>

float recursive_sum(int n)
{
    if(n == 1)
    {
        return 0;
    }   

    return (n - 5) / (n * n + n - 2) + recursive_sum(n - 1);
}
