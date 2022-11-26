#include <stdio.h>
#include <math.h>

double TripPrice(int n)
{
    double sum = 0, trip_price = 2.75f;

    if(n > 2)
    {
        sum = roundf(((double)(trip_price / 1.05f) * n) * 10) / 10;
    }
    else
    {
        sum = (double)n * trip_price;
    }

    printf("%.1f\n", n * trip_price - sum);

    return sum;
}

int main()
{
    double result = TripPrice(2);
    printf("%f\n\n", result);


    result = TripPrice(1);
    printf("%f\n\n", result);

    result = TripPrice(3);
    printf("%f\n", result);

    return 0;
}
