#include <stdio.h>

int power(int x,int n)
{
    int result = 1;

    for(int i = 1; i <= n; ++ i)
    {
        result *= x; 
    }

    return result;
}

int factorial(int n)
{
    int result = 1;

    for(int i = 1; i <= n; ++ i)
    {
        result *= i;
    }
}

int expoTaylor(int n)
{
    
}
