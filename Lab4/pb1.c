#include <stdio.h>

void HexPrintA(unsigned n)
{
    printf("%X\n", n);
}

void HexPrintB()
{
    int c, num = 0;

    while((c = getchar()) != '\n')
    {
        num = num * 10 + (c - '0');
    }

    HexPrintA(num);
}

int main()
{
    HexPrintA(10);

    HexPrintB();
}
