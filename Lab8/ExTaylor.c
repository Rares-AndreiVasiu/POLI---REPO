#include <stdio.h>

int computePower(int x, int power)
{
    int result = 1;

    for(int i = 1; i <= power; ++ i)
    {
        result *= x;
    }

    return result;
}

double exponentialTaylor(int x, unsigned long long factorial, double current, int index)
{
    if(current <= 1e-6)
    {
        return current;
    }
    else
    {   
        current = (double)computePower(x, index) / factorial;

        // printf("%.9f %lld %d\n", current, factorial, index);

        return current + exponentialTaylor(x, factorial * (index + 1), current, index + 1);        
    }   
}

// we start automatically from position 1
// bc the series will be 1 + x + (x ^ 2) / 2!
//                       0   1      2
double expTaylor(int x)
{
    return 1 + exponentialTaylor(x, 1ULL, 1, 1);
}

int main()
{
    printf("%.9f\n", expTaylor(2));

    return 0;
}
//0.000001 = 1e-6