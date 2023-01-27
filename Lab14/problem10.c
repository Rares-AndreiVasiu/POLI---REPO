#include <stdio.h>
#include <stdlib.h>

struct prime_factor
{
    unsigned prime;
    unsigned exponent;
};

struct number
{
    unsigned number_of_factors;

    struct prime_factor *factors;
};

typedef struct prime_factor prime_t;
typedef struct number num_t;

prime_t init_prime_t(unsigned pr, unsigned exp)
{
    prime_t a;

    a.prime = pr;
    a.exponent = exp;

    return a;
}

num_t multiply(num_t a, num_t b)
{
    num_t result;

    result.number_of_factors = 0;
    
    result.factors = malloc(sizeof(num_t) * (a.number_of_factors + b.number_of_factors));

    if(!result.factors)
    {
        printf("Error while allocating memory!\n");

        return (num_t){0, NULL};
    }
    
    int i = 0, j = 0, index = 0;

    while(i < a.number_of_factors && j < b.number_of_factors)
    {
        if(a.factors[i].prime < b.factors[j].prime)
        {
            result.factors[index++] = a.factors[i++]; 
        }
        else
        {
            if(a.factors[i].prime > b.factors[j].prime)
            {
                result.factors[index++] = b.factors[j++];
            }
            else
            {
                //both prime factors are equal but
                //might differ in power
                prime_t new_prime = init_prime_t(a.factors[i].prime, a.factors[i].exponent + b.factors[j].exponent);

                result.factors[index++] = new_prime;

                i++;
                j++;
            }
        }
    }

    while(i < a.number_of_factors)
    {
        result.factors[index++] = a.factors[i];
        i++;
    }

    while(j < b.number_of_factors)
    {
        result.factors[index++] = b.factors[j];
        j++;
    }

    result.number_of_factors = index;

    return result;
}

int main()
{
    num_t a = {2, (prime_t[]){{2, 3}, {3,2}}};
    num_t b = {3, (prime_t[]){{2, 1}, {3,1},{5,1}}};

    num_t c = multiply(a, b);

    for(int i = 0; i < c.number_of_factors; ++ i)
    {
        printf("%u^%u * ", c.factors[i].prime, c.factors[i].exponent);
    }

    free(c.factors);
    
    return 0;
}
