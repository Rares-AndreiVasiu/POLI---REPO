#include <stdio.h>
#include <math.h>

double myround(double x)
{
    if(x - floor(x) < 0.5f)
    {
        return floor(x);
    }
    else
    {
        return ceil(x);
    }
    
}

void validateResult(double x)
{
    double result = myround(x);

    if(result == round(x))
    {
        printf("Test for %f passed, the round is %f.\n", x, result);
    }
    else
    {
        printf("Test for %f failed, the result is %f.\n", x, result);
    }
}

int main()
{
    validateResult(1.2f);

    validateResult(2.7f);

    validateResult(10.5f);

    validateResult(-1.2f);

    validateResult(-1.6f);

    validateResult(-0.6f);

    validateResult(-0.3f);

    validateResult(0.6f);

    validateResult(0.3f);
}
