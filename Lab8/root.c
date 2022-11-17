#include <stdio.h>
#include <math.h>
#include <limits.h>

// f(x) = x ^ 2 + 3x - 4
double f(double x)
{
    return (x * x + 3 * x - 4);
}

double rootOfFunction(double a, double b, double precision, int *err)
{
    *err=0;
    
    // printf("%lf %lf \n", a, b);

    if(fabs(b - a) <= precision)
    {
        return (a+b)/2;
    }
    else
    {
        double mid = (a + b) / 2;
        // printf("Signs are %lf and %lf\n", f(a)*f(mid), f(mid)*f(b));
        if(f(a) * f(mid) <= 0)
        {
            return rootOfFunction(a, mid, precision, err);
        }
        
        if(f(mid) * f(b) <= 0)
        {
            return rootOfFunction(mid, b, precision, err);
        }
        
    }
    
    *err=1;

    return -INT_MAX;
}
//expected roots are x1 = 1, x2 = -4

int main()
{
    double a = 0.5, b = 4.6, precision = 1e-6;
    
    int err_flag=0;
    
    //  printf("%f\n", rootOfFunction(a, b, precision));

    a = -10;
    b  = -5;
    
    printf("%f\n", rootOfFunction(a, b, precision, &err_flag));
    if (err_flag)
    {
        printf("something bad %d", err_flag);
    }

    a  = -5;
    b  = 1;
   
    //printf("%f\n", rootOfFunction(a, b, precision));

    return 0;
}
