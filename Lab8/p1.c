#include <stdio.h>

unsigned mostSignificantDigit(unsigned n)
{
    if(n < 10)
    {
        return n;
    }
    else
    {
        return mostSignificantDigit(n / 10);
    }
}

int main()
{
    printf("%d\n", mostSignificantDigit(459));
    printf("%d\n", mostSignificantDigit(15229));
    printf("%d", mostSignificantDigit(40059));
}
