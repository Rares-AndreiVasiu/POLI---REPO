#include <stdio.h>

double computeN(double n)
{
    double value = 1.0 / (n * n);

    return value; 
}

double geometricSeriesRightWise(double n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return computeN(n) + geometricSeriesRightWise(n - 1);
    }
}

double geometricSeriesLeftWise(double n, double index)
{
    if(index == n)
    {
        return computeN(index);
    }
    else
    {
        return computeN(index) + geometricSeriesLeftWise(n, index + 1);
    }
}

double gSeriesLeftWrapper(double n)
{
    return geometricSeriesLeftWise(n, 1);
}

int main()
{
    printf("%f\n", geometricSeriesRightWise(5));

    printf("%f\n", gSeriesLeftWrapper(5));
    return 0;
}
