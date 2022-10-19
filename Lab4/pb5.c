#include <stdio.h>

void primeFactors(int n)
{
    int power = 0, divisor = 2;
    int flagFirst = 1;

    while(n > 1)
    {
        power = 0;

        while(n % divisor == 0)
        {
            power++;

            n /= divisor;
        }

        if(power > 0)
        {
            // printf("Divisor: %d  at power: %d\n", divisor, power);

            if(power == 1)
            {
                if(flagFirst)
                {
                    printf("%d", divisor);
                    flagFirst = 0;
                }
                else
                {
                    printf("*%d", divisor);
                }
            }
            else
            {
                if(flagFirst)
                {
                    printf("%d^%d", divisor, power);
                    flagFirst = 0;
                }
                else
                {
                    printf("*%d^%d", divisor, power);
                }
            }
        }

        divisor++;

        if(n > 1 && divisor * divisor > n)
        {
            divisor = n;
        }
    }
}

int main()
{
    primeFactors(9);
    
    printf("\n");

    primeFactors(16);

    printf("\n");

    primeFactors(18);

    printf("\n");

    primeFactors(315);

    printf("\n");

    primeFactors(11);

    printf("\n");

    primeFactors(18);

    printf("\n");

    primeFactors(390);

    printf("\n");

    primeFactors(123456);
}
