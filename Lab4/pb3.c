#include <stdio.h>
#include <ctype.h>

int countDigits;

float floatPart()
{
    int c;
    float powerTen = 10;
    int flagDot = 0;

    float number = 0;
    countDigits = 0;

    while((c = getchar()) != '\n')
    {
        if(c == '.')
        {
            flagDot = 1;
        }
        else
        {
            if(flagDot)
            {
                countDigits++;

                float digit = c - '0';

                number = number + (digit / powerTen);

                powerTen *= 10;
            }
        }
    }
    return number;
}

int main()
{
    float test = floatPart();

    char fmt[101];

    int cnt = countDigits;

    // printf("%d\n", cnt);
    
    sprintf(fmt,"%%.%df",cnt);
    //printf("%s\n", fmt);

    printf(fmt, test);

}
